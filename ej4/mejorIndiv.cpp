#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv){
	int N,M,C;
	N = atoi(argv[1]);				//Cantidad de nodos del grafo a generar
	C = atoi(argv[2]);
	std::string filename(argv[3]);


	std::ofstream file(filename.c_str());

	file << N << " ";
	long posM = file.tellp(); //Defino cantidad de aristas al final de todo
	file << " ";
	file << C << std::endl;

	if(M == 0) {
		int colsTot;
		long posIn,posFin;
		for(int i=0; i<N; i++){
			colsTot = 0;
			posIn = file.tellp();
			file << "  ";
			for(int j=0; j<C; j++){
				if(rand()%2	== 1) {
					file << j << " ";
					colsTot++;
				}	
			}
			posFin = file.tellp();

			file.seekp(posIn);
			file << colsTot;
			file.seekp(posFin);
			file << std::endl;
		}

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				if(rand()%2 == 1) {
					file << i << " " << j << std::endl;
					M++;
				}
			}
		}
		
		file.seekp(posM);
		file << M;

		file.close();
	} else {
		//Aca iria el caso en el que quiera tener predefinida la cantidad de aristas
	}

	return 0;
}