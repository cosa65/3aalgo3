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
//

void maximo(std::vector<int> vector) {
  int max = 0;
  int i = 0;
  int j = 0;
  for (int v : vector) {
    if (max < v) { 
      max = v
      i = j;
    }
    j++;
  }
  vector[i] = -1;
  return i;
}

void goloso_por_grado_vertice(Grafo& g) {
  int vistos = 0;
  int cant_vertices = g.cant_vertices();
  std::vector<int> usados;

  // Creo vector para obtener el maximo
  for (int i = 0 ; i < cant_vertices ; ++i) {
    usados.insert(g.dame_grado(i));
  }


  while (vistos < cant_vertices) {

    // Hallar el vertice de mayor grado
    int vertice = maximo(usados);
    std::set<int> color_vertice = g.dame_colores_posibles(vertice);

    // recorro los vecinos del maximo
    std::set<int> vecinos = g.dame_vecinos(vertice);
    for (int v : vecinos) {

      // Si tengo mas de un color disponible para pintarlo
      if (color_vertice.size() > 1) {

        int color_vecino = g.dame_color(v);
        if (color_vecino != -1) { // Ya esta pintado y no puedo usar ese color
          // Me fijo si el de grado maximo tiene ese color como disponible
          std::set<int>::iterator it = colores_vertice.find(color_vecino);
          if (it != colores_vertice.end()) 
            // Si es asi lo borro
            colores_vertice.erase(it);
        } else {
          // Si no esta pintado el vecino
        
        }
        std::set<int> colores = g.dame_colores_posibles(v); 

      }

        // Una vez que tengo el conjunto de colores del vertice tengo que verificar
        // 1) Filtrar los colores que ya estan siendo utilizados por los vertices vecinos 
        // 2) Luego, por el color del vertice que menos se interseco con los de sus vecinos 
        // 3) 
        // si ya esta sinedo utilizado
        //  si el set tiene tamaño 1
        //    no hacer nada
        //  sino 
        //    sacar ese color
        //
        //  colol = Vector de vectores [[color, numero de veces que aparecio]]
        //  sino esta siendo utilizado
        //    para cada conjunto de colores del vecino
        //      si esta en colol
        //        aumentar su numero
        //
        //  sacar el minimo color tal que su numero de veces sea el menor
        //      
        //  pintar al vertice de ese color
      
    }
  } 
}

int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
  std::ifstream fileResult (fileTestResult.c_str());
  std::ofstream fileWrite (fileTestWrite.c_str());
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


    grafo.imprimir();

    //double prom = acum/100;
    //FileWrite << "Test numero: " << i << " cantidad de pisos: " << cant_pisos << std::endl;
    //FileWrite << std::fixed << acum << std::endl;
    //fileWrite << std::fixed << prom << std::endl;
    //acum = 0;


    //getline (fileResult, line);

    //// Lei una linea del archivo de resultados
    //// y pregunto si ya termine de evaluar todos los tests

    //int resTest = atoi(line.c_str());
    ////// convierto a int

    //if (res == resTest) {
    //  std::cout << "Paso el test " << i << ". Felicitaciones!" << std::endl;
    //} else {
    //  std::cout << "Fallo el test " << i << ". :(" << std::endl;
    //  std::cout << "Obtuve " << res << " deberia tener " << resTest << std::endl;
    //}

    //std::cout << z << std::endl;
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
