#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "digrafo.h"
#include "grafo.h"
#include "utils.h"

using namespace std;

int evaluarTests(string fileTestData, string fileTestResult)
{

	string line;
	ifstream fileData (fileTestData.c_str());
	ifstream fileResult (fileTestResult.c_str());
	string s;
	string res;

	Grafo grafo;
	while ( getline(fileData, line) )
	{

		int n;
		int m;
		int c;

		istringstream iss(line);

		iss >> n;
		iss >> m;
		iss >> c;

		for (int i = 0 ; i < n ; ++i)
		{

			getline(fileData, line);
			istringstream iss(line);
			int cantidad_colores;
			iss >> cantidad_colores;
			set<int> colores; 
	    
			for (int j = 0 ; j < cantidad_colores ; ++j)
			{
	        	int color;
	        	iss >> color;
				colores.insert(color);
			}

			grafo.agregar_vertice(colores);

		}

		for (int i = 0 ; i < m ; ++i)
		{
	    
			getline(fileData, line);
			istringstream iss(line);
			int v1;
			int v2;
			iss >> v1;
			iss >> v2;

			grafo.agregar_arista(v1, v2);
	    
		}


		
	}

	grafo.ListColoring();

	return 0;

}

int main(int argc, char** argv)
{
	string fileTestData(argv[1]); // IN
	string fileTestResult(argv[2]); //OUT

	evaluarTests(fileTestData, fileTestResult);

	return 0;
}
