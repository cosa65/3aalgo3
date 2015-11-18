import numpy as np
import matplotlib.pyplot as plt


# y[0..1] = mejoresCasos e=3
# y[2..4] = CasosPromedios e=3
# y[4..5] = CasoPeor e=3

#x = [3, 3, 3, 3, 3, 3]
#numeros del eje x
# x = [100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000]
#y = [0.000002, 0.000007, 0.000028, 0.000029, 0.000029, 0.000049]

# valores primera funcion
# ymejor = [0.000002,0.000004,0.000006,0.000008,0.000010,0.000012,0.000014,0.000016,0.000018, 0.000021, 0.000022, 0.000024, 0.000026, 0.000028, 0.000030, 0.000032, 0.000033, 0.000035, 0.000037, 0.000039]
#[0.66029 ,0.71213,0.75875,1.370972 ]  

#valores segunda funcion
# yrandom = [0.000006,0.000013,0.000015,0.000014,0.000028,0.000035,0.000047,0.000036,0.000041,0.000036,0.000066,0.000038,0.000054,0.000084,0.000067,0.000093,0.000089,0.000103,0.000077,0.000087]

#
# ypeor = [0.000006,0.000013,0.000018,0.000018,0.000031,0.000038,0.000047,0.000038,0.000053,0.000048,0.000071,0.000052,0.000063,0.000091,0.000089,0.000102,0.000106,0.000115,0.000088,0.000094]

#'ro' te dice que lo plotee con los numeritos que escribiste, como puntitos en el grafico
# plt.plot(x,ymejor,'ro', color='green')
# plt.plot(x,ypeor,'ro', color='black')
# plt.plot(x,yrandom,'ro', color='blue')

yfunction = []

x = [0,100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000]

for m in range(0,21):
		yfunction.append(0.000007*m)


#sin 'ro' lo plotea como una funcion comun, continua
plt.plot(x,yfunction, color='red')


#nombre que va en el eje x
plt.xlabel("Ciudades")

#nombre que va en el eje y
plt.ylabel("Tiempo(segundos)")

#area = 34

plt.show()