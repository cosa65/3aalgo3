import random

def exists_path(pisos, a):
  b = [0 for x in range(0, a+1)]

  for i in range(1, a+1):
    for j in range(0, i+1):
      if pisos[i][j] == 1:
        b[i] = 1

  return b[a] == 1


f = open('tests_caso_promedio.in', 'w')
a = 50
connections = set()
i = 0

while (a <= 1000 and i < 3):
  connec = ''
  floors = str(a) + '\n'
  for j in range(0, a):
    n = random.randint(0, a)
    n1 = random.randint(0, a)
    while n == n1:
      n1 = random.randint(0, a)

    b = (n,n1)
    c = (n1,n)
    if (n > n1):
      connections.update([c])
    elif(n1 > n):
      connections.update([b])

  pisos = [[0 for x in range(0,a+1)] for x in range(0, a+1)]

  
  b = sorted(connections)
  for edge in b:
    pisos[edge[0]][edge[1]] = 1
    pisos[edge[1]][edge[0]] = 1
    connec = connec + str(edge[0]) + ' ' + str(edge[1]) + ';' 

  if (exists_path(pisos, a)):
    print a
    i+=1
    connec = connec + '\n'
    f.write(floors)
    f.write(connec)
    if (i == 3):
      a += 50
      i = 0

