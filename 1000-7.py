import matplotlib.pyplot as plt
import numpy as np 
import math
mas = []
ok = []
with open('data.txt', 'r') as data:
	for line in data:
		mas.append(int(line))
data.close()
with open('settings.txt', 'r') as settings:
	for l in settings:
		ok.append(l)
settings.close()
t = float(ok[0])
u = float(ok[1])

T = [t * i for i in range(len(mas))]
U = [u * j for j in mas]
ind = 0
tmp = 0
for d in range(len(U)):
	if(U[d] >= tmp):
		ind = d
		tmp = U[d]
plt.title("Процесс заряда и разряда в RC-цепочке")
plt.text(6, 2.25, f'Время разряда = {T[ind]}')
plt.text(6, 1.75, f'Время разряда = {T[len(U) - 1] - T[ind]}')

T = np.array(T)
U = np.array(U)

T_new = np.array(T[::20])
U_new = np.array(U[::20])

plt.yticks(np.arange(0.0, 4.0, 0.5))
plt.xticks(np.arange(0.0, 13.0, 1.0))
plt.xlabel('Время, с')
plt.ylabel('Напряжение, В')

plt.minorticks_on()
plt.grid(visible= True, which= 'major', linestyle= '-', linewidth= 1, color = '0.7')														
plt.grid(visible= True, which= 'minor', linestyle= '-', linewidth= 0.5, color= '0.9')
graf = plt.plot(T, U, color= 'blue')
plt.legend(graf, ['V(t)'])
plt.errorbar(T_new, U_new,
             
             capsize=3,
             capthick=3.0,
             elinewidth=5.0,
             marker='o',
             color= "blue")
plt.show()


