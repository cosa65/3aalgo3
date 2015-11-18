g++ -std=c++11 src/generar.cpp -o src/generar
mkdir tests_in

COUNTER=50
while [  $COUNTER -lt 3001 ]; do
	echo "Generando test para $COUNTER nodos"
	./src/generar $COUNTER tests_in/test$COUNTER
	let COUNTER=COUNTER+50
done