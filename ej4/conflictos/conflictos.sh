make clean
make clear
make build
j=0
for ((i = 1; i <= 100; i++));
do
	./conflictos 1000 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done
for ((i = 1; i <= 100; i++));
do
	./conflictos 900 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 800 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 700 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 600 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 500 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 400 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 300 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 200 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 100 resultados/confs.in $1
	./ej4Conf resultados/confs.in test.txt resultados/confs.out vecinos $i
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual $i
done

g++ resultados/miniscript.cpp -o mini
./mini 10
