g++ -std=c++11 -ggdb src/ej1Timed.cpp src/grafo/digrafo.cpp src/grafo/grafo.cpp src/grafo/vertice_digrafo.cpp src/grafo/vertice.cpp -o src/ej1Timed 
# g++ -std=c++11 src/ej1Timed.cpp -o src/ej1Timed
mkdir tests_out

for i in $(ls tests_in)
do
	echo "Midiendo tiempos para $i"
	./src/ej1Timed tests_in/$i parametro_basura tests_out/$i
done