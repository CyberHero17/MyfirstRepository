import RPi.GPIO as GPIO
import time 
import math
import matplotlib.pyplot as plt
GPIO.setmode(GPIO.BCM)
dac = [8, 11, 7, 1, 0, 5, 12, 6]
leds = [2, 3, 4, 17, 27, 22, 10, 9]
GPIO.setup(leds, GPIO.OUT)
GPIO.setup(dac, GPIO.OUT)
GPIO.setup(14, GPIO.IN)
comp = 14
troyka = 13
GPIO.setup(troyka, GPIO.OUT, initial = GPIO.LOW) # Настраиваем тройку

y = [] # Данные
x = [] # Время 

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
        GPIO.output(leds, binary(mediana))
        pause = time.sleep(0.005)
        compval = GPIO.input(comp)
        if(compval == 1):
            right = mediana
        else:
            left = mediana  
    return left
try:
    
    GPIO.output(troyka, 1) # Как только подалинапряжение стали срауз считывать их значения через 0.1 секунды 
    start = time.time()
    u = 0

    while(1):
        u += 1
        print((adc() / 256) * 3.3) # Время зарядки
        y.append(adc())
        if(u == 150):

            break
    end = time.time()
    t = end - start
    print(t)
    delta_t = t / u
   
    for f in range(u):
        x.append(round(float(delta_t * f), 2))
    print(y)
    print(x)
    plt.xlabel("T, c")
    plt.ylabel("ADC")
    plt.plot(x, y)
                                          
    plt.show()
    with open("datafile.txt", "w", encoding='utf-8') as file:
        for e in range(len(y)):
            file.write(str(y[e]))
            file.write('\n')

    with open("units.txt", "w", encoding='utf-8') as p:
        p.write("Delta t = ", str(delta_t))
        p.write("\n")
        p.write("Step of U = ", str(3.3 / 256))

    
except KeyboardInterrupt():
    print("Прервано с клавиатуры")
finally:
    GPIO.cleanup(dac)
    

