import numpy as np
import matplotlib.pyplot as plt
from math import log

#numeros del eje x
x = [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000]

# valores primera funcion
y_chico = []
y_mediano = []
y_grande = []
          

#valores primer funcion
f = open('../tiempos/tiempos_col/tiempo_col_random1.txt', 'r')
for i in range(0,20):
  y_chico.append(float(f.readline()[:-1]))

#valores segunda funcion
f = open('../tiempos/tiempos_col/tiempo_col_random2.txt', 'r')
for i in range(0,20):
  y_mediano.append(float(f.readline()[:-1]))

#valores tercer funcion
f = open('../tiempos/tiempos_col/tiempo_col_completo.txt', 'r')
for i in range(0,20):
  y_grande.append(float(f.readline()[:-1]))

#print len(y_chico)
#print len(y_mediano)
#print len(y_grande)
#print len(x)
plt.plot(x,y_chico,'ro', color='green', label= "grafo random")
plt.plot(x,y_mediano,'ro', color='red', label= "grafo random")
plt.plot(x,y_grande,'ro', color='blue', label= "grafo completo")

yfunction = []
tfunction = []

a = 50
for m in range(0,20):
  if m == 0:
    yfunction.append(0)
  else:
    yfunction.append(0.00000673421*a*a)
    a += 50 

#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x,yfunction, color='purple', label='T(n)=k*(|V|log(|V|))',linewidth=3)
plt.legend()

#nombre que va en el eje x
plt.xlabel("Tamano de la entrada (cantidad de vertices)")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

plt.show()
