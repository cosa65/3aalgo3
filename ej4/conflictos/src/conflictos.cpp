#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

int main(int argc, char **argv){
	int N,M,C;
	N = atoi(argv[1]);				//Cantidad de nodos del grafo a generar
	std::string filename(argv[2]);
	std::string familia(argv[3]);
	M=0;
	srand(time(NULL));	

	std::ofstream file(filename.c_str());
	file << std::endl;
	C = 3;				//Hay entre 1 y N colores disponibles
	file << N << " ";
	std::ostringstream save;
	int colsTot;
	long posIn,posFin;

	if(familia.compare("rueda")==0){

		for(int i=0; i<N; i++){
			std::ostringstream saveOne;
			colsTot = 0;
			for(int j=0; j<C; j++){
				if(rand()%2	== 1) {
					saveOne << j << " ";
					colsTot++;
				}
			}
			if(colsTot==0) {
				saveOne << rand()%C;
				colsTot++;
			}

			save << colsTot << " " << saveOne.str() << std::endl;
		}

		for(int i=1; i<N; i++){
			save << 0 << " " << i << std::endl;
		}
		for(int i=1; i<N-1; i++){
			save << i << " " << i+1 << std::endl;
		}

		file << N-1 + N-1 << " " << C << std::endl << save.str();

	} else if(familia.compare("bipartito")==0) {

		for(int i=0; i<N; i++){
			std::ostringstream saveOne;
			colsTot = 0;
			for(int j=0; j<C; j++){
				if(rand()%2	== 1) {
					saveOne << j << " ";
					colsTot++;
				}
			}
			if(colsTot==0) {
				saveOne << rand()%C;
				colsTot++;
			}

			save << colsTot << " " << saveOne.str() << std::endl;
		}

		std::set<int> G1;
		std::set<int> G2;

		for(int i=0; i<N; i++){
			if(rand()%2 == 1){
				G1.insert(i);
			} else {
				G2.insert(i);
			}
		}

		for(int v1 : G1){
			for(int v2 : G2){
				if(rand()%2 == 1){
					save << v1 << " " << v2 << std::endl;
					M++;
				}
			}
		}

		file << M << " " << C << std::endl << save.str();

	}

	file.close();

	return 0;
}