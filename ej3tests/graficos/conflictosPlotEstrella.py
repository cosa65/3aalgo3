import numpy as np
import matplotlib.pyplot as plt
import matplotlib.patches as mpatches

n_groups = 10


x = [1,1000,2000,3000,4000,5000,6000,7000,8000,9000,10000]

prom_colores = [1516,1364,1212,1059,906,755,609,456,302,167,0]
prom_grado = [1041,937,832,726,621,518,414,310,206,201,0]

prom_colores.reverse()
prom_grado.reverse()

plt.plot(x,prom_colores,'ro', color='blue')
plt.plot(x,prom_grado,'ro', color='green')

colPatch = mpatches.Patch(color='blue', label='colores')
gradoPatch = mpatches.Patch(color='green', label='grado')


plt.legend([colPatch,gradoPatch],['colores','grado'],bbox_to_anchor=(0.35, 1))
plt.xlabel('Cantidad de Nodos')
plt.ylabel('Conflictos')
plt.title('Cantidad de conflictos segun cantidad de nodos')

#plt.tight_layout()
plt.savefig("hechos/conf3Estrella.png")
plt.show()