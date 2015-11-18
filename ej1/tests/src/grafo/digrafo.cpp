#include "digrafo.h"

Digrafo::Digrafo() {
  return;
}

Digrafo::Digrafo(Grafo& g) {
  int cant_vertices = g.cant_vertices();

  for (int i = 0 ; i < cant_vertices ; ++i) {
    // Encuentro los colores del vértice en el grafo inicial
    std::set<int> colores = g.dame_colores_posibles(i);

    // Caso vértice tiene 2 colores
    if (colores.size() == 2) {
      expandir_vertice_2_colores(colores, i);
    }

    // Caso vértice tiene un solo color
    if (colores.size() == 1) {
      expandir_vertice_1_color(colores, i);
    }
  }

  for (int i = 0 ; i < cant_vertices ; ++i) {
    std::set<int> vecinos = g.dame_vecinos(i);
    for (int v : vecinos) {
      std::set<int> colores_i = g.dame_colores_posibles(i);
      std::set<int> colores_v = g.dame_colores_posibles(v);


      std::set<int> interseccion;
      std::set<int>::iterator it = interseccion.begin();

      // Calculo la interseccion entre los colores de los dos 
      // vertices
      std::set_intersection(colores_i.begin(), colores_i.end(), 
                            colores_v.begin(), colores_v.end(), 
                            std::inserter(interseccion, it)); 

      // Caso tienen un color en comun
      if (interseccion.size() == 1) {
        agregar_arista_1_color(interseccion, i, v);
      }

      // Caso tienen dos colores en comun
      if (interseccion.size() == 2) {
        agregar_arista_2_colores(interseccion, i, v);
      }

      // Si no tienen colores en comun esta todo bien (Y)
    }
  }
}

void Digrafo::agregar_arista(int vertice1, int vertice2) {
  assert (existe_vertice(vertice1) && existe_vertice(vertice2));

  if (!existe_arista(vertice1, vertice2))
    vecinos_[vertice1].push_back(vertice2);
}

int Digrafo::agregar_vertice(int color, int num, bool valor_de_verdad) {
  int id = vertices_.size();
  Vertice_digrafo v(color, num, id, valor_de_verdad);
  std::list<int> l; 
  vertices_.push_back(v);
  vecinos_.push_back(l);
  return id;
}

void Digrafo::imprimir() {
  for (Vertice_digrafo& v : vertices_) {
    std::cout << "{ " << std::endl; 
    std::cout << "  vertice:         " << v.dame_nombre() << std::endl;
    std::cout << "  id     :         " << v.dame_id() << std::endl;
    std::cout << "  color  :         " << v.dame_color() << std::endl;
    if (v.dame_valor_de_verdad()) {
      std::cout << "  valor de verdad: " << "True" << std::endl;
    } else {
      std::cout << "  valor de verdad: " << "False" << std::endl;
    }

    std::cout << "  Vecinos y su color";
    for (int i : vecinos_[v.dame_id()]) {
      std::cout << " --> (" << vertices_[i].dame_nombre();
      if (vertices_[i].dame_valor_de_verdad()) {
        std::cout << ", True)";
      } else {
        std::cout << ", False)"; 
      }
    }
    std::cout << std::endl;

    std::cout << "                 ";
    for (int i : vecinos_[v.dame_id()]) {
      std::cout << "              " << vertices_[i].dame_color();
    }
    std::cout << std::endl;

    std::cout << "}" << std::endl;
  }
}

void Digrafo::imprimir_solo_vecinos() {
  for (Vertice_digrafo& v : vertices_) {
    if (vecinos_[v.dame_id()].size() != 0) {
    std::cout << "{ " << std::endl; 
    std::cout << "  vertice:         " << v.dame_nombre() << std::endl;
    std::cout << "  id     :         " << v.dame_id() << std::endl;
    std::cout << "  color  :         " << v.dame_color() << std::endl;
    if (v.dame_valor_de_verdad()) {
      std::cout << "  valor de verdad: " << "True" << std::endl;
    } else {
      std::cout << "  valor de verdad: " << "False" << std::endl;
    }

    std::cout << "  Vecinos y su color";
    for (int i : vecinos_[v.dame_id()]) {
      std::cout << " --> (" << vertices_[i].dame_nombre();
      if (vertices_[i].dame_valor_de_verdad()) {
        std::cout << ", True)";
      } else {
        std::cout << ", False)"; 
      }
    }
    std::cout << std::endl;

    std::cout << "                 ";
    for (int i : vecinos_[v.dame_id()]) {
      std::cout << "              " << vertices_[i].dame_color();
    }
    std::cout << std::endl;

    std::cout << "}" << std::endl;
    }
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

int Digrafo::dame_contrario(int vertice) {
  Vertice_digrafo v = dame_vertice(vertice);
  int contrario;

  // Si es el true del nodo, el contrario esta 1 adelante
  if (v.dame_valor_de_verdad()) {
    contrario = vertices_[vertice+1].dame_id();
  } else {
    // Si es el falso, el verdadero esta 1 detras
    contrario = vertices_[vertice-1].dame_id();
  }
  return contrario;
}

// int dame_valor_de_verdad()
// {
  
// }

Digrafo Digrafo::invertir_aristas() {
  Digrafo invertido;

  for (Vertice_digrafo& v : vertices_)
    invertido.agregar_vertice(v.dame_color(), v.dame_nombre(), v.dame_valor_de_verdad());

  for (Vertice_digrafo& v : vertices_) {
    for (int i : vecinos_[v.dame_id()]) {
      invertido.agregar_arista(i, v.dame_id());
    }
  }
  return invertido;
}

bool Digrafo::son_contrarias(int id1, int id2) {
  Vertice_digrafo v1 = dame_vertice(id1);
  Vertice_digrafo v2 = dame_vertice(id2);
  return v1.dame_nombre() == v2.dame_nombre() && v1.dame_color() == v2.dame_color() && v1.dame_valor_de_verdad() == v2.dame_valor_de_verdad();
}

//void Digrafo::dfs(int inicial, std::stack<int>& vertices_vistos) {
//  assert(existe_vertice(inicial));
//
//  std::stack<int> vertices;
//
//  vertices.push(inicial);
//  vertices_[inicial].visitar();
//
//  while (!vertices.empty()) {
//
//    int vertice = vertices.top();
//    vertices.pop();
//
//    int ultimo_visto = true;
//    for (int i : vecinos_[vertice]) {
//      if (!vertices_[i].fue_visitado()) {
//        vertices_[i].visitar();
//        vertices.push(i);
//        ultimo_visto = false;
//      }
//    }
//    if (ultimo_visto)
//      vertices_vistos.push(vertice);
//  }
//}




// Algoritmo de Kosaraju, para calcular componentes fuertemente conexas
std::list<std::list<int>> Digrafo::Kosaraju()
{
  // Creo vector de visitados y lo inicializo. Al principio no hay visitados
  std::vector<bool> visitados(vertices_.size());
  fill(visitados.begin(), visitados.end(), false);
  
  // Primer DFS: me armo un stack de acuerdo al orden en que visito cada nodo
  std::stack<int> finish_time;
  dfs( visitados, finish_time );

  // Busco el grafo Invertido
  Digrafo invertido = invertir_aristas();

  // Vuelvo a inicializar el vector para el segundo dfs
  fill(visitados.begin(), visitados.end(), false);

  // Segundo DFS: recorro el stack que me armé
  return invertido.dfs2( visitados, finish_time );
}




///////////////////////////////////////////////////////////////////////////////////
// Funciones privadas

void Digrafo::expandir_vertice_1_color(std::set<int> colores, int vertice) {
  std::set<int>::iterator it = colores.begin();
  int color = *it;

  // Creo dos vértices para el nodo inicial, su color 
  // y su negación
  int id1 = agregar_vertice(color, vertice, true);
  int id2 = agregar_vertice(color, vertice, false);

  // Creo dos vértices "fantasmas" ya que necesito poder 
  // volver a acceder a los vértices de manera relativa 
  // para poder unirlos mediante sus aristas
  // De esta manera me queda que si quiero conectar V_3 
  // con V_5, V_3 empieza en la posición 3*4=12 del vector 
  // de vértices y V_5 en 5*4=20.
  // De esta manera se puede buscar fácil la ubicación del vértice 
  // original y, a partir de esa posición, tiene 4 posiciones 
  // fijas para sus nuevos vértices creados.
  agregar_vertice(color, vertice, true);
  agregar_vertice(color, vertice, false);

  // Si tiene un solo color me tengo que asegurar 
  // que valga ese color en ese vértice.
  // Por esa razon, ¬Rojo -> Rojo
  // ya que falso implicando es verdadero
  // y quiero que el vertice tenga color rojo
  agregar_arista(id2, id1);
}

void Digrafo::expandir_vertice_2_colores(std::set<int> colores, int vertice) {
  std::set<int>::iterator it = colores.begin();
  int color1 = *it;
  ++it;
  int color2 = *it;
  
  // Como estamos en 2ListColoring, pueden tener 2 colores
  // como máximo
  
  int id1 = agregar_vertice(color1, vertice, true);
  int id2 = agregar_vertice(color1, vertice, false);

  int id3 = agregar_vertice(color2, vertice, true);
  int id4 = agregar_vertice(color2, vertice, false);

  // Si tenía dos colores le creo 4 vértices al nodo inicial
  // Por cada color, su negación
  // Necesito el "id" que vendría a ser la posición del vector 
  // de vértices para saber como conectarlos entre sí

  // Los conecto
  // V_0_rojo -> ¬V_0_azul
  agregar_arista(id1, id4);

  // ¬V_0_rojo -> V_0_azul
  agregar_arista(id2, id3);

  // ¬V_0_azul -> V_0_rojo
  agregar_arista(id4, id1);

  // V_0_azul -> ¬V_0_rojo
  agregar_arista(id3, id2);
}

void Digrafo::agregar_arista_1_color(std::set<int> interseccion, int v1, int v2) {
  std::set<int>::iterator it = interseccion.begin();
  int color = *it;

  int pos_v1_true = dame_posicion_vertice(v1, color, true);
  int pos_v1_false = dame_posicion_vertice(v1, color, false);

  int pos_v2_true = dame_posicion_vertice(v2, color, true);
  int pos_v2_false = dame_posicion_vertice(v2, color, false);

  // V_0_rojo -> ¬V_1_rojo
  agregar_arista(pos_v1_true, pos_v2_false);

  // V_1_rojo -> ¬V_0_rojo
  agregar_arista(pos_v2_true, pos_v1_false);
}

void Digrafo::agregar_arista_2_colores(std::set<int> interseccion, int v1, int v2) {
  std::set<int>::iterator it = interseccion.begin();
  int color1 = *it;
  ++it;
  int color2 = *it;

  int pos_v1_true_1 = dame_posicion_vertice(v1, color1, true);
  int pos_v1_false_1 = dame_posicion_vertice(v1, color1, false);

  int pos_v1_true_2 = dame_posicion_vertice(v1, color2, true);
  int pos_v1_false_2 = dame_posicion_vertice(v1, color2, false);

  int pos_v2_true_1 = dame_posicion_vertice(v2, color1, true);
  int pos_v2_false_1 = dame_posicion_vertice(v2, color1, false);

  int pos_v2_true_2 = dame_posicion_vertice(v2, color2, true);
  int pos_v2_false_2 = dame_posicion_vertice(v2, color2, false);


  // V_0_rojo -> ¬V_1_rojo
  agregar_arista(pos_v1_true_1, pos_v2_false_1);

  // V_1_rojo -> ¬V_0_rojo
  agregar_arista(pos_v2_true_1, pos_v1_false_1);

  // V_0_azul -> ¬V_1_azul_
  agregar_arista(pos_v1_true_2, pos_v2_false_2);

  // V_1_azul -> ¬V_0_azul
  agregar_arista(pos_v2_true_2, pos_v1_false_2);
}

Vertice_digrafo Digrafo::dame_vertice(int vertice) {
  return vertices_[vertice];
}

int Digrafo::dame_posicion_vertice(int vertice, int color, bool valor_de_verdad) {
  int posicion_inicial = vertice * 4;
  int posicion_final;
  bool encontre = false;
  for (int i = 0 ; i < 4 && !encontre; ++i) {
    int pos = posicion_inicial + i;
    if (vertices_[pos].dame_color() == color && vertices_[pos].dame_valor_de_verdad() == valor_de_verdad) {
      posicion_final = pos;
      encontre = true;
    }
  }
  return posicion_final;
}



void Digrafo::dfs( std::vector<bool>& visitados, std::stack<int>& finish_time) // El parámetro visitados es reemplazado por un putero al primer elemento del array ;). Para evitar el cambio implícito, usar una referencia. Lo cambié por un std::vector, el comentario queda anuado.
{
  for (int i = 0; i < vertices_.size(); ++i)
    if (!visitados[i])
      recorrer(i, visitados, finish_time);
}

void Digrafo::recorrer(int i, std::vector<bool>& visitados, std::stack<int>& finish_time)
{
  visitados[i] = true;
  for (int v: vecinos_[i])
    if (!visitados[v]) 
      recorrer(v, visitados, finish_time);

  // A esta altura, todos los alcanzables desde i están visitados
  finish_time.push(i);
}

std::list<std::list<int>> Digrafo::dfs2( std::vector<bool>& visitados, std::stack<int>& finish_time)
{
  // Armo lista de componentes fuertemente conexas en orden topológico. De esto último no estoy seguro.
  std::list<std::list<int>> cfc;

  while (!finish_time.empty())
  {
    int i = finish_time.top();
    finish_time.pop();

    if (!visitados[i])
    {
      std::list<int> componente;
      cfc.push_back( recorrer2(i, visitados, componente) );
    }
  }
  return cfc;
}

std::list<int> Digrafo::recorrer2(int i, std::vector<bool>& visitados, std::list<int>& componente)
{
  visitados[i] = true;
  componente.push_back(i);

  for (int v: vecinos_[i])
    if (!visitados[v])
      recorrer2(v, visitados, componente);

  return componente;
}

