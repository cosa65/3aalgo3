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
    Vertice_digrafo dame_vertice(int vertice);
    int dame_contrario(int vertice);
    // bool dame_valor_de_verdad(int vertice);

    void imprimir();
    void imprimir_solo_vecinos();
    
    bool existe_arista(int vertice1, int vertice2);
    bool existe_vertice(int vertice);
    
    bool son_contrarias(int id1, int id2);

    std::list<std::list<int>> Kosaraju();


  private:

    void expandir_vertice_1_color(std::set<int> colores, int v1);
    void expandir_vertice_2_colores(std::set<int> colores, int v1);

    void agregar_arista_1_color(std::set<int> colores, int v1, int v2);
    void agregar_arista_2_colores(std::set<int> colores, int v1, int v2);

    int dame_posicion_vertice(int vertice, int color, bool valor_de_verdad);

    
    void dfs( std::vector<bool>& visitados, std::stack<int>& finish_time);
    void recorrer(int i, std::vector<bool>& visitados, std::stack<int>& finish_time);
    std::list<std::list<int>> dfs2( std::vector<bool>& visitados, std::stack<int>& finish_time);
    std::list<int> recorrer2(int i, std::vector<bool>& visitados, std::list<int>& componente);


    std::vector<std::list<int> > vecinos_;
    std::vector<Vertice_digrafo> vertices_;
};

#endif
