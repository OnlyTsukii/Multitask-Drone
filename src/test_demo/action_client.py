import rclpy
from rclpy.node import Node
from action_tutorials_interfaces.action import Fibonacci
from rclpy.action import ActionClient

class FibonacciActionClient(Node):
    def __init__(self):
        super().__init__('fibonacci_action_client')
        self._action_client = ActionClient(self, Fibonacci, 'fibonacci')

    def send_goal(self, order):
        goal_msg = Fibonacci.Goal()
        goal_msg.order = order

        self._action_client.wait_for_server()
        self._send_goal_future = self._action_client.send_goal_async(
            goal_msg,
            feedback_callback=self.feedback_callback
        )
        self._send_goal_future.add_done_callback(self.goal_response_callback)

    def goal_response_callback(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().info('Goal rejected')
            return

        self.get_logger().info('Goal accepted')
        self._goal_handle = goal_handle
        self._get_result_future = goal_handle.get_result_async()
        self._get_result_future.add_done_callback(self.get_result_callback)

    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f'Received feedback: {feedback_msg.feedback.partial_sequence}')

    def get_result_callback(self, future):
        result = future.result().result
        self.get_logger().info(f'Result: {result.sequence}')
        self.send_goal(10)

    def cancel_goal(self):
        if self._goal_handle:
            cancel_future = self._goal_handle.cancel_goal_async()
            cancel_future.add_done_callback(self.cancel_done_callback)

    def cancel_done_callback(self, future):
        cancel_response = future.result()
        if cancel_response.goals_cancel_response.return_code == 1: 
            self.get_logger().info('Goal canceled successfully')
        else:
            self.get_logger().info('Goal cancelation failed')


def main(args=None):
    rclpy.init(args=args)
    fibonacci_action_client = FibonacciActionClient()

    order = 10 
    fibonacci_action_client.send_goal(order)

    try:
        rclpy.spin(fibonacci_action_client)
    except KeyboardInterrupt:
        fibonacci_action_client.cancel_goal()
        fibonacci_action_client.get_logger().info('Goal cancel requested')

    fibonacci_action_client.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
