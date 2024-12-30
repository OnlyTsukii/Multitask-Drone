import OPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(18, GPIO.OUT)

pwm3 = GPIO.PWM(chip=3,pin=0,frequency=66,duty_cycle_percent=100,invert_polarity=False)

try:
    # close
    pwm3.duty_cycle(89)
    print('success', end="")
except KeyboardInterrupt:
    pwm3.stop_pwm()
    pwm3.pwm_close()
    GPIO.cleanup()
    print('failed', end="")
