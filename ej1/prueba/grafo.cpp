#include "grafo.h"
#include "digrafo.h"
#include "utils.h"

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

std::set<int> Grafo::dame_colores_posibles(int vertice) {
  return vertices_[vertice].colores_disponibles;
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

// void Grafo::dfs(int inicial, std::stack<int>& vertices_vistos) {
//   assert(existe_vertice(inicial));

//   std::stack<int> vertices;

//   vertices.push(inicial);
//   vertices_[inicial].visto = true;

//   while (!vertices.empty()) {

//     int vertice = vertices.top();
//     vertices.pop();

//     int ultimo_visto = true;
//     for (int i : vecinos_[vertice]) {
//       if (!vertices_[i].visto) {
//         vertices_[i].visto = true;
//         vertices.push(i);
//         ultimo_visto = false;
//       }
//     }
//     if (ultimo_visto)
//       vertices_vistos.push(vertice);
//   }
// }




vector<bool> Grafo::buscar_contradiccion(list<list<int>> cfc, Digrafo digrafo)
{
  // Vector que indica el valor de verdad de todos los nodos de cada cfc
  // vector<bool> vooleanos(cfc.size());
  // fill(vooleanos.begin(), vooleanos.end(), false);
  // int count = 0;

  // Itero sobre las componentes  
  for (list<int>& l: cfc)
  {
    list<int>::iterator it = l.begin();

    // Itero sobre los nodos de cada componente. Freno si ya puse esa componente en true.
    while (it != l.end() && vooleanos[count] != true)
    {
      vooleanos[count] = digrafo.dfs3(*it, vooleanos);
      ++it;
    }
    ++count; 
  }

  return vooleanos;

}

list<int> Grafo::ListColoring()
{
  // Creo el digrafo expandido a 4 vértices por cada uno en el original
  Digrafo digrafo(*this);
  // Busco componentes fuertemente conexas
  list<list<int>> cfc = digrafo.Kosaraju();

  // Chequeo si existe solución (si no existen contradicciones dentro de una misma cfc)
  vector<bool> colores = buscar_contradiccion(cfc, digrafo);
  
  cout << "Coloreo:" << endl;
  int count = 0;
  for (list<list<int>>::iterator it = cfc.begin(); it != cfc.end(); ++it)
  {
    for (int d: *it)
    {
      cout.setf(ios::boolalpha);
      cout << "La componente del nodo " << d << " es " << colores[count] << ". Luego para el nodo " << d << " vale " << digrafo.vertices_[d].color << " " << !(digrafo.vertices_[d].valor_de_verdad ^ colores[count]);
      cout << endl;
    }
    cout << endl;
  }


  list<int> l;
  return l;

}
