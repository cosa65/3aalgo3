#ifndef GRAFO_H_
#define GRAFO_H_

#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <list>
#include <tuple>
#include <stack>
#include <assert.h>
#include <iostream>

#include "vertice_menor_color.h"

class Grafo {
  
  public:

    Grafo();
    Grafo(int vertices);

    void agregar_arista(int vertice1, int vertice2);
    void agregar_vertice(std::set<int> colores);

    
    int cant_vertices() {return vertices_.size();};
    int conflictos(int v);
    int conflictos_totales();
    std::set<int> conjunto_colores_vecinos(int vertice);

    void agregar_color_a_vertice(int vertice, int color);
    void eliminar_color_de_vertice(int vertice, int color);

    std::set<int> dame_vecinos(int vertice);
    std::set<int> dame_vecinos_no_visitados(int vertice);
    std::set<int> dame_colores_posibles(int vertice);
    int dame_color(int vertice);
    Vertice dame_vertice(int num);
    void dfs(int inicial, std::stack<int>& vertices_vistos);

    void intercambiar_color(int v1, int v2);

    void imprimir();
    void impimir_color(std::string);
    
    bool existe_arista(int vertice1, int vertice2);
    bool existe_vertice(int vertice);

    void pintar(int vertice, int color);
    void desvisitar_vertices();

    int valor_de_intercambio(int v1, int v2);
    int valor_de_pintar(int v1, int color);
    bool son_colores_intercambiables(int v1, int v2);

  private:

    std::vector<std::list<int> > vecinos_;
    std::vector<Vertice> vertices_;
};

#endif
