import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

n_groups = 10


x = [1,100,200,300,400,500,600,700,800,900,1000]

prom_vecinos = [132,115,103,87,76,59,47,35,23,6,0]
prom_individual = [151,138,119,104,85,69,58,40,24,9,0]
prom_original = [164,150,135,116,100,81,68,48,33,16,0]

prom_vecinos.reverse()
prom_individual.reverse()
prom_original.reverse()

plt.plot(x,prom_vecinos,'ro', color='blue')
plt.plot(x,prom_original,'ro', color='black')
plt.plot(x,prom_individual,'ro', color='green')

interPatch = mpatches.Patch(color='blue', label='Vecinos')
indivPatch = mpatches.Patch(color='green', label='Individual')
origPatch = mpatches.Patch(color='black', label='Original')


plt.legend([interPatch,indivPatch,origPatch],['Vecinos','Individual','Original'],bbox_to_anchor=(0.35, 1))
plt.xlabel('Cantidad de Nodos')
plt.ylabel('Conflictos')
plt.title('Cantidad de conflictos segun cantidad de nodos')

#plt.tight_layout()
plt.show()