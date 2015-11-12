import random
from sets import Set

f = open('tests_peor_caso_ejes_menor_que_colores.in', 'w')
a = 50

#i = 0
while (a <= 1000): # and i < 3):
  vertex = str(a) 
  edges = (a*(a-1))/2
  colors = edges*a
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

  for j in range(0, a):
    for k in range (j+1, a):
      connections =  str(j) + ' ' + str(k) + '\n' 
      f.write(connections)

  print "iteracion %d" % a
  a += 50
