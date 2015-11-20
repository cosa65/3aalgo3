#!/usr/bin/env python
# -*- coding: utf-8 -*-

import numpy as np
import matplotlib.pyplot as plt
from math import log

#numeros del eje x
x = [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000]

# valores primera funcion
y_chico = []
y_mediano = []

y_arbol = []
y_arbol2 = []
          

#valores primer funcion
#f = open('../tests_tiempos/resultados_mejor_caso/res', 'r')
#for i in range(0,20):
#  y_chico.append(float(f.readline()[:-1]))
#
##valores segunda funcion
#f = open('../tests_tiempos/resultados_mejor_caso_sin_2lc/res', 'r')
#for i in range(0,20):
#  y_mediano.append(float(f.readline()[:-1]))

#valores primer funcion
f = open('../tiempo_mejor_caso_con2lc.in', 'r')
for i in range(0,20):
  y_chico.append(float(f.readline()[:-1]))

#valores segunda funcion
f = open('../tiempo_mejor_caso_sin2lc.in', 'r')
for i in range(0,20):
  y_mediano.append(float(f.readline()[:-1]))

#valores segunda funcion
f = open('../tiempos_arbol/arbol2_con2lc.in', 'r')
for i in range(0,20):
  y_arbol.append(float(f.readline()[:-1]))

#valores segunda funcion
f = open('../tiempos_arbol/arbol2_sin2lc.in', 'r')
for i in range(0,20):
  y_arbol2.append(float(f.readline()[:-1]))

#print len(y_chico)
#print len(y_mediano)
#print len(y_grande)
#print len(x)
plt.plot(x,y_chico,'ro', color='green', label= "Mejor caso 2-List coloring")
plt.plot(x,y_mediano,'ro', color='red', label= "Mejor caso sin 2-List coloring")
plt.plot(x,y_arbol,'ro', color='blue', label= "Arbol con 2-List coloring")
plt.plot(x,y_arbol2,'ro', color='yellow', label= "Arbol sin 2-List coloring")

yfunction = []
tfunction = []

a = 50
for m in range(0,20):
  if m == 0:
    yfunction.append(0)
  else:
    yfunction.append(0.00000173421*a*a)
    a += 50 

#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x,yfunction, color='purple', label='T(n)=n^2',linewidth=3)
plt.legend()

#nombre que va en el eje x
plt.xlabel(u"Tamaño de la entrada (cantidad de vértices)")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

plt.show()
