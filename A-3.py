import RPi.GPIO as GPIO
import time 
GPIO.setmode(GPIO.BCM)
GPIO.setup(6, GPIO.OUT)
T = 0.5
try:
	pwm = GPIO.PWM(6, T)
	pwm.start(25)
except KeyboardInterrupt:
	pwn.stop()
	print("ШИМ прервана с клавиатуры")
finally:
	GPIO.cleanup()

