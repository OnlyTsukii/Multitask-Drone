import subprocess

from drone_controller.config import SYSTEM_PASSWORD

class PayloadController():
    def __init__(self):
        self.enable_cmd = f"echo {SYSTEM_PASSWORD} | sudo python ~/Multitask-Drone/src/scripts/enable_payload.py"
        self.disable_cmd = f"echo {SYSTEM_PASSWORD} | sudo python ~/Multitask-Drone/src/scripts/disable_payload.py"
    
    def enable_payload(self) -> bool:
        try:
            result = subprocess.run(self.enable_cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            return result == 'success'
        except subprocess.CalledProcessError as e:
            return False
    
    def disable_payload(self) -> bool:
        try:
            result = subprocess.run(self.disable_cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            return result == 'success'
        except subprocess.CalledProcessError as e:
           return False
