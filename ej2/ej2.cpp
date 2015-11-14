#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/time.h>
#include <algorithm>

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


//NO LO BORREN AÚN POR LAS DUDISSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS!!!!!!!!!!!!

//bool list_coloring_recursivo(Grafo &g, std::vector<Vertice> vertices, int i) {
//  bool pude_pintar = false; // ! ver que este bien esta inicializacion
//  //caso base
//  if (i == (g.cant_vertices() - 1)) { //estoy pintando al ultimo nodo
//    std::set<int> colores = g.dame_colores_posibles(i); //colores posibles para ese vertice
//    std::set<int> colores_vecinos = g.conjunto_colores_vecinos(i); //colores de los vecinos (aquellos que ya estan definidos)
//    borrar_subconjunto(colores, colores_vecinos); //elimino los colores de mis vecinos, ya que no puedo utilizarlos
//    if (!colores.empty()) { //si me queda algun color disponible
//      std::set<int>::iterator it = colores.begin();
//      g.pintar(i, *it); //elijo un color arbitrariamente y pinto
//      pude_pintar = true;
//    } else { //si no quedan colores disponibles, retorno false
//      g.pintar(i, -1);
//      pude_pintar = false; //voy a volver a la rama anterior de la recursion
//    }
//      
//  } else {
//    //paso recursivo
//    //if (cardinal_menor_dos(g, vertices, i)) {
//    //  aca armo el grafo para pasarle a 2-list-coloring
//    //} else { //hago la recursion comun
//        std::set<int> colores = g.dame_colores_posibles(i); //colores posibles para ese vertice
//        std::set<int> colores_vecinos = g.conjunto_colores_vecinos(i); //colores de los vecinos (aquellos que ya estan definidos)
//        borrar_subconjunto(colores, colores_vecinos); //elimino los colores de mis vecinos, ya que no puedo utilizarlos
//
//        for (std::set<int>::iterator it_c = colores.begin(); it_c != colores.end() && !pude_pintar; ++it_c) { //mientras tenga colores no utilizados, y no hay podido pintar el grafo  
//          g.pintar(i, *it_c); //pinto actual de un color determinado
//          pude_pintar = list_coloring_recursivo(g, vertices, ++i);
//          if (!pude_pintar) {
//            g.pintar(i, -1); //pinto actual de un color determinado
//            --i;
//          }
//        }
//      //}
//  }
//  return pude_pintar;
//}
//
//void borrar_subconjunto(std::set<int> &c1, std::set<int> &c2) {
//  std::set<int>::iterator it;
//  for (int i : c2) {
//    it = c1.find(i);
//    if (it != c1.end())
//      c1.erase(it);
//  }  
//}


///////////////////////////////////////////AUXILIARES//////////////////////////////////////////////

bool cardinal_menor_dos(Grafo &g, std::vector<Vertice> vertices, int i) { //O(n)
  bool res = true;
  for (int j = i; j < vertices.size() && res; ++j) { //itero sobre los vértices no coloreados
    if (g.dame_colores_posibles(j).size() > 2)  res = false; //si alguno tiene más de dos colores, retorno false
  }
  return res;
}

void eliminar_color_a_vecinos(Grafo &g, int i, int color) { // O(n*c)
  for (int j = i+1 ; j < g.cant_vertices() ; ++j) { //itero sobre los vecinos de i subsiguientes en el vector O(n)
    if (g.existe_arista(i, j))  g.eliminar_color_de_vertice(j, color); //les elimino el color que le asigné a i O(c) 
  }
}

void agregar_color_a_vecinos(Grafo &g, int i, int color, std::vector<std::set<int > > colores_originales) { //O(n*c)
  std::set<int>::iterator it;
  for (int j = i+1 ; j < g.cant_vertices() ; ++j) { //itero sobre los vecinos de i O(n)
    if (g.existe_arista(i, j)) {
      it = colores_originales[j].find(color); //chequeo si originalmente tenían ese color O(c)
      if (it != colores_originales[j].end()) g.agregar_color_a_vertice(j, color); //si lo tenían, lo agrego
    }
  }
}
void borrar_todos_menos(Grafo &g, int i, int color) { //O(C)
  for (std::set<int>::iterator it = g.dame_colores_posibles(i).begin() ; it != g.dame_colores_posibles(i).end(); ++it) { 
    if (*it != color) g.dame_colores_posibles(i).erase(it);
  }
}
void agregar_todos(Grafo &g, int i, std::set<int> colores) { //O(C)
  for (int c : colores) 
    g.agregar_color_a_vertice(i, c);
}

////////////////////////////////////////////////////////////////////////////////////////////////

//CREO QUE ESTE ANDA
//LIST_COLORING_RECURSIVO SIN LLAMAR A 2-LIST-COLORING
bool list_coloring_recursivo(Grafo &g, std::vector<Vertice> &vertices, std::vector<std::set <int> > colores_originales, int i) {
  bool pude_pintar = false; 
  std::set<int> colores = g.dame_colores_posibles(i);
  //caso base
  if (i == (g.cant_vertices() - 1)) { //estoy pintando al ultimo nodo
    if (!colores.empty()) { //si me queda algun color disponible
      std::set<int>::iterator it = colores.begin();
      g.pintar(i, *it); //elijo un color arbitrariamente y pinto
      pude_pintar = true;
    } else { //si no quedan colores disponibles, retorno false
      g.pintar(i, -1);
      pude_pintar = false; //voy a volver a la rama anterior de la recursion
    }
      
  } else {
    //paso recursivo
    for (std::set<int>::iterator it_c = colores.begin(); it_c != colores.end() && !pude_pintar; ++it_c) { //mientras tenga colores no utilizados, y no hay podido pintar el grafo  
      g.pintar(i, *it_c); //pinto actual de un color determinado
      eliminar_color_a_vecinos(g, i, *it_c); //le borro el color elegido a los vecinos de i
      pude_pintar = list_coloring_recursivo(g, vertices, colores_originales, ++i);
      if (!pude_pintar) {
        g.pintar(i, -1); //pinto actual de -1
        --i;
        agregar_color_a_vecinos(g, i, *it_c, colores_originales); //agrego el color elegido a los vecinos de i
      }
    }
  }
  return pude_pintar;
}

///////////////////////////////////////////////////////////////////////////////////////////

//LIST_COLORING_RECURSIVO LLAMANDO A 2-LIST-COLORING
//bool list_coloring_recursivo(Grafo &g, std::vector<Vertice> &vertices, std::vector<std::set <int> > colores_originales, int i) {
//  bool pude_pintar = false; 
//  std::set<int> colores = g.dame_colores_posibles(i);
//  //caso base
//  if (i == (g.cant_vertices() - 1)) { //estoy pintando al ultimo nodo
//    if (!colores.empty()) { //si me queda algun color disponible
//      std::set<int>::iterator it = colores.begin();
//      g.pintar(i, *it); //elijo un color arbitrariamente y pinto
//      pude_pintar = true;
//    } else { //si no quedan colores disponibles, retorno false
//      g.pintar(i, -1);
//      pude_pintar = false; //voy a volver a la rama anterior de la recursion
//    }
//      
//  } else {
//    //paso recursivo
//    if (cardinal_menor_dos(g, vertices, i)) { //chequeo si todos los vértices tienen menos de 2 colores
//      std::vector<std::set<int> > colores_parciales;
//      for (int j = 0 ; j < i ; ++j) { //armo grafo para pasarle a dos_list_coloring
//        colores_parciales.push_back(g.dame_colores_posibles(j)); //guardo los colores posibles hasta el momento
//        borrar_todos_menos(g, j, g.dame_color(j));
//      }
//
//      pude_pintar = dos_list_coloring(g);
//
//      if (!pude_pintar) { //restauro el estado de la rama de recursión
//        for (int j = 0 ; j < i ; ++j) {
//          agregar_todos(g, j, colores_parciales[j]);
//        }
//      }
//
//    } else { //hago la recursion comun
//
//      for (std::set<int>::iterator it_c = colores.begin(); it_c != colores.end() && !pude_pintar; ++it_c) { //mientras tenga colores no utilizados, y no hay podido pintar el grafo  
//        g.pintar(i, *it_c); //pinto actual de un color determinado
//        eliminar_color_a_vecinos(g, i, *it_c);
//        pude_pintar = list_coloring_recursivo(g, vertices, colores_originales, ++i);
//        if (!pude_pintar) {
//          g.pintar(i, -1); //pinto actual de un color determinado
//          --i;
//          agregar_color_a_vecinos(g, i, *it_c, colores_originales);
//        }
//      }
//    }
//  }
//  return pude_pintar;
//}
//
bool list_coloring_backtracking(Grafo &g){
  
  std::vector<Vertice> vertices;
  for (int i = 0 ; i < g.cant_vertices() ; ++i) {
    vertices.push_back(g.dame_vertice(i));
  }
  //std::sort(vertices.begin(), vertices.end()); //INTENTAR HACERLO CON SORT DESPUES !
  
  std::vector<std::set<int> > colores_originales;
  for (int j = 0 ; j < g.cant_vertices() ; ++j) {
    colores_originales.push_back(g.dame_colores_posibles(j));
  }

  return list_coloring_recursivo(g, vertices, colores_originales, 0);
}


int evaluarTests(std::string fileTestData/*, std::string fileTestResult, std::string fileTestWrite*/) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
//  std::ofstream fileResult (fileTestResult.c_str());
//  std::ofstream fileWrite (fileTestWrite.c_str());
  std::string s;
  std::string res;
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

    bool hay_solucion = list_coloring_backtracking(grafo);
     
    std::cout << "Hay solución: " << hay_solucion << std::endl;

    grafo.imprimir();

//    if (hay_solucion) { //imprimo coloreo del grafo
//
//      for (int i = 0; i < grafo.cant_vertices(); ++i) { 
//        fileResult << grafo.dame_color(i); 
//        fileResult << " "; 
//      }
//
//    } else { //devuelvo X
//      fileResult << "X"; 
//    }
//    fileResult << std::endl;
  }
  return 0;
}

void test_c3_coloreable() {
  Grafo g;
  std::set<int> color_v1{1, 2};
  g.agregar_vertice(color_v1);
  std::set<int> color_v2{1};
  g.agregar_vertice(color_v2);
  std::set<int> color_v3{3, 1};
  g.agregar_vertice(color_v3);
  g.agregar_arista(0, 1);
  g.agregar_arista(0, 2);
  g.agregar_arista(1, 2);
  bool res = list_coloring_backtracking(g);
  std::cout << "Se pudo colorear " << res << std::endl;
  g.imprimir();
}

void test_barriletes_unidos_no_coloreable() {
  Grafo g;
  std::set<int> color_1{1, 2, 3};
  g.agregar_vertice(color_1); //v0
  g.agregar_vertice(color_1); //v1
  g.agregar_vertice(color_1); //v2
  g.agregar_vertice(color_1); //v3
  g.agregar_vertice(color_1); //v4
  g.agregar_vertice(color_1); //v5
  g.agregar_vertice(color_1); //v5
  g.agregar_arista(0, 1);
  g.agregar_arista(0, 2);
  g.agregar_arista(0, 6);
  g.agregar_arista(1, 2);
  g.agregar_arista(1, 3);
  g.agregar_arista(2, 3);
  g.agregar_arista(3, 4);
  g.agregar_arista(3, 5);
  g.agregar_arista(4, 5);
  g.agregar_arista(4, 6);
  g.agregar_arista(5, 6);
  bool res = list_coloring_backtracking(g);
  std::cout << "Se pudo colorear " << res << std::endl;
  g.imprimir();
}

int main(int argc, char** argv) {
  std::string fileTestData(argv[1]);
//  std::string fileTestResult(argv[2]);
  //std::string fileTestWrite(argv[3]);
  // Recibo por parametro tres archivos
  // El primero del cual leo los datos a evaluar
  // El segundo en el cual evaluo si los resultados fueron correctos
  // El tercero donde puedo escribir datos (tiempos)

  //test_k33_coloreable();
 //test_barriletes_unidos_no_coloreable(); 
  //test_barriletes_unidos_coloreable();
  //test_k6_no_coloreable(); 
  //test_k6_coloreable(); 
  //test_k4_coloreable(); 
  //test_c3_no_coloreable(); 
  //test_c3_coloreable();

  evaluarTests(fileTestData/*, fileTestResult, fileTestWrite*/);
  
  return 0;
}
