#ifndef GRAFO_H_
#define GRAFO_H_

#include <vector>
#include <set>
#include <list>
#include <tuple>
#include <stack>
#include <assert.h>
#include <iostream>

#include "vertice.h"

class Grafo {
  
  public:

    Grafo();
    Grafo(int vertices);

    void agregar_arista(int vertice1, int vertice2);
    void agregar_vertice(std::set<int> colores);

    int cant_vertices() {return vertices_.size();};

    std::set<int> dame_vecinos(int vertice);
    std::set<int> dame_vecinos_no_visitados(int vertice);
    std::set<int> dame_colores_posibles(int vertice);
    int dame_color(int vertice);
    Vertice dame_vertice(int num);

    void imprimir();

    void dfs(int inicial, std::stack<int>& vertices_vistos);
    
    bool existe_arista(int vertice1, int vertice2);
    bool existe_vertice(int vertice);

    void pintar(int vertice, int color);

    std::set<int> conjunto_colores_vecinos(int vertice);


  private:

    std::vector<std::list<int> > vecinos_;
    std::vector<Vertice> vertices_;
};

#endif
