import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

n_groups = 10


x = [1,50,100,150,200,250,300,350,400,450,500]

prom_intercambio = [0,42,82,120,185,207,258,303,341,398,444]
prom_individual = [0,13,31,41,55,66,82,96,109,123,138]
prom_original = [0,44,90,144,198,229,292,328,380,438,485]


plt.plot(x,prom_intercambio,'ro', color='blue')
plt.plot(x,prom_original,'ro', color='black')
plt.plot(x,prom_individual,'ro', color='green')

interPatch = mpatches.Patch(color='blue', label='Intercambiar')
indivPatch = mpatches.Patch(color='green', label='Individual')
origPatch = mpatches.Patch(color='black', label='Original')


plt.legend([interPatch,indivPatch,origPatch],['Intercambiar','Individual','Original'],bbox_to_anchor=(0.35, 1))
plt.xlabel('Cantidad de Nodos')
plt.ylabel('Conflictos')
plt.title('Cantidad de conflictos segun cantidad de nodos')

#plt.tight_layout()
plt.show()