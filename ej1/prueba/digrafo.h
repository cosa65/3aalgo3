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

using namespace std;

class Digrafo {
  
  public:

    Digrafo();
    Digrafo(Grafo& g);

    void agregar_arista(int vertice1, int vertice2);
    int agregar_vertice(int color, int num, bool valor_de_verdad);

    int cant_vertices() {return vecinos_.size();};
    Digrafo invertir_aristas();

    std::set<int> dame_vecinos(int vertice);

    void imprimir();

    bool existe_arista(int vertice1, int vertice2);
    bool existe_vertice(int vertice);
    list<list<int>> Kosaraju();

  private:

    struct Vertice {
      int color;
      int num;
      int id;
      bool valor_de_verdad; 
      bool visto;
      Vertice(int col, int n, int id, bool v) : color(col) , num(n) , id(id) , valor_de_verdad(v) , visto(false) {};
    };

    void expandir_vertice_1_color(std::set<int> colores, int v1);
    void expandir_vertice_2_colores(std::set<int> colores, int v1);

    void agregar_arista_1_color(std::set<int> colores, int v1, int v2);
    void agregar_arista_2_colores(std::set<int> colores, int v1, int v2);

    int dame_posicion_vertice(int vertice, int color, bool valor_de_verdad);

    void dfs( vector<bool>& visitados, stack<int>& finish_time);
    void recorrer(int i, vector<bool>& visitados, stack<int>& finish_time);
    list<list<int>> dfs2( vector<bool>& visitados, stack<int>& finish_time);
    list<int> recorrer2(int i, vector<bool>& visitados, list<int>& componente);

    std::vector<std::list<int> > vecinos_;
    std::vector<Vertice> vertices_;
};

#endif
