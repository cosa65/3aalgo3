#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv){
	int N,M,C;
	N = atoi(argv[1]);				//Cantidad de nodos del grafo a generar
	M = atoi(argv[2]);
	C = atoi(argv[3]);
	std::string filename(argv[4]);


	std::ofstream file(filename.c_str());

	file << N << " ";
	long posM = file.tellp(); //Defino cantidad de aristas al final de todo
	file << std::endl;

	if(M == 0) {
		int colsTot;
		long posIn,posFin;
		for(int i=0; i<=N; i++){
			colsTot = 0;
			posIn = file.tellp();
			file << "  ";
			for(int j=0; j<C; j++){
				if(rand()%2	== 1) {
					file << j << " ";
					colsTot++;
				}	
			}
			if(colsTot==0) {
				file << rand()%C;
				colsTot++;
			}
			posFin = file.tellp();

			file.seekp(posIn);
			file << colsTot;
			file.seekp(posFin);
			file << std::endl;
		}

		for(int i=0; i<N; i++){
			for(int j=i; j<N; j++){
				if(rand()%2 == 1 && j!=i) {
					file << i << " " << j << std::endl;
					M++;
				}
			}
		}
		
		file.seekp(posM);
		file << M << " " << C;

		file.close();
	} else {
		//Aca iria el caso en el que quiera tener predefinida la cantidad de aristas
	}

	return 0;
}