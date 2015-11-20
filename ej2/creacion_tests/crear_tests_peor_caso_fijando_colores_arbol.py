
import random
from sets import Set

f = open('tests_peor_caso_colores_arbol2.in', 'w')
a = 50

#i = 0
while (a <= 1000): # and i < 3):
  vertex = str(a) 
  #edges = (a*(a-1))/2
  edges = a-1
  #edges = random.randint(0, a-1)
  colors = vertex 
  line = vertex + ' ' + str(edges) + ' ' + str(colors) + '\n'
  f.write(line)
  for i in range(0, a):
    l = ''
    for j in range(0, a):
      l = l + ' ' + str(j)

    l = l + '\n'

    line = colors
    line = line + l

    f.write(line)

  for i in range(0,a-1):
    connections =  str(i) + ' ' + str(i+1) + '\n' 
    f.write(connections)

  print "iteracion %d" % a
  a += 50
