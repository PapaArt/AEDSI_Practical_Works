#All the graphs plotted it's on doc folder
import matplotlib.pyplot as plt
import numpy as np


x = np.linspace(-1.5,2,100)
y = (2*((x**3)/3)) + (x**2)
fig = plt.figure(figsize = (10, 6))

plt.xlabel("Variaveis")
plt.ylabel("Clausulas")
plt.title("Complexidade assintotica")
plt.grid()

plt.plot(x, y)
plt.show()