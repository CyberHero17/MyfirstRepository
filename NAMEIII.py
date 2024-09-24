import RPi.GPIO as GPIO

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

try:
    while 1:
        num = input()
        GPIO.output(dac, 0)
        num_int = int(num)
        res = binar(num_int)
        print(res)
        for i in range(len(res)):
            GPIO.output(dac[i], res[i])
        print('Предполагаемое напряжение: ', 0.013 * num_int)
        
except TypeError:
    print('Не тот тип')
except KeyboardInterrupt:
    print('Прервано с клавиатуры')
except IndexError:
    print('Выход за пределы массива')
except ZeroDivisionError:
    print("Вы не можете разделить на 0")
finally:
    for u in dac:
        GPIO.output(u, 0)
































# for elem in dac:
#     GPIO.setup(elem, GPIO.OUT)

# def double(n):
#                                  #(''.join(k for k in i))

# try:
#     times = 0
#     while(True):
#         num = input('Введите число от 0 до 255: ')
#         int_num = int(num)
#         times = int_num
#         for j in range(len(dac)):
#             s = double(int_num)
#             GPIO.output(dac[j], s[j])
#     print(0.013 * times)                #Напряжение
# finally:
#     for y in dac:
#         GPIO.output(y, 0)
