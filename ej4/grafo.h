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
    void agregar_vertice(std::set<int> colores);

    int cant_vertices() {return vecinos_.size();};

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

Grafo::Grafo() {
  return;
}

Grafo::Grafo(int vertices) {
  std::list<int> l; 
  std::set<int> s;
  for (int i = 0 ; i < vertices ; ++i) {
    Vertice v(s, i);
    vecinos_.push_back(l);
    vertices_.push_back(v);
  }
}

void Grafo::agregar_arista(int vertice1, int vertice2) {
  assert (existe_vertice(vertice1) && existe_vertice(vertice2));

  vecinos_[vertice1].push_back(vertice2);
  vecinos_[vertice2].push_back(vertice1);
}

void Grafo::agregar_vertice(std::set<int> colores) {
  Vertice v(colores, vertices_.size());
  std::list<int> l; 
  vertices_.push_back(v);
  vecinos_.push_back(l);
}

void Grafo::imprimir() {
  for (Vertice& v : vertices_) {
    std::cout << "{ " << std::endl; 
    std::cout << "  vertice: " << v.num << std::endl;
    std::cout << "  Posibles colores: {";
    int j = 0;
    for (int i : v.colores_disponibles) {
      if (j == 0) {
        std::cout << i;
        ++j;
      } else {
      std::cout << ", " << i;
      }
    }
    std::cout << "}" << std::endl;
    std::cout << "  Vecinos y su color";
    for (int i : vecinos_[v.num]) {
      std::cout << " --> " << i;
    }
    std::cout << std::endl;
    //for (std::list<int>::iterator it = vecinos_[i].begin() ; it != vecinos_[i].end() ; ++it) {
    //  std::cout << " --> (" << *it << ", " << vertices_[*it]).color << ")";
    //}
    //std::cout << "]"<< std::endl;

    std::cout << "                   ";
    for (int i : vecinos_[v.num]) {
      std::cout << "     " << vertices_[i].color;
    }
    std::cout << std::endl;

    std::cout << "}" << std::endl;
  }
}

bool Grafo::existe_vertice(int vertice) {
  return (vertice >= 0) && (vertice < vecinos_.size());
}

bool Grafo::existe_arista(int vertice1, int vertice2) {
  assert (existe_vertice(vertice1) && existe_vertice(vertice2));

  bool res = false; 
  for (int i : vecinos_[vertice1]) {
    if (vertice2 == i) 
      res = true;
  }
  return res; 
}

std::set<int> Grafo::dame_vecinos(int vertice) {
  assert (existe_vertice(vertice)); 

  std::set<int> vecinos;
  for (int i : vecinos_[vertice]) {
    vecinos.insert(i);
  }
  return vecinos;
}

void Grafo::dfs(int inicial, std::stack<int>& vertices_vistos) {
  assert(existe_vertice(inicial));

  std::stack<int> vertices;

  vertices.push(inicial);
  vertices_[inicial].visto = true;

  while (!vertices.empty()) {

    int vertice = vertices.top();
    vertices.pop();

    int ultimo_visto = true;
    for (int i : vecinos_[vertice]) {
      if (!vertices_[i].visto) {
        vertices_[i].visto = true;
        vertices.push(i);
        ultimo_visto = false;
      }
    }
    if (ultimo_visto)
      vertices_vistos.push(vertice);
  }
}

//int main() {
//  Grafo grafo;
//  std::set<int> color{1,2};
//  grafo.agregar_vertice(color);
//  grafo.agregar_vertice(color);
//  grafo.agregar_vertice(color);
//  grafo.agregar_arista_digrafo(1,2);
//  grafo.agregar_arista_digrafo(2,0);
//  grafo.agregar_arista_digrafo(2,1);
//  grafo.imprimir();
//  //std::cout << "vecinos 0" << std::endl;
//  //grafo.dame_vecinos(0);
//  //std::cout << "vecinos 1" << std::endl;
//  //grafo.dame_vecinos(1);
//  //std::cout << "vecinos 2" << std::endl;
//  //grafo.dame_vecinos(2);
//  
//  std::stack<int> s;
//  //grafo.dfs(0, s);
//  //for (int i = 0 ; i < s.size() ; ++i) {
//  //  std::cout << " v: " << s.top();
//  //  s.pop();
//  //}
//  //std::cout << std::endl;
//
//  grafo.dfs(2, s);
//  for (int i = 0 ; i < s.size() ; ++i) {
//    std::cout << " v: " << s.top();
//    s.pop();
//  }
//  std::cout << std::endl;
//
//
//  std::cout << "segundo grafo" << std::endl;
//
//
//
//  Grafo invertido = grafo.invertir_aristas();
//  //invertido.imprimir();
//  //std::cout << "vecinos 0" << std::endl;
//  //invertido.dame_vecinos(0);
//  //std::cout << "vecinos 1" << std::endl;
//  //invertido.dame_vecinos(1);
//  //std::cout << "vecinos 2" << std::endl;
//  //invertido.dame_vecinos(2);
//
//  return 0;
//}


//  while (vertices_vistos.size() < cant_vertices) {
//
//    int vertice;
//    bool encontre = false;
//    for (int i = 0 ; i < vertices_.size() && !encontre ; ++i) {
//      if (!vertices_[i].visto) {
//        vertice = v.num;
//        encontre = true;
//      }
//    }
//
