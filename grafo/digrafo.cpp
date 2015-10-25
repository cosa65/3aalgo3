#include "grafo.h"

Digrafo::Digrafo() {
  return;
}

Digrafo::Digrafo(Grafo g) {


}

void Digrafo::agregar_arista(int vertice1, int vertice2) {
  assert (existe_vertice(vertice1) && existe_vertice(vertice2));

  vecinos_[vertice1].push_back(vertice2);
}

void Digrafo::agregar_vertice(int num, bool valor_de_verdad) {
  Vertice v(num, vertices_.size(), valor_de_verdad);
  std::list<int> l; 
  vertices_.push_back(v);
  vecinos_.push_back(l);
}

void Digrafo::imprimir() {
  for (Vertice& v : vertices_) {
    std::cout << "{ " << std::endl; 
    std::cout << "  vertice:         " << v.num << std::endl;
    std::cout << "  id     :         " << v.id << std::endl;
    std::cout << "  color  :         " << v.valor_de_verdad << std::endl;
    std::cout << "  valor de verdad: " << v.valor_de_verdad << std::endl;

    std::cout << "  Vecinos y su color";
    for (int i : vecinos_[v.id]) {
      std::cout << " --> (" << vertices_[i].num;
      if (vertices_[i].valor_de_verdad) {
        std::cout << ", True)";
      } else {
        std::cout << ", False)"; 
      }
    }
    std::cout << std::endl;

    std::cout << "                   ";
    for (int i : vecinos_[v.id]) {
      std::cout << "     " << vertices_[i].color;
    }
    std::cout << std::endl;

    std::cout << "}" << std::endl;
  }
}

bool Digrafo::existe_vertice(int vertice) {
  return (vertice >= 0) && (vertice < vecinos_.size());
}

bool Digrafo::existe_arista(int vertice1, int vertice2) {
  assert (existe_vertice(vertice1) && existe_vertice(vertice2));

  bool res = false; 
  for (int i : vecinos_[vertice1]) {
    if (vertice2 == i) 
      res = true;
  }
  return res; 
}

std::set<int> Digrafo::dame_vecinos(int vertice) {
  assert (existe_vertice(vertice)); 

  std::set<int> vecinos;
  for (int i : vecinos_[vertice]) {
    vecinos.insert(i);
  }
  return vecinos;
}

Digrafo Digrafo::invertir_aristas() {
  Digrafo invertido;

  for (Vertice& v : vertices_)
    invertido.agregar_vertice(v.num, v.valor_de_verdad);

  for (Vertice& v : vertices_) {
    for (int i : vecinos_[v.id]) {
      invertido.agregar_arista_digrafo(i, v.id);
    }
  }
  return invertido;
}

void Digrafo::dfs(int inicial, std::stack<int>& vertices_vistos) {
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

std::list<Digrafo> Digrafo::Kosaraju( int init )
{
  std::stack<int> finish_time;
  std::set<int> visitados; 

  visitados.insert(init);
  vertices_[init].visto = true;

  while ( visitados.size() < vertices_.size() )
  {
    for ( auto& nodo: vertices_)
    {
      if ( !nodo.visitado )
      {

        while (!visitados.empty())
        {

          int vertice = visitados.top();
          int ultimo_visto = true;

          for (auto nodo : vertices_[vecinos_[vertice]])
          {
            if (!nodo.visto)
            {
              nodo.visto = true;
              visitados.push(nodo);
              ultimo_visto = false;
            }
          }

          if (ultimo_visto)
          {
            finish_time.push(visitados.top());
            visitados.pop();
          }

        }
        
      }
    }
  }

  Digrafo complemento = invertir_aristas();

  while (!visitados.empty())
  {
    
  }

}




//int main() {
//  Digrafo grafo;
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
//  Digrafo invertido = grafo.invertir_aristas();
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
