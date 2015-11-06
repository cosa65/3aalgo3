#ifndef DIGRAFO_H_
#define DIGRAFO_H_

#include <vector>
#include <set>
#include <list>
#include <tuple>
#include <stack>
#include <assert.h>
#include <iostream>
#include <algorithm>
//#include <boost/foreach.hpp>
#include "grafo.h"
#include "vertice_digrafo.h"

//#define foreach BOOST_FOREACH

class Digrafo {
  
  public:

    Digrafo();
    Digrafo(Grafo& g);

    void agregar_arista(int vertice1, int vertice2);
    int agregar_vertice(int color, int num, bool valor_de_verdad);

    int cant_vertices() {return vecinos_.size();};
    Digrafo invertir_aristas();

    std::set<int> dame_vecinos(int vertice);
    Vertice_digrafo dame_vertice(int id);
    bool son_contrarias(int id1, int id2);

    std::list<Digrafo> Kosaraju(int init);

    void imprimir();

    void dfs(int inicial, std::stack<int>& vertices_vistos);
    void dfs2(int inicial);
    
    bool existe_arista(int vertice1, int vertice2);
    bool existe_vertice(int vertice);
    

  private:

    void expandir_vertice_1_color(std::set<int> colores, int v1);
    void expandir_vertice_2_colores(std::set<int> colores, int v1);

    void agregar_arista_1_color(std::set<int> colores, int v1, int v2);
    void agregar_arista_2_colores(std::set<int> colores, int v1, int v2);

    int dame_posicion_vertice(int vertice, int color, bool valor_de_verdad);

    std::vector<std::list<int> > vecinos_;
    std::vector<Vertice_digrafo> vertices_;
};

#endif
