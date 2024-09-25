import RPi.GPIO as GPIO
import time
dac = [8, 11, 7, 1, 0, 5, 12, 6]
GPIO.setmode(GPIO.BCM)
for elem in dac:
    GPIO.setup(elem, GPIO.OUT)

def binar(n):
    ar = [0, 0, 0, 0, 0, 0, 0, 0]
    for i in range(len(ar)):
        ar[i] += n % 2
        n //= 2
        if (n == 0):
            break
    return ar[::-1]

# try:
#     while 1:
#         num = input()
#         GPIO.output(dac, 0)
#         num_int = int(num)
#         res = binar(num_int)
#         print(res)
#         for i in range(len(res)):
#             GPIO.output(dac[i], res[i])
#         print('Предполагаемое напряжение: ', 0.013 * num_int)
        
# except TypeError:
#     print('Не тот тип')
# except KeyboardInterrupt:
#     print('Прервано с клавиатуры')
# except IndexError:
#     print('Выход за пределы массива')
# except ZeroDivisionError:
#     print("Вы не можете разделить на 0")
# finally:
#     for u in dac:
#         GPIO.output(u, 0)
try:
	while 1:
		for i in range(0, 128, 1):
			binary = binar(i)
			for j in range(len(binary)):
				GPIO.output(dec[j], binary[j])
				pause = time.sleep(0.2)
			print(i)

		for i in range(128, 0, -1):
			binary = binar(i)
			for j in range(len(binary)):
				GPIO.output(dec[j], binary[j])
				pause = time.sleep(0.2)
			print(i)
		for i in range(128, 1, -1):
			binary = binar(i)
			for j in range(len(binary)):
				GPIO.output(dec[j], binary[j])
				pause = time.sleep(0.2)
			print(i)
		for i in range(0, 128, -1):
			binary = binar(i)
			for j in range(len(binary)):
				GPIO.output(dec[j], binary[j])
				pause = time.sleep(0.2)
			print(i)
finally:
	for y in dac:
		GPIO.output(y, 0)














