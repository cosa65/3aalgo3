import random
from sets import Set

f = open('tests_peor_caso_colores_arbol.in', 'w')
vertex = 3 

#i = 0
while (vertex <= 11):
  edges = ((vertex-1)*(vertex-2)/2) 
  colors = 5
  line = str(vertex) + ' ' + str(edges) + ' ' + str(colors) + '\n'
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

  edges = set()
  while ()
    v1 = random.randint(0, edges)
    v2 = random.randint(0, edges)
    edges.add(v1,v2)

  for edge in edges:
    connections =  str(edge[0]) + ' ' + str(edge[1]) + '\n' 
    f.write(connections)

  print "iteracion %d" % vertex
  vertex += 1
