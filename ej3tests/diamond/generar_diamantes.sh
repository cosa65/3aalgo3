g++ -ggdb -std=c++11 src/generar.cpp -o src/generar
mkdir diamantes_in

# Los A tienen 2 colores, no random
COUNTER=10
while [  $COUNTER -lt 101 ]; do
	echo "Generando test para $COUNTER nodos no random"
	./src/generar diamantes_in/testA$COUNTER $COUNTER 2 0
	let COUNTER=COUNTER+10
done

# Los B tienen 2 colores, random
COUNTER=10
while [  $COUNTER -lt 101 ]; do
	echo "Generando test para $COUNTER nodos random"
	./src/generar diamantes_in/testB$COUNTER $COUNTER 2 1
	let COUNTER=COUNTER+10
done

# Los C tienen random colores, no random
COUNTER=4
j=3
while [ $COUNTER -lt 12 ]; do
	j=3
	while [ $j -lt $COUNTER ]; do
		echo "Generando test para $COUNTER nodos $j colores no random"
		./src/generar diamantes_in/testC$COUNTER-$j $COUNTER $j 0
		let j=j+1
	done
	let COUNTER=COUNTER+1
done

# Los D tienen random colores, random
COUNTER=4
j=3
while [ $COUNTER -lt 12 ]; do
	j=3
	while [ $j -lt $COUNTER ]; do
		echo "Generando test para $COUNTER nodos $j colores random"
		./src/generar diamantes_in/testD$COUNTER-$j $COUNTER $j 1
		let j=j+1
	done
	let COUNTER=COUNTER+1
done
