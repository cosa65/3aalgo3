#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int generar_mejor_caso(int vertices, std::string fileTestResult) {
  std::ofstream fileResult (fileTestResult.c_str());

  int colores = vertices;
  int aristas = (vertices * (vertices-1)) / 2;
  // #vértices #aristas #colores
  fileResult << vertices << ' ' << aristas << ' ' << colores << std::endl;
  // escribo cantidad de colores y colores de cada vértice
  for (int i = 0 ; i < vertices ; ++i) {
    fileResult << colores;
    for (int j = 0 ; j < colores ; ++j) {
      fileResult << ' ' << j;
    }
    fileResult << std::endl;
  }

  //escribo las aristas
  for (int i = 0 ; i < vertices ; ++i) {
    for (int j = i+1 ; j < vertices ; ++j) 
      fileResult << i << ' ' << j << std::endl;
  }

  return 0;
}

int generar_peor_caso(int vertices, std::string fileTestResult) {
  std::ofstream fileResult (fileTestResult.c_str());

  int colores = vertices-1;
  int aristas = (vertices * (vertices-1)) / 2;
  // #vértices #aristas #colores
  fileResult << vertices << ' ' << aristas << ' ' << colores << std::endl;
  // escribo cantidad de colores y colores de cada vértice
  for (int i = 0 ; i < vertices ; ++i) {
    fileResult << colores;
    for (int j = 0 ; j < colores ; ++j) {
      fileResult << ' ' << j;
    }
    fileResult << std::endl;
  }

  //escribo las aristas
  for (int i = 0 ; i < vertices ; ++i) {
    for (int j = i+1 ; j < vertices ; ++j) 
      fileResult << i << ' ' << j << std::endl;
  }

  return 0;
}

int main(int argc, char** argv) {
  int caso = atoi(argv[1]);
  int cant_vertices = atoi(argv[2]);
  std::string fileTestResult(argv[3]);
  
  if (caso == 1)  generar_mejor_caso(cant_vertices, fileTestResult);
  if (caso == 2)  generar_peor_caso(cant_vertices, fileTestResult);

  return 0;
}
