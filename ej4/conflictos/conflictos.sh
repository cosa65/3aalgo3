make clean
make clear
make build

for ((i = 1; i <= 100; i++));
do
	./conflictos 500 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 450 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 400 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 350 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 300 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 250 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 200 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 150 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 100 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done

for ((i = 1; i <= 100; i++));
do
	./conflictos 50 resultados/confs.in
	./ej4Conf resultados/confs.in test.txt resultados/confs.out intercambiar
	./ej4Conf resultados/confs.in test.txt resultados/confs.out individual
done