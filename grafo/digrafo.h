#include <vector>
#include <set>
#include <list>
#include <tuple>
#include <stack>
#include <assert.h>
#include <iostream>
#include "Grafo.h"

class Digrafo {
  
  public:

    Digrafo();
    Digrafo(Grafo g);

    void agregar_arista(int vertice1, int vertice2);
    void agregar_vertice(std::set<int> colores);

    int cant_vertices() {return vecinos_.size();};
    Digrafo invertir_aristas();

    std::set<int> dame_vecinos(int vertice);

    void imprimir();

    void dfs(int inicial, std::stack<int>& vertices_vistos);
    
    bool existe_arista(int vertice1, int vertice2);
    bool existe_vertice(int vertice);

  private:

    struct Vertice {
      int color;
      int num;
      int id;
      bool valor_de_verdad; 
      bool visto;
      Vertice(int n, int id, bool v) : color(-1) , num(n) , id(id) , valor_de_verdad(v) , visto(false) {};
    };

    std::vector<std::list<int> > vecinos_;
    std::vector<Vertice> vertices_;
};
