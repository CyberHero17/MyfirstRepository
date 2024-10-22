import numpy as np 
import matplotlib.pyplot as plt
import pandas as pd 
import math
# data = pd.read_excel('approximation.xlsx').to_numpy()
# a = np.array(data[:, 0])
# T1 = np.array(data[:, 1]) 

# T = np.array(np.log(abs(T1 - math.pi)))
# a = np.array(np.log(a))


pdf = pd.read_csv('approximation.xlsx', delimiter=' ')
plt.figure(figsize=(16,12))
plt.plot(pdf['n'],abs(pdf['pi']-np.pi),c='r')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('Iterations (log)')
plt.ylabel('abs(PI-pi) (log)')
plt.show()

# def apx(a, T):

#  aT = np.mean(a * T)
#  a_sred = np.mean(a)
#  T_sred = np.mean(T)
#  a_sq_sred = np.mean(a * a)
#  T_sq_sred = np.mean(T * T)
#  k = (aT - a_sred * T_sred) / (a_sq_sred - a_sred ** 2)
#  b = T_sred - k * a_sred
#  #sigma_k = len(a)**(-0.5)*((T_sq_sred - T_sred ** 2) / (a_sq_sred - a_sred ** 2) - k ** 2)**(0.5)
#  #sigma_b = sigma_k * (a_sq_sred - a_sred**2)**0.5
#  return k, b#, sigma_b, sigma_k
# k, b = apx(a, T)
#k1, b1 = apx(a, T1)
# print("k = ",k)
# print("b = ",b)
# print("k1 = ",k)
# print("b1 = ",b)
# print(sigma_b)
# print(sigma_k)
# plt.xlim([0, np.max(a) + 100])
# plt.ylim([-80000, np.max(T) + 50000])

# plt.minorticks_on()

# plt.errorbar(a, T,
#              lw=0,
#              capsize=3,
#              capthick=1,
#              elinewidth=1.5,
#              marker='o',
#              ms=2, 
#              mew = 1.5,
#              color= "red")
# # plt.text(15000, 1.7, 'Bubble')
# # plt.text(14000, 0.4, 'Insert')
# # plt.text(20000, 0.063, 'Quick')

# plt.grid(visible= True, which= 'major', linestyle= '-', linewidth= 1, color = '0.7')														
# plt.grid(visible= True, which= 'minor', linestyle= '-', linewidth= 0.5, color= '0.8')

# # plt.plot(a, T, linewidth= 1.0, color= "red")
# # plt.plot(a, T1, linewidth = 1.0, color= "blue")
# plt.plot(a, T, linewidth= 1.0, color= "red")

# plt.show()








