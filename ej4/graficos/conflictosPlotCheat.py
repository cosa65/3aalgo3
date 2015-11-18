import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

n_groups = 10


x = [1,100,200,300,400,500,600,700,800,900,1000]

prom_original = [666,596,532,475,402,337,258,192,140,70,0]
prom_vecinos = [505,450,401,361,303,255,194,145,108,56,0]
prom_individual = [653,580,516,456,391,324,252,185,135,68,0]

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