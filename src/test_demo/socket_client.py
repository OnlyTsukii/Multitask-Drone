import asyncio
import websockets
import json
import time


# TYPE_START              = 0   
# TYPE_LAND               = 1
TYPE_NAVIGATION         = 2

MISSION_NONE            = -1
MISSION_GLOBAL_CLEAN    = 0
MISSION_LOCAL_CLEAN     = 1
MISSION_LOCAL_CAPTURE   = 2
MISSION_LOCAL_TEST      = 3


# data = [
#     {'latitude': 31.3103954421165, 'longitude': 120.6353975762323, 'altitude': 15, 'type': 2, 'mission': 2, 'velocity': 1},
#     {'latitude': 31.31030895219921, 'longitude': 120.6356110476122, 'altitude': 15, 'type': 2, 'mission': 2, 'velocity': 1},
#     {'latitude': 31.31032775443108, 'longitude': 120.6358223180631, 'altitude': 15, 'type': 2, 'mission': 2, 'velocity': 1},
# ]

data = [
    # {'latitude': 31.31033444464784, 'longitude': 120.6354806816461, 'altitude': 10, 'type': 2, 'mission': 2, 'velocity': 1},
    {'latitude': 31.31028382509383, 'longitude': 120.6357004193035, 'altitude': 10, 'type': 2, 'mission': 3, 'velocity': 1},
]

async def send_and_receive_data():
    uri = "ws://127.0.0.1:8765"  
    async with websockets.connect(uri) as websocket:
        await websocket.send(json.dumps(data))
        print(f"Sent data: {data}")

        response = await websocket.recv()
        print(f"Received response: {response}")

time.sleep(300)
asyncio.run(send_and_receive_data())
