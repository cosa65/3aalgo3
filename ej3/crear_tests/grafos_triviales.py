
import random
from sets import Set

f = open('tests_mejor_caso_triviales.in', 'w')
a = 50

#i = 0
while (a <= 1000):
  vertex = str(a) 
  edges = 0 
  colors = 1 
  line = vertex + ' ' + str(edges) + ' ' + str(colors) + '\n'
  f.write(line)
  l = ''
  for i in range(0, a):
    line = str(1) + ' ' + str(0) + '\n' 
    f.write(line)

  print "iteracion %d" % a
  a += 50
