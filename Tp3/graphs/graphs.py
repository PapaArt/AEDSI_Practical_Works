from mpl_toolkits.axisartist.parasite_axes import HostAxes, ParasiteAxes
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure(figsize=(800,600))

# Criacao dos eixos
x1 = [1000, 5000, 10000, 50000, 100000, 500000, 1000000]
y1 = [2714684, 12497500, 4999500, 124997500, 4999950000, 124999750000, 124999750000]
y2 = [2465342, 6200330, 24718101, 617972477, 2477176147, 124999750000, 124999750000]
y3 = [18686, 116975, 253927, 1801349, 3201722, 61887393004, 12365468987]
y4 = [13910, 97177, 216520, 1200341, 2592634, 15155126, 31841123]
y5 = [496376, 223715, 482855, 2824966, 6103280, 32175376, 71842568]
y6 = [18686, 116975, 253927, 1801349, 3201722, 18288537, 42230132]
y7 = [3007, 20624, 30009, 166033, 300010, 1500008, 3000010]


plt.plot(x1, y1, label='Bubble')
plt.plot(x1, y2, label='Selection')
plt.plot(x1, y3, label='Insertion')
plt.plot(x1, y4, label='Shell')
plt.plot(x1, y5, label='Quick')
plt.plot(x1, y6, label='Merge')
plt.plot(x1, y7, label='Radix')


plt.xlabel('Tamanho das entradas')
plt.ylabel('Media das comparacoes')
plt.title("Comparacoes -> Cenario 1")
plt.grid()


plt.plot(y1, 'b', color='r', linewidth='1')
plt.plot(y2, 'b', color='b', linewidth='1')
plt.plot(y3, 'b', color='g', linewidth='1')
plt.plot(y4, 'b', color='m', linewidth='1')
plt.plot(y5, 'b', color='y', linewidth='1')
plt.plot(y6, 'b', color='c', linewidth='1')
plt.plot(y7, 'b', color='k', linewidth='1')


plt.ylim([3007, 50000000])
plt.xlim([1000, 10000000])
plt.legend()
plt.show()