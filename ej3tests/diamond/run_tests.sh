rm -f src/*.o src/ej3_menor_color src/ej3_mayor_vertice
echo -e '\0033\0143'
g++ src/ej3_menor_color.cpp src/grafo_menor_color.cpp src/vertice_menor_color.cpp -std=c++11 -ggdb -o src/ej3_menor_color
g++ src/ej3_mayor_vertice.cpp src/grafo_mayor_vertice.cpp src/vertice_mayor_vertice.cpp -std=c++11 -ggdb -o src/ej3_mayor_vertice

mkdir diamantes_out_menor_color
mkdir diamantes_out_mayor_grado

for i in $(ls diamantes_in)
do
	echo "Midiendo conflictos para $i"
	src/ej3_menor_color diamantes_in/$i basura diamantes_out_menor_color/$i
done

for i in $(ls diamantes_in)
do
	echo "Midiendo conflictos para $i"
	src/ej3_mayor_vertice diamantes_in/$i basura diamantes_out_mayor_grado/$i
done

rm basura