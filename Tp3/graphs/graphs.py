from mpl_toolkits.axisartist.parasite_axes import HostAxes, ParasiteAxes
import matplotlib.pyplot as plt
import numpy as np

fig = plt.figure()
ax = fig

x1 = ['BubbleSort', 'SelectionSort', 'InsertionSort', 'ShellSort', 'QuickSort', 'MergeSort', 'RadixSort']
# Criacao dos eixos
y1 = [2714684, 12497500, 4999500, 124997500, 4999950000, 124999750000]
y2 = [2465342, 6200330, 24718101, 617972477, 2477176147]
y3 = [18686, 116975, 253927, 1801349, 3201722]
y4 = [13910, 97177, 216520, 1200341, 2592634, 15155126, 31841123]
y5 = [496376, 223715, 482855, 2824966, 6103280, 32175376, 71842568]
y6 = [18686, 116975, 253927, 1801349, 3201722, 18288537, 42230132]
y7 = [3007, 20624, 30009, 166033, 300010, 1500008, 3000010]

plt.plot(x1, y1, )
plt.plot(x1, y2, )
plt.plot(x1, y3, )
plt.plot(x1, y4, )
plt.plot(x1, y5, )
plt.plot(x1, y6, )
plt.plot(x1, y7, )

plt.xlabel('Metodos de ordenação')
plt.ylabel('Media das comparacoes')
plt.title("Comparacoes -> Cenario 1")
plt.grid()

plt.plot(y1, 'b', color='tab:red', linewidth='6')
plt.plot(y2, 'b', color='tab:purple', linewidth='6')
plt.plot(y3, 'b', color='tab:green', linewidth='6')
plt.plot(y4, 'b', color='tab:pink', linewidth='6')
plt.plot(y5, 'b', color='tab:blue', linewidth='6')
plt.plot(y6, 'b', color='tab:brown', linewidth='6')
plt.plot(y7, 'b', color='tab:orange', linewidth='6')

plt.legend()
plt.show()