
TYPE_START              = 0
TYPE_LAND               = 1
TYPE_NAVIGATION         = 2

TYPE_TAKEOFF            = 3
TYPE_ROTATE             = 4
TYPE_VERTICAL           = 5
TYPE_STAND              = 6
TYPE_HORIZONTAL         = 7

BODY_CLIMB              = 0
BODY_DOWN               = 1
BODY_FORWARD            = 2
BODY_BACKWARD           = 3
BODY_LEFT               = 4
BODY_RIGHT              = 5
BODY_ROTATE_CLOCKWISE   = 6
BODY_ROTATE_COUNTERCW   = 7 
BODY_HOLD               = 8

APPROACH_PAENL_EDGE_TOP = 9 
APPROACH_PAENL_EDGE_BOT = 10 
APPROACH_HORIZONTAL_FB  = 11
APPROACH_HORIZONTAL_LR  = 12
APPROACH_VERTICAL       = 13
APPROACH_YAW            = 14

MISSION_NONE            = -1
MISSION_GLOBAL_CLEAN    = 0
MISSION_LOCAL_CLEAN     = 1

FRAME_GLOBAL_INT            = 5
FRAME_GLOBAL_REL_ALT        = 6
FRAME_GLOBAL_TERRAIN_ALT    = 11
FRAME_LOCAL_NED             = 1   
FRAME_LOCAL_OFFSET_NED      = 7
FRAME_BODY_NED              = 8     # Forward, Left and Up
FRAME_BODY_OFFSET_NED       = 9

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
