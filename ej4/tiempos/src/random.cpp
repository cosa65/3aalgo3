#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv){
	int N,M,C;
	N = atoi(argv[1]);				//Cantidad de nodos del grafo a generar
	M = atoi(argv[2]);
	C = atoi(argv[3]);
	std::string filename(argv[4]);

	srand(time(NULL));	

	std::ofstream file(filename.c_str());
	file << std::endl;
	file << N << " ";

	if(M == 0) {
		std::ostringstream save;
		int colsTot;
		long posIn,posFin;
		for(int i=0; i<N; i++){
			colsTot = 0;
			posIn = save.tellp();
			save << "  ";
			for(int j=0; j<C; j++){
				if(rand()%2	== 1) {
					save << j << " ";
					colsTot++;
				}	
			}
			if(colsTot==0) {
				save << rand()%C;
				colsTot++;
			}
			posFin = save.tellp();

			save.seekp(posIn);
			save << colsTot;
			save.seekp(posFin);
			save << std::endl;
		}

		for(int i=0; i<N; i++){
			for(int j=i; j<N; j++){
				if(rand()%2 == 1 && j!=i) {
					save << i << " " << j << std::endl;
					M++;
				}
			}
		}

		file << M << " " << C << std::endl << save.str();

		file.close();
	} else {
		//Aca iria el caso en el que quiera tener predefinida la cantidad de aristas
	}

	return 0;
}