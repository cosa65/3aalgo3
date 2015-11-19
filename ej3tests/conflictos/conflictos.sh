make clean
make clear
make ej3
j=0
for ((i = 1; i <= 100; i++));
do
	./conflictos 10000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 9000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 8000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 7000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 6000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 5000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 4000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 3000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 2000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 1000 resultados/confs.in $1 $i
	./ej3Conf resultados/confs.in test.txt resultados/confs.out 
	
done

g++ resultados/miniscript.cpp -o mini
./mini 10
