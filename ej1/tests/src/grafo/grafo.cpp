#include "grafo.h"

Grafo::Grafo() {
  return;
}

Grafo::Grafo(int vertices) {//Genera un grafo de tamaño vertices
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
    vertices_[vertice1].aumentar_grado();
    vertices_[vertice2].aumentar_grado();
  }
}

void Grafo::agregar_vertice(std::set<int> colores) {
  Vertice v(colores, vertices_.size());
  std::list<int> l; 
  vertices_.push_back(v);
  vecinos_.push_back(l);
}

std::set<int> Grafo::dame_colores_posibles(int vertice) {//Devuelve un set<int> los colores que puede tomar un vértice
  Vertice v = dame_vertice(vertice);
  return v.dame_colores_posibles();
}

Vertice Grafo::dame_vertice(int num) {//devuelve el vértice número num
  return vertices_[num];
}

int Grafo::dame_color(int vertice) {//devuelve el valor del color del que actualmente está pintando el vértice número vertice
  Vertice v = dame_vertice(vertice);
  return v.dame_color();
}

std::set<int> Grafo::dame_vecinos(int vertice) {//devuelve los vértices adyacentes al vértice número vertice
  assert (existe_vertice(vertice)); 

  std::set<int> vecinos;
  for (int i : vecinos_[vertice]) {
    vecinos.insert(i);
  }
  return vecinos;
}

std::set<int> Grafo::dame_vecinos_no_visitados(int vertice) {//devuelve aquellos vecinos que aún no han sido visitados 
  assert (existe_vertice(vertice));                           //(se recurre a esta función en ciertos algoritmos presentados en el trabaji práctico)

  std::set<int> vecinos;
  for (int i : vecinos_[vertice]) {
    if (dame_color(i) == -1)
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

    std::cout << "                    ";
    for (int i : vecinos_[v.dame_nombre()]) {
      std::cout << "     " << vertices_[i].dame_color();
    }
    std::cout << std::endl;

    std::cout << "}" << std::endl;
  }
}

void Grafo::impimir_color(std::string fileTestWrite){
  std::ofstream fileWrite (fileTestWrite.c_str(), std::ofstream::app);
  for(Vertice& v : vertices_) {
    fileWrite << v.dame_color() << " ";
  }
  fileWrite << std::endl;
}

void Grafo::pintar(int vertice, int color) {
  assert(existe_vertice(vertice) && vertices_[vertice].dame_colores_posibles().find(color) != vertices_[vertice].dame_colores_posibles().end());

  vertices_[vertice].pintar(color);
}

void Grafo::desvisitar_vertices(){
  for(int i=0;i<vertices_.size();i++) {
    vertices_[i].desvisitar();
  }
}

std::set<int> Grafo::conjunto_colores_vecinos(int vertice) {
  assert(existe_vertice(vertice));

  std::set<int> res;
  std::set<int> vecinos = dame_vecinos(vertice);
  for (int i : vecinos) {
    if (dame_color(i) != -1)
      res.insert(dame_color(i));
  } 
  return res;
}

void Grafo::agregar_color_a_vertice(int i, int color) {
  vertices_[i].agregar_color(color);  
}

void Grafo::eliminar_color_de_vertice(int i, int color) {
  vertices_[i].eliminar_color(color);
}

void Grafo::intercambiar_color(int v1, int v2) { //Intercambia el color de dos vértices 
  assert(existe_vertice(v1) && existe_vertice(v2));

  int swapear = vertices_[v1].dame_color();
  vertices_[v1].pintar(vertices_[v2].dame_color());
  vertices_[v2].pintar(swapear);
}

int Grafo::valor_de_intercambio(int v1, int v2) { //Devuelve el balance de conflictos si se intercambian dos colores
  assert(existe_vertice(v1) && existe_vertice(v2));

  int conf = conflictos(v1) + conflictos(v2);
  intercambiar_color(v1,v2);
  int res = conf - (conflictos(v1) + conflictos(v2));
  intercambiar_color(v1,v2);
  return res;
}

int Grafo::valor_de_pintar(int v1, int color){//
  assert(existe_vertice(v1));
  int colOrig = dame_color(v1);
  int conf = conflictos(v1);
  pintar(v1,  color);
  int res = conf - conflictos(v1);
  pintar(v1,colOrig);
  return res;
}

bool Grafo::son_colores_intercambiables(int v1, int v2) {//Determina si es posible intercambiar los colores actuales de dos nodos
  assert(existe_vertice(v1) && existe_vertice(v2));

  if(dame_color(v1) == dame_color(v2) || !existe_arista(v1,v2)) return false;

  for(int col1 : dame_colores_posibles(v1)) {
    if(col1 == dame_color(v2)) {
      for(int col2 : dame_colores_posibles(v2)) {
        if(col2 == dame_color(v1)){
          return true;
        } else {
          return false;
        }
      }
    }
  }
  return false;
}


int Grafo::conflictos(int v) {//Devuelve la cantidad de conflictos en los que cae el nodo número v estando pintado de su color actual
  assert(existe_vertice(v));

  int conflictos = 0;
  for(int i : vecinos_[v]){
    if((vertices_[i]).coincide_color(vertices_[v])) conflictos++;
  }
  return conflictos;
}

int Grafo::conflictos_totales() {//Devuelve la cantidad de conflictos existentes en el grafo actual
  int conflictos = 0;
  int cantidad_vertices = vertices_.size();

  std::queue<int> vertices;
  std::set<int> vertices_vistos;

  while (vertices_vistos.size() < cantidad_vertices) {

    bool encontre = false;
    int vertice;
    for (int i = 0 ; i < cantidad_vertices && !encontre ; ++i) {
      if (vertices_vistos.find(i) == vertices_vistos.end()) {
        vertice = i;
        encontre = true;
      }
    }

    vertices.push(vertice);
    vertices_[vertice].visitar();

    while (!vertices.empty()) {

      vertice = vertices.front();
      vertices_vistos.insert(vertice);
      vertices_[vertice].visitar();
      vertices.pop();

      for (int i : vecinos_[vertice]) {
        if (!vertices_[i].fue_visitado()) {
          vertices.push(i);
          if (dame_color(vertice) == dame_color(i))
            conflictos++;
        }
      }
    }
  }
  return conflictos;
}
