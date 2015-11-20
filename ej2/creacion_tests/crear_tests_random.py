import random
from sets import Set

f = open('tests_random.in', 'w')
vertex = 3

#i = 0
while (vertex <= 116):
  edges_amount = ((vertex-1)*(vertex-2)/2) 
  colors = 10
  line = str(vertex) + ' ' + str(edges_amount) + ' ' + str(colors) + '\n'
  f.write(line)
  for i in range(0, vertex):
    line = str(7) + ' ' + str(0) + ' ' + str(1) + ' ' + str(2) + ' ' + str(3) + ' ' + str(4) + ' ' + str(5) + ' ' + str(6) + '\n' 
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

  print "iteracion %d" % vertex
  vertex += 1
