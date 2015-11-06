#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sys/time.h>

#include "../grafo/grafo.h"
#include "goloso.cpp"

/*
timeval start, end;
double acum = 0;

void init_time() {
  gettimeofday(&start, NULL);
}

double get_time() {
  gettimeofday(&end, NULL);
  return (1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec))/1000000.0;
}
*/
//Funciones y datos utilizados para la toma de tiempos



bool paso_busqueda_local(Grafo in){             //Devuelve true si consiguió dar un paso que mejorara el estado anterior
  int verts = in.cant_vertices();
  int conflictos = 0;
  int mejorPasov1, mejorPasov2;

  for(int i=0; i<verts; i++){
    for(int j=0; j<verts; j++){
      int actual = in.valor_de_intercambio(i,j);
      if(actual < conflictos){
        conflictos = actual;
        mejorPasov1 = i;
        mejorPasov2 = j;
      }
    }
  }
  if(conflictos == 0){
    return false;
  } else {
    in.intercambiar_color(mejorPasov1,mejorPasov2);
    return true;
  }
}

void busqueda_local(Grafo in){
  bool mejoro = true;
  while(mejoro){
    mejoro = paso_busqueda_local(in);
  }
}

int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
  //std::ifstream fileResult (fileTestResult.c_str());
  std::string s;
  std::string res;
  int z = 1;
  // Abri los archivos de datos y resultados
  // e instancie las variables necesarias para el problema
  // el vector de exploradoras y el vector de amistades 


  while (getline (fileData, line)) {
    Grafo grafo;
    int n;
    int m;
    int c;

    std::istringstream iss(line);

    iss >> n;
    iss >> m;
    iss >> c;

    for (int i = 0 ; i < n ; ++i) {
      getline(fileData, line);
      std::istringstream iss(line);

      int cantidad_colores;
      iss >> cantidad_colores;

      std::set<int> colores; 
      for (int j = 0 ; j < cantidad_colores ; ++j) {
        int color;
        iss >> color;
        colores.insert(color);
      }

      grafo.agregar_vertice(colores);

    }

    for (int i = 0 ; i < m ; ++i) {
      getline(fileData, line);
      std::istringstream iss(line);

      int v1;
      int v2;
      iss >> v1;
      iss >> v2;

      grafo.agregar_arista(v1, v2);
    }

    
    goloso_por_grado_vertice(grafo);
    grafo.imprimir();
    busqueda_local(grafo);

    grafo.imprimir();
    grafo.impimir_color(fileTestWrite);
    ++z;

  }
  return 0;
}

int main(int argc, char** argv) {
  std::string fileTestData(argv[1]);
  std::string fileTestResult(argv[2]);
  std::string fileTestWrite(argv[3]);
  // Recibo por parametro tres archivos
  // El primero del cual leo los datos a evaluar
  // El segundo en el cual evaluo si los resultados fueron correctos
  // El tercero donde puedo escribir datos (tiempos)

  evaluarTests(fileTestData, fileTestResult, fileTestWrite);
  
  return 0;
}
