make clean
make clear
make build
j=0
for ((i = 1; i <= 15; i++));
do
	./random 500 0 100 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done
for ((i = 1; i <= 15; i++));
do
	./random 500 0 90 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done
for ((i = 1; i <= 15; i++));
do
	./random 500 0 80 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

for ((i = 1; i <= 15; i++));
do
	./random 500 0 70 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

for ((i = 1; i <= 15; i++));
do
	./random 500 0 60 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

for ((i = 1; i <= 15; i++));
do
	./random 500 0 50 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

for ((i = 1; i <= 15; i++));
do
	./random 500 0 40 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

for ((i = 1; i <= 15; i++));
do
	./random 500 0 30 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

for ((i = 1; i <= 15; i++));
do
	./random 500 0 20 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

for ((i = 1; i <= 15; i++));
do
	./random 500 0 10 resultados/times.in
	./ej4Time resultados/times.in test.txt resultados/times.out vecinos i
	./ej4Time resultados/times.in test.txt resultados/times.out individual i
done

g++ miniscript.cpp -o mini
./resultados/mini 10
rm mini
