make clean
make clear
make build
j=0
for ((i = 1; i <= 20; i++));
do
	./random 1000 0 30 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done
for ((i = 1; i <= 20; i++));
do
	./random 900 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 800 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 700 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 600 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 200 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 400 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 300 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 200 0 30 resultados/times.in 
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

for ((i = 1; i <= 20; i++));
do
	./random 100 0 30 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos
	./ej4Time resultados/times.in test.txt resultados/times.out individual
done

g++ miniscript.cpp -o mini
./resultados/mini 10
rm mini
