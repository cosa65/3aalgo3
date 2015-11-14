#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/time.h>

#include "../grafo/grafo.h"
#include "../grafo/digrafo.h"

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

bool hay_contradiccion(Digrafo &digrafo, std::list<std::list<int>>& comp_conexas, std::vector<int>& vertices_por_componente) {

  bool res = true;
  int indice_componente = 0;

  for (std::list<int>& componentes : comp_conexas) {
    for (int vertice : componentes) {
      vertices_por_componente[vertice] = indice_componente;
      int contrario = digrafo.dame_contrario(vertice);
      if (vertices_por_componente[contrario] == indice_componente)
        res = false;
    }
    indice_componente++;
  }
  return res;
}

void conectar_componentes_fuertemente_conexas(Digrafo& digrafo_comp_f_conexas, Digrafo& digrafo, std::vector<int> vertices_por_componentes) {
  int cant_vertices = digrafo.cant_vertices();
  for (int i = 0 ; i < cant_vertices ; ++i) {
    digrafo.agregar_vertice(-1, i, false);
  }

  for (int i = 0 ; i < cant_vertices ; ++i) {
    std::set<int> vecinos = digrafo.dame_vecinos(i);
    for (int v : vecinos) {
      if (vertices_por_componentes[i] != vertices_por_componentes[v])
        digrafo.agregar_arista(vertices_por_componentes[i], vertices_por_componentes[v]);
    }
  }
}

bool dos_list_coloring(Grafo &g) {
  
  //convierto el grafo g en el digrafo
  Digrafo digrafo(g);

  //kosaraju bla bla
  std::list<std::list<int>> cfc = digrafo.kosaraju();

  std::vector<int> vertices_por_componente(g.cant_vertices());
  std::fill(vertices_por_componente.begin(), vertices_por_componente.end(), -1);

  bool hay_solucion = hay_contradiccion(digrafo, cfc, vertices_por_componente);
  if (hay_solucion) {
    Digrafo digrafo_comp_f_conexas;
    conectar_componentes_fuertemente_conexas(digrafo_comp_f_conexas, digrafo, vertices_por_componente);

    // Para cada vertice del vector vertices_por_componente
    // agarras el elemento de la posicion i
    // pedis el contrario
    // te fijas en que cfc esta
    // preguntas
    // al nodo en el que estoy parado o su contradiccion ya le asigne un valor de verdad?
    // si ya le asigne un valro de verdad, me aseguro de no contradecirlo
    // si no le asigne un valor de verdad le pongo false



  //aca viene el orden topologico y coloreo del grafo
  
  } 

  return hay_solucion;
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

/*
  for (std::list<std::list<int>>::iterator it_componentes = comp_conexas.begin() ; it_componentes != comp_conexas.end() && res ; ++it_componentes) { //para cada componente fuertemente conexa
    for (std::list<int>::iterator it_elems = (*it_componentes).begin() ; it_elems != (*it_componentes).end() && res ; ++it_elems) { //para cada elemento de la componente
      int id_vertice = *it_elems; //elijo un vertice
      for (std::list<int>::iterator it_elems = (*it_componentes).begin() ; it_elems != (*it_componentes).end() ; ++it_elems) { 
      //recorro todos los elementos de la componente para ver que no ocurra p => ¬p
        if (g.son_contrarias(id_vertice, *it_elems)) //si ocurre, hay contradiccion y por lo tanto no hay solucion
          res = false;
      }
    
    }
  }*/
