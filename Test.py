# import numpy as np
# import pandas as pd
# import matplotlib.pyplot as plt
# from scipy.optimize import curve_fit
# excel_data = pd.read_excel('MyData.xlsx').to_numpy()

# new_data = excel_data[::]

# t = new_data[:, 0]
# f = new_data[:, 1]

# log_f = np.log(f)

# plt.plot(t,log_f, 'o')

# def lin(t, log_f):
# 	t_log_f_sred = np.mean(t * log_f)
# 	t_sred = np.mean(t)
# 	log_f_sred = np.mean(log_f)
# 	t_sq_sred = np.mean(t ** 2)

# 	k = (t_log_f_sred - t_sred * log_f_sred) / (t_sq_sred - t_sred ** 2)
# 	b = log_f_sred - k * t_sred
# 	return k, b
# k, b = lin(t, log_f) # CHECK IT 
# plt.plot(t, k * t + b)
# plt.show()

