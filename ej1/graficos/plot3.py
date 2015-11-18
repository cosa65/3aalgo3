import numpy as np
import matplotlib.pyplot as plt

#numeros del eje x
x = [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500]

ypeor = [0.021669,0.106249,0.295593,0.644955,1.329194,2.223637,4.410146,7.755886,11.688811,16.223099,21.967535,13.269764,13.434027,18.233065,17.107331,27.300582,36.463518,44.178295,55.448431,58.935791,66.642262,76.055512,84.791721,101.668411,101.784670,151.608997,154.141541,149.610231,163.568473,175.855780]

#'ro' te dice que lo plotee con los numeritos que escribiste, como puntitos en el grafico
plt.plot(x,ypeor,'ro', color='black')

yfunction = []

x = [50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500]

for m in range(1,31):
		yfunction.append(m**1.63)


peor_caso = plt.plot(x,ypeor,'ro', color='blue', marker='o', label='Peor Caso')

#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x,yfunction, color='red', label='$T(n)=n^2$',linewidth=3)
plt.legend(numpoints=1,loc=2)

#nombre que va en el eje x
plt.xlabel("Nodos")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()