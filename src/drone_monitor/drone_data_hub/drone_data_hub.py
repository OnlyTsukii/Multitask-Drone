import rclpy
import threading
from time import sleep
from rclpy.node import Node
from mavros_msgs.msg import State
from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import PoseStamped
from rclpy.qos import QoSProfile, ReliabilityPolicy, HistoryPolicy
from std_msgs.msg import Float64
from drone_interfaces.msg import PanelBox, Yaw, UavData


class UavDataHub(Node):
    def __init__(self):
        super().__init__("uav_data_hub")
        qos_profile = QoSProfile(
            reliability=ReliabilityPolicy.BEST_EFFORT,
            history=HistoryPolicy.KEEP_LAST,
            depth=10,
        )
        self.data_publisher = self.create_publisher(UavData, "/uav/uav_data", 10)

        self.state_sub = self.create_subscription(
            State, "/mavros/state", self.state_callback, qos_profile
        )

        self.gps_sub = self.create_subscription(
            NavSatFix, "/mavros/global_position/global", self.gps_callback, qos_profile
        )

        self.panel_sub = self.create_subscription(
            PanelBox, "/drone/panel_box", self.panel_callback, qos_profile
        )

        self.panel_yaw_sub = self.create_subscription(
            Yaw, "/drone/panel_yaw", self.panel_yaw_callback, qos_profile
        )

        self.yaw_sub = self.create_subscription(
            Float64,
            "/mavros/global_position/compass_hdg",
            self.yaw_callback,
            qos_profile,
        )

        self.rel_alt_sub = self.create_subscription(
            Float64,
            "/mavros/global_position/rel_alt",
            self.rel_alt_callback,
            qos_profile,
        )

        self.local_pos_sub = self.create_subscription(
            PoseStamped,
            "/mavros/local_position/pose",
            self.local_pos_callback,
            qos_profile,
        )
        self.state = None
        self.gps_fix = None
        self.yaw = 0.0
        self.rel_alt = 0.0
        self.local_pose = None
        self.panel_yaw = 0.0
        self.panel_detected = False
        self.panel_loss = 0
        self.panel_found = 0
        self.panel_pos = None

        self.create_timer(0.2, self.publish_data)

    def state_callback(self, msg: State):
        self.state = msg

    def gps_callback(self, msg):
        self.gps_fix = msg

    def yaw_callback(self, msg: Float64):
        self.yaw = msg.data

    def rel_alt_callback(self, msg: Float64):
        self.rel_alt = msg.data

    def local_pos_callback(self, msg: PoseStamped):
        self.local_pose = msg

    def panel_callback(self, msg: PanelBox):
        if msg.x == 0 and msg.y == 0 and msg.w == 0 and msg.h == 0:
            if not self.panel_detected:
                self.panel_pos = None
            self.panel_loss += 1
            self.panel_found = 0
            if self.panel_loss == 30:
                self.panel_detected = False
                self.panel_loss = 0
                self.panel_pos = None
        else:
            if self.panel_detected:
                self.panel_pos = msg
            self.panel_found += 1
            self.panel_loss = 0
            if self.panel_found == 5:
                self.panel_found = 0
                self.panel_detected = True
                self.panel_pos = msg

    def panel_yaw_callback(self, msg: Yaw):
        self.panel_yaw = msg.yaw

    def publish_data(self):
        if self.state is None or self.gps_fix is None:
            return

        msg = UavData()
        msg.state = self.state
        msg.gps_fix = self.gps_fix
        msg.yaw = self.yaw
        msg.rel_alt = self.rel_alt
        msg.local_pose = self.local_pose if self.local_pose else PoseStamped()
        msg.panel_pos = self.panel_pos if self.panel_pos else PanelBox()
        msg.panel_detected = self.panel_detected
        msg.panel_yaw = self.panel_yaw

        self.data_publisher.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    uav_data_hub = UavDataHub()
    try:
        rclpy.spin(uav_data_hub)
    except KeyboardInterrupt:
        pass
    finally:
        uav_data_hub.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
