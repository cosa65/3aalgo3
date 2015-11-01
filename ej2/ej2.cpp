#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/time.h>

#include "../grafo/grafo.h"

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

//int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite) {
//  std::string line;
//  std::ifstream fileData (fileTestData.c_str());
//  std::ifstream fileResult (fileTestResult.c_str());
//  std::ofstream fileWrite (fileTestWrite.c_str());
//  std::string s;
//  std::string res;
//  int z = 1;
//  // Abri los archivos de datos y resultados
//  // e instancie las variables necesarias para el problema
//  // el vector de exploradoras y el vector de amistades 
//
//
//  while (getline (fileData, line)) {
//    Grafo grafo;
//    int n;
//    int m;
//    int c;
//
//    std::istringstream iss(line);
//
//    iss >> n;
//    iss >> m;
//    iss >> c;
//
//    for (int i = 0 ; i < n ; ++i) {
//      getline(fileData, line);
//      std::istringstream iss(line);
//
//      int cantidad_colores;
//      iss >> cantidad_colores;
//
//      std::set<int> colores; 
//      for (int j = 0 ; j < cantidad_colores ; ++j) {
//        int color;
//        iss >> color;
//        colores.insert(color);
//      }
//
//      grafo.agregar_vertice(colores);
//
//    }
//
//    for (int i = 0 ; i < m ; ++i) {
//      getline(fileData, line);
//      std::istringstream iss(line);
//
//      int v1;
//      int v2;
//      iss >> v1;
//      iss >> v2;
//
//      grafo.agregar_arista(v1, v2);
//    }
//
//
//
//    bool res = list_coloring_backtracking(grafo);
//
//    grafo.imprimir();
//
//    //getline(fileResult, line);
//    //if (res) {
//    ////imprimo coloreo del grafo
//    //  for (int i = 0; i < grafo.cant_vertices(), ++i) { 
//    //    
//    //  }
//    //} else {
//    ////devuelvo X
//    //}
//    //double prom = acum/100;
//    //FileWrite << "Test numero: " << i << " cantidad de pisos: " << cant_pisos << std::endl;
//    //FileWrite << std::fixed << acum << std::endl;
//    //fileWrite << std::fixed << prom << std::endl;
//    //acum = 0;
//
//
//    //getline (fileResult, line);
//
//    //// Lei una linea del archivo de resultados
//    //// y pregunto si ya termine de evaluar todos los tests
//
//    //int resTest = atoi(line.c_str());
//    ////// convierto a int
//
//    //if (res == resTest) {
//    //  std::cout << "Paso el test " << i << ". Felicitaciones!" << std::endl;
//    //} else {
//    //  std::cout << "Fallo el test " << i << ". :(" << std::endl;
//    //  std::cout << "Obtuve " << res << " deberia tener " << resTest << std::endl;
//    //}
//
//    //std::cout << z << std::endl;
//    ++z;
//
//  }
//  return 0;
//}


bool list_coloring_desde_nodo(Grafo &g, int actual, int padre, int color){
  
  bool pude_pintar = false;

  //caso base
  if (g.dame_colores_posibles(actual).size() == 0)
    pude_pintar = true; //estoy en un nodo que pinté en el paso anterior, y no tengo otros que pintar

  //paso recursivo
  std::set<int> colores = g.dame_colores_posibles(actual);
  for (std::set<int>::iterator it_c = colores.begin(); it_c != colores.end() && !pude_pintar; ++it_c) {
  //mientras tenga colores no utilizados, y no hay podido pintar el grafo  
    if (*it_c != color){ //pinto sólo si no es igual al color de mi padre
      g.pintar(actual, *it_c); //pinto actual de un color determinado
      pude_pintar = true;

      std::set<int> vecinos = g.dame_vecinos_no_visitados(actual);
      
      for (std::set<int>::iterator it = vecinos.begin(); it!=vecinos.end() && pude_pintar; ++it) {
        if (!list_coloring_desde_nodo(g, *it, actual, *it_c))
        //si no pude pintar, tengo que volver al vértice anterior 
          pude_pintar = false; 
      }
    }
  }
  return pude_pintar;
}

//False si no hay solución, True si la hay
bool list_coloring_backtracking(Grafo &g){
  return list_coloring_desde_nodo(g, 0, 0, -1);
}

int main(/*int argc, char** argv*/) {
  //std::string fileTestData(argv[1]);
  //std::string fileTestResult(argv[2]);
  //std::string fileTestWrite(argv[3]);
  // Recibo por parametro tres archivos
  // El primero del cual leo los datos a evaluar
  // El segundo en el cual evaluo si los resultados fueron correctos
  // El tercero donde puedo escribir datos (tiempos)
  Grafo g;

  std::set<int> color_v1;
  color_v1.insert(1);
  color_v1.insert(2);
  g.agregar_vertice(color_v1);

  std::set<int> color_v2;
  color_v2.insert(1);
  g.agregar_vertice(color_v2);

  std::set<int> color_v3;
  color_v3.insert(1);
  g.agregar_vertice(color_v3);

  g.agregar_arista(0, 1);
  g.agregar_arista(0, 2);
  g.agregar_arista(1, 2);

  bool res = list_coloring_backtracking(g);

  std::cout << "Se pudo colorear " << res << std::endl;

  g.imprimir();

  //evaluarTests(fileTestData, fileTestResult, fileTestWrite);
  
  return 0;
}
