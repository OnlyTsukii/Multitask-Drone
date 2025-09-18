import asyncio
import websockets
import json
import time


# TYPE_START              = 0   
# TYPE_LAND               = 1
TYPE_NAVIGATION         = 2
TYPE_STAND              =6
MISSION_NONE            = -1
MISSION_GLOBAL_CLEAN    = 0
MISSION_LOCAL_CLEAN     = 1
MISSION_LOCAL_CAPTURE   = 2
# test
MISSION_LOCAL_TEST      = 3


data = [
    # {'latitude': 31.31036948702145, 'longitude': 120.63545148225, 'altitude': 5, 'type': 2, 'mission': 2, 'velocity': 1},
    {'latitude': 47.3979703, 'longitude': 8.5465649, 'altitude': 2, 'type': 2, 'mission': -1, 'velocity': 2},
    {'latitude': 47.3977703, 'longitude': 8.5465649, 'altitude': 2, 'type': 2, 'mission': -1, 'velocity': 2},
    {'latitude': 47.3974703, 'longitude': 8.5465642, 'altitude': 2, 'type': 6, 'mission': -1, 'velocity': 2},
    {'latitude': 47.3978703, 'longitude': 8.5466642, 'altitude': 2, 'type': 2, 'mission': -1, 'velocity': 2},
    {'latitude': 47.3979703, 'longitude': 8.5465649, 'altitude': 2, 'type': 2, 'mission': -1, 'velocity': 2},
]

async def send_and_receive_data():
    uri = "ws://127.0.0.1:8765"  
    async with websockets.connect(uri) as websocket:
        await websocket.send(json.dumps(data))
        print(f"Sent data: {data}")

        response = await websocket.recv()
        print(f"Received response: {response}")

asyncio.run(send_and_receive_data())
