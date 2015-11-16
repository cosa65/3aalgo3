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
#include "../grafo/digrafo.h"


timeval start, end;
double acum = 0;
int x = 0;

void init_time() {
  gettimeofday(&start, NULL);
}

double get_time() {
  gettimeofday(&end, NULL);
  return (1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec))/1000000.0;
}

//Funciones y datos utilizados para la toma de tiempos


//ESTO HABRIA QUE PONERLO EN OTRO LUGAR, NO DA COPIARLO DOS VECES
//////////////////////////////////////DOS_LIST_COLORING/////////////////////////////////////////////////

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
  
  //convierto el grafo g en el digrafo
  Digrafo digrafo(g);

  //kosaraju bla bla
  std::list<std::list<int>> cfc = digrafo.Kosaraju();

  std::vector<int> vertices_por_componente(digrafo.cant_vertices());
  std::fill(vertices_por_componente.begin(), vertices_por_componente.end(), -1);

  bool hay_solucion = hay_contradiccion(digrafo, cfc, vertices_por_componente);
  if (hay_solucion) {
    Digrafo digrafo_comp_f_conexas;
    conectar_componentes_fuertemente_conexas(digrafo_comp_f_conexas, digrafo, vertices_por_componente);

  std::vector<bool> coloreo = colorear(digrafo, cfc, vertices_por_componente);

  for (int i = 0; i < coloreo.size(); ++i)
  {
    
    if (coloreo[i] && digrafo.dame_vertice(i).dame_valor_de_verdad())
    {
      g.pintar(digrafo.dame_vertice(i).dame_nombre(), digrafo.dame_vertice(i).dame_color());
    }
  
  } 

}
  return hay_solucion;
}

///////////////////////////////////////////AUXILIARES//////////////////////////////////////////////

//para checkear que puedo usar dos_list_coloring
bool cardinal_menor_dos(Grafo &g, std::vector<Vertice> vertices, int i) { //O(n)
  bool res = true;
  for (int j = i; j < vertices.size() && res; ++j) { //itero sobre los vértices no coloreados
    if (g.dame_colores_posibles(j).size() > 2 || g.dame_colores_posibles(j).size() < 1 )  res = false; //si alguno tiene más de dos colores o si no tiene ningun color posible, retorno false
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
  std::set<int> colores = g.dame_colores_posibles(i);
  for (int c : colores) {
    if (c != color) { 
      g.eliminar_color_de_vertice(i, c);
    }
  }  
}

void agregar_todos(Grafo &g, int i, std::set<int> colores) { //O(C)
  for (int c : colores) 
    g.agregar_color_a_vertice(i, c);
}

////////////////////////////////////////////////////////////////////////////////////////////////

//LIST_COLORING_RECURSIVO SIN LLAMAR A 2-LIST-COLORING
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
//    for (std::set<int>::iterator it_c = colores.begin(); it_c != colores.end() && !pude_pintar; ++it_c) { //mientras tenga colores no utilizados, y no hay podido pintar el grafo  
//      g.pintar(i, *it_c); //pinto actual de un color determinado
//      eliminar_color_a_vecinos(g, i, *it_c); //le borro el color elegido a los vecinos de i
//      pude_pintar = list_coloring_recursivo(g, vertices, colores_originales, ++i);
//      if (!pude_pintar) {
//        g.pintar(i, -1); //pinto actual de -1
//        --i;
//        agregar_color_a_vecinos(g, i, *it_c, colores_originales); //agrego el color elegido a los vecinos de i
//      }
//    }
//  }
//  return pude_pintar;
//}

///////////////////////////////////////////////////////////////////////////////////////////

//LIST_COLORING_RECURSIVO LLAMANDO A 2-LIST-COLORING
bool list_coloring_recursivo(Grafo &g, std::vector<Vertice> &vertices, std::vector<std::set <int> >& colores_originales, int i) {
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
    if (cardinal_menor_dos(g, vertices, i)) { //chequeo si todos los vértices tienen menos de 2 colores
      std::vector<std::set<int> > colores_parciales;
      for (int j = 0 ; j < i ; ++j) { //armo grafo para pasarle a dos_list_coloring
        colores_parciales.push_back(g.dame_colores_posibles(j)); //guardo los colores posibles hasta el momento
        borrar_todos_menos(g, j, g.dame_color(j)); //le dejo al grafo un solo posible color, que es el que le asignó antes de hacer la llamada recursiva
      }

      pude_pintar = dos_list_coloring(g);

      if (!pude_pintar) { //restauro el estado de la rama de recursión
        for (int j = 0 ; j < i ; ++j) {
          agregar_todos(g, j, colores_parciales[j]);
        }
      }

    } else { //hago la recursión común

      for (std::set<int>::iterator it_c = colores.begin(); it_c != colores.end() && !pude_pintar; ++it_c) { //mientras tenga colores no utilizados, y no hay podido pintar el grafo  
        g.pintar(i, *it_c); //pinto actual de un color determinado
        eliminar_color_a_vecinos(g, i, *it_c);
        pude_pintar = list_coloring_recursivo(g, vertices, colores_originales, ++i);
        if (!pude_pintar) {
          g.pintar(i, -1); //pinto actual de un color determinado
          --i;
          agregar_color_a_vecinos(g, i, *it_c, colores_originales);
        }
      }
    }
  }
  return pude_pintar;
}

bool list_coloring_backtracking(Grafo &g){
  init_time();
  
  std::vector<Vertice> vertices;
  for (int i = 0 ; i < g.cant_vertices() ; ++i) {
    vertices.push_back(g.dame_vertice(i));
  }
  //std::sort(vertices.begin(), vertices.end()); 
  
  std::vector<std::set<int> > colores_originales;
  for (int j = 0 ; j < g.cant_vertices() ; ++j) {
    colores_originales.push_back(g.dame_colores_posibles(j));
  }

  return list_coloring_recursivo(g, vertices, colores_originales, 0);
}


int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
  std::ofstream fileResult (fileTestResult.c_str());
  std::ofstream fileWrite (fileTestWrite.c_str());
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

    for (int k = 0 ; k < 50 ; ++k) {
      bool hay_solucion = list_coloring_backtracking(grafo);
      acum = get_time(); 
    }
    fileWrite << std::fixed << acum  << std::endl;
     
    //std::cout << "Hay solución: " << hay_solucion << std::endl;

    std::cout << "iteracion: " << x << std::endl;
    ++x;
    //grafo.imprimir();

    //if (hay_solucion) { //imprimo coloreo del grafo

    //  for (int i = 0; i < grafo.cant_vertices(); ++i) { 
    //    fileResult << grafo.dame_color(i); 
    //    fileResult << " "; 
    //  }

    //} else { //devuelvo X
    //  fileResult << "X"; 
    //}
    //fileResult << std::endl;
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
