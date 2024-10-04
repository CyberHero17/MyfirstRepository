import RPi.GPIO as GPIO
import time 
GPIO.setmode(GPIO.BCM)
dac = [8, 11, 7, 1, 0, 5, 12, 6]

for elem in dac:
    GPIO.setup(dac, GPIO.OUT, initial = GPIO.LOW)
GPIO.setup(14, GPIO.IN)
comp = 14
troyka = 13
GPIO.setup(troyka, GPIO.OUT, initial = GPIO.LOW)
GPIO.output(troyka, 1)
def binary(n):
    arr = [0, 0, 0, 0, 0, 0, 0, 0]
    i = 0
    while(n > 0):
        arr[i] = n % 2
        i += 1
        n //= 2
    return arr[::-1]

def adc():
    left = 0
    right = 255
    while(right - left > 1):
        mediana = (right + left) // 2
        
        GPIO.output(dac, binary(mediana))
        pause = time.sleep(0.1)
        compval = GPIO.input(comp)
        if(compval == 1):
            right = mediana
        else:
            left = mediana
        
    return left

try:
    print("left = 0, right = 255")
    while 1:
        
        print((adc() / 256) * 3.3)
        pause = time.sleep(1)

except KeyboardInterrupt:
    print("\nПрервано с клавиатуры")
finally:
    GPIO.cleanup(dac)
