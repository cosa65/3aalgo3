#include "grafo.h"

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

  if (!existe_arista(vertice1, vertice2)) {
    vecinos_[vertice1].push_back(vertice2);
    vecinos_[vertice2].push_back(vertice1);
  }
}

void Grafo::agregar_vertice(std::set<int> colores) {
  Vertice v(colores, vertices_.size());
  std::list<int> l; 
  vertices_.push_back(v);
  vecinos_.push_back(l);
}

std::set<int> Grafo::dame_colores_posibles(int vertice) {
  Vertice v = dame_vertice(vertice);
  return v.dame_colores_posibles();
}

Vertice Grafo::dame_vertice(int num) {
  return vertices_[num];
}

int Grafo::dame_color(int vertice) {
  Vertice v = dame_vertice(vertice);
  return v.dame_color();
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
  vertices_[inicial].visitar();

  while (!vertices.empty()) {

    int vertice = vertices.top();
    vertices.pop();

    int ultimo_visto = true;
    for (int i : vecinos_[vertice]) {
      if (!vertices_[i].fue_visitado()) {
        vertices_[i].visitar();
        vertices.push(i);
        ultimo_visto = false;
      }
    }
    if (ultimo_visto)
      vertices_vistos.push(vertice);
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

void Grafo::imprimir() {
  for (Vertice& v : vertices_) {
    std::cout << "{ " << std::endl; 
    std::cout << "  vertice: " << v.dame_nombre() << std::endl;
    std::cout << "  Posibles colores: {";
    int j = 0;
    for (int i : v.dame_colores_posibles()) {
      if (j == 0) {
        std::cout << i;
        ++j;
      } else {
      std::cout << ", " << i;
      }
    }
    std::cout << "}" << std::endl;
    std::cout << "  color: " << v.dame_color() << std::endl;
    std::cout << "  Vecinos y su color";
    for (int i : vecinos_[v.dame_nombre()]) {
      std::cout << " --> " << i;
    }
    std::cout << std::endl;
    //for (std::list<int>::iterator it = vecinos_[i].begin() ; it != vecinos_[i].end() ; ++it) {
    //  std::cout << " --> (" << *it << ", " << vertices_[*it]).color << ")";
    //}
    //std::cout << "]"<< std::endl;

    std::cout << "                   ";
    for (int i : vecinos_[v.dame_nombre()]) {
      std::cout << "     " << vertices_[i].dame_color();
    }
    std::cout << std::endl;

    std::cout << "}" << std::endl;
  }
}

void Grafo::pintar(int vertice, int color) {
  vertices_[vertice].pintar(color);
}
