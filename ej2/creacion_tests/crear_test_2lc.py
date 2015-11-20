import random
from sets import Set

f = open('tests_sin_2lc.in', 'w')
vertex = 14
edges_amount = ((vertex-1)*(vertex-2)/2) 
colors = 2

#i = 0
while (colors <= 13):
  line = str(vertex) + ' ' + str(edges_amount) + ' ' + str(colors) + '\n'
  f.write(line)
  for i in range(0, vertex):
    l = ''
    for j in range(0, colors):
      l = l + ' ' + str(j)

    l = l + '\n'

    line = str(colors)
    line = line + l

    f.write(line)

  edges = set()
  while (len(edges) != edges_amount):
    v1 = random.randint(0, vertex-1)
    v2 = random.randint(0, vertex-1)
    while (v1 == v2):
      v2 = random.randint(0, vertex-1)

    edge = frozenset([v1,v2])
    edges.add(edge)

  for edge in edges:
    a = set()
    for e in edge:
      a.add(e)
          
    v1 = a.pop()
    v2 = a.pop()
    connections =  str(v1) + ' ' + str(v2) + '\n' 
    f.write(connections)

  print "iteracion %d" % colors
  colors += 1
