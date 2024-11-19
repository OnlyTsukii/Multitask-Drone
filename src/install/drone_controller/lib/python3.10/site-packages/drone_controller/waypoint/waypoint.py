
from geometry_msgs.msg import Vector3, Point

TYPE_TAKEOFF            = 0
TYPE_LAND               = 1
TYPE_NAVIGATION         = 2
TYPE_ROTATE             = 3
TYPE_VERTICAL_MOVE      = 4
TYPE_STAND              = 5
TYPE_HORIZONTAL_MOVE    = 6
TYPE_BODY_MOVE          = 7

MISSION_NONE            = -1
MISSION_CLOBAL_CLEAN    = 0
MISSION_LOCAL_CLEAN     = 1

FRAME_GLOBAL_INT            = 5
FRAME_GLOBAL_REL_ALT        = 6
FRAME_GLOBAL_TERRAIN_ALT    = 11
FRAME_LOCAL_NED         = 1   
FRAME_LOCAL_OFFSET_NED  = 7
FRAME_BODY_NED          = 8     # Forward, Left and Up
FRAME_BODY_OFFSET_NED   = 9

IGNORE_LATITUDE = 1	
IGNORE_LONGITUDE = 2
IGNORE_ALTITUDE = 4
IGNORE_VX = 8	
IGNORE_VY = 16
IGNORE_VZ = 32
IGNORE_AFX = 64	
IGNORE_AFY = 128
IGNORE_AFZ = 256
FORCE = 512	
IGNORE_YAW = 1024
IGNORE_YAW_RATE = 2048


class Waypoint():
    def __init__(self, id, type, mission, vel_x, vel_y, vel_z, yaw, yaw_rate):
        self.id = id
        self.type = type
        self.mission = mission

        vel = Vector3()
        vel.x = float(vel_x)
        vel.y = float(vel_y)
        vel.z = float(vel_z)
        self.velocity = vel

        self.yaw = yaw
        self.yaw_rate = yaw_rate


class GlobalWaypoint(Waypoint):
    def __init__(self, id, type, mission, vel_x, vel_y, vel_z, pos_x, pos_y, pos_z, yaw=float('nan'), yaw_rate=0.0):
        super.__init__(id, type, mission, vel_x, vel_y, vel_z, yaw, yaw_rate)

        self.frame = FRAME_GLOBAL_INT

        self.latitude = float(pos_x)
        self.longitude = float(pos_y)
        self.altitude = float(pos_z)


class LocalWaypoint(Waypoint):
    def __init__(self, id, type, mission, vel_x, vel_y, vel_z, pos_x, pos_y, pos_z, yaw=float('nan'), yaw_rate=0.0):
        super.__init__(id, type, mission, vel_x, vel_y, vel_z, yaw, yaw_rate)

        self.frame = FRAME_BODY_NED

        pos = Point()
        pos.x = float(pos_x)
        pos.y = float(pos_y)
        pos.z = float(pos_z)
        self.position = pos