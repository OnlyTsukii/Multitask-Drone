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
    {'latitude': 23.0417418, 'longitude': 113.3947909, 'altitude': 2, 'type': 2, 'mission': -1, 'velocity': 2},
    {'latitude': 23.0415418, 'longitude': 113.3946909, 'altitude': 2, 'type': 6, 'mission': -1, 'velocity': 2},
    {'latitude': 23.0417418, 'longitude': 113.3947909, 'altitude': 2, 'type': 2, 'mission': -1, 'velocity': 2},
]

async def send_and_receive_data():
    uri = "ws://127.0.0.1:8765"  
    async with websockets.connect(uri) as websocket:
        await websocket.send(json.dumps(data))
        print(f"Sent data: {data}")

        response = await websocket.recv()
        print(f"Received response: {response}")

asyncio.run(send_and_receive_data())
