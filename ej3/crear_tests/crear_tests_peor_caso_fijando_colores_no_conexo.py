
import random
from sets import Set

f = open('tests_peor_caso_colores_no_conexo.in', 'w')
a = 50

#i = 0
while (a <= 1000): # and i < 3):
  vertex = str(a) 
  #edges = (a*(a-1))/2
  #edges = a-1
  edges = random.randint(0, a-1)
  colors = 100 
  line = vertex + ' ' + str(edges) + ' ' + str(colors) + '\n'
  f.write(line)
  for i in range(0, a):
    color = random.randint(1, colors)
    col = Set()
    
    for j in range(0, color):
      c = random.randint(0, color)
      col.add(c)

    l = ''
    for c in col:
      l = l + ' ' + str(c)

    l = l + '\n'

    line = str(len(col))
    line = line + l

    f.write(line)

  for i in range (0, edges):
    v1 = random.randint(0, edges)
    v2 = random.randint(0, edges)
    while (v1 == v2):
      v2 = random.randint(0, edges)

    connections =  str(v1) + ' ' + str(v2) + '\n' 
    f.write(connections)

  print "iteracion %d" % a
  a += 50
