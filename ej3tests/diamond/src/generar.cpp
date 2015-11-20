#include <iostream>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

int main(int argc, char **argv)
{
	string filename(argv[1]); //Archivo a escribir
	int N = atoi(argv[2]); // Vértices
	int M = 2*(N-2); // Aristas
	int C = atoi(argv[3]); // Colores
	int random = atoi(argv[4]); //Esto dice si se generan colores random o todos iguales.

	srand(time(NULL));

	ofstream file(filename.c_str());
	file << N << " " << M << " " << C << endl;
	ostringstream save;
	int colsTot;


	// if ( !random )
	if ( random == 0 )
	{
		for (int i = 0 ; i < N ; ++i)
		{
			file << C;
			for (int j = 0 ; j < C ; ++j)
				file << ' ' << j;
			file << std::endl;
		}
	}
	else
	{
		for( int i = 0; i < N; i++ )
		{
			ostringstream saveOne;
			colsTot = 0;
			for(int j=0; j<C; j++)
			{
				if(rand()%2	== 1) {
					saveOne << j << " ";
					colsTot++;
				}
			}
			if(colsTot==0) {
				saveOne << rand()%C;
				colsTot++;
			}

			file << colsTot << " " << saveOne.str() << endl;
			}
		}	


	for( int i=1; i< N-1; i++ )
	{
		file << 0 << " " << i << endl;
		file << i << " " << N-1 << endl;
	}

	file.close();

	return 0;
}