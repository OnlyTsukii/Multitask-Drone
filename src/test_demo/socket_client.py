import asyncio
import websockets
import json


TYPE_START              = 0
TYPE_LAND               = 1
TYPE_NAVIGATION         = 2

TYPE_TAKEOFF            = 3
TYPE_ROTATE             = 4
TYPE_VERTICAL           = 5
TYPE_STAND              = 6
TYPE_HORIZONTAL         = 7

MISSION_NONE            = -1
MISSION_GLOBAL_CLEAN    = 0
MISSION_LOCAL_CLEAN     = 1

# 120.635400824016,31.31038774000782,0 
# 120.6356829326259,31.31038680258519,0 
# 120.6358377079404,31.31027238676101,0 

# 120.6353975762323,31.3103954421165,0 
# 120.6356110476122,31.31030895219921,0 
# 120.6358223180631,31.31032775443108,0 


data = [
    {'latitude': 31.3103954421165, 'longitude': 120.6353975762323, 'altitude': 10, 'type': 0, 'mission': -1, 'velocity': 1},
    {'latitude': 31.31030895219921, 'longitude': 120.6356110476122, 'altitude': 10, 'type': 2, 'mission': 0, 'velocity': 1},
    {'latitude': 31.31032775443108, 'longitude': 120.6358223180631, 'altitude': 10, 'type': 2, 'mission': -1, 'velocity': 1},
]

async def send_and_receive_data():
    uri = "ws://127.0.0.1:8765"  
    async with websockets.connect(uri) as websocket:
        await websocket.send(json.dumps(data))
        print(f"Sent data: {data}")

        response = await websocket.recv()
        print(f"Received response: {response}")

asyncio.run(send_and_receive_data())
