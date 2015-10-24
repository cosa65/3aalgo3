#include <vector>
#include <set>
#include <list>
#include <tuple>
#include <stack>
#include <assert.h>
#include <iostream>

class Grafo {
  
  public:

    Grafo();
    Grafo(int vertices);

    void agregar_arista(int vertice1, int vertice2);
    void agregar_arista_digrafo(int vertice1, int vertice2);
    void agregar_vertice(std::set<int> colores);

    int cant_vertices() {return vecinos_.size();};
    Grafo invertir_aristas();

    std::set<int> dame_vecinos(int vertice);

    void imprimir();

    void dfs(int inicial, std::stack<int>& vertices_vistos);
    
    bool existe_arista(int vertice1, int vertice2);
    bool existe_vertice(int vertice);

  private:

    struct Vertice {
      std::set<int> colores_disponibles;
      int color;
      int num;
      bool visto;
      Vertice(std::set<int > colores, int n) : colores_disponibles(colores) , color(-1) , visto(false) , num(n) {};
    };

    std::vector<std::list<int> > vecinos_;
    std::vector<Vertice> vertices_;
};
