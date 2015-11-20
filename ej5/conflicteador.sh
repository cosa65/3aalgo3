make clean
make clear
make ej5

for ((i = 1; i <= 11; i++));
do
	./conflictos 1000 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 900 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 800 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 700 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 600 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 500 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done	

for ((i = 1; i <= 11; i++));
do
	./conflictos 400 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 300 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 200 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

for ((i = 1; i <= 11; i++));
do
	./conflictos 100 resultados/test.in $i $1
	./ej5 resultados/test.in test.txt resultados/test.out ambos $i
done

make prom
make clean