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

#include "utils.h"

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

std::vector<bool> colorear(Digrafo& digrafo, std::list<std::list<int>> cfc, std::vector<int> vertices_por_componente)
{
  // Vector que indica si ya pinté el nodo i.
  std::vector<bool> coloreados(vertices_por_componente.size());
  std::fill(coloreados.begin(), coloreados.end(), false);
  
  // Vector que indica el valor de verdad del valor de verdad.
  std::vector<bool> valor_de_verdad2(vertices_por_componente.size());
  std::fill(valor_de_verdad2.begin(), valor_de_verdad2.end(), false);

  for (std::list<int>& componente: cfc)
  {
   for (int i: componente)
    {
      // i es el vértice actual, j es su contrario
      int j = digrafo.dame_contrario(i);

      // Hay alguno de los dos coloreados?
      if (coloreados[i] || coloreados[j])
      {
        // i coloreado, j no coloreado
        if (!coloreados[j])
        {
          if (digrafo.dame_vertice(j).dame_valor_de_verdad() == !(valor_de_verdad2[i] ^ digrafo.dame_vertice(i).dame_valor_de_verdad()))
            valor_de_verdad2[j] = true;
          coloreados[j] = true;
        }

        // j coloreado, i no coloreado
        if (!coloreados[i])
        {
          if (digrafo.dame_vertice(i).dame_valor_de_verdad() == !(valor_de_verdad2[j] ^ digrafo.dame_vertice(j).dame_valor_de_verdad()))
            valor_de_verdad2[i] = true;
          coloreados[i] = true;         
        }

      }
      // Ninguno de los dos está coloreado
      else
      {
        // No hay ninguno de los dos coloreados, entonces le pongo false
        valor_de_verdad2[i] = false;
        // Lo marco como coloreado
        coloreados[i] = true;
      
      }
    }
  }

  return valor_de_verdad2;
}


bool dos_list_coloring(Grafo& g) {
  
  // Creo el digrafo expandido a 4 vértices por cada uno en el original
  Digrafo digrafo(g);
  // Busco componentes fuertemente conexas
  std::list<std::list<int>> cfc = digrafo.Kosaraju();
  // Inicializo vector que indica a qué componente pertenece cada vértice
  std::vector<int> vertices_por_componente(digrafo.cant_vertices());
  std::fill(vertices_por_componente.begin(), vertices_por_componente.end(), -1);
  // Chequeo si existe solución (si no existen contradicciones dentro de una misma cfc)
  bool hay_solucion = hay_contradiccion(digrafo, cfc, vertices_por_componente);

  // Coloreo
  if (hay_solucion) {
    std::vector<bool> coloreo = colorear(digrafo, cfc, vertices_por_componente);

    for (int i = 0; i < coloreo.size(); ++i)
    {
      if (coloreo[i] && digrafo.dame_vertice(i).dame_valor_de_verdad())
        g.pintar(digrafo.dame_vertice(i).dame_nombre(), digrafo.dame_vertice(i).dame_color());
    } 
  }

  return hay_solucion;
}

int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
  std::ifstream fileResult (fileTestResult.c_str());
  // std::ofstream fileWrite (fileTestWrite.c_str());
  std::string s;
  std::string res;

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

    dos_list_coloring(grafo);

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
