#include "grafo.h"
#include "digrafo.h"

int main() {
  Grafo grafo;
  std::set<int> color1{1,2};
  std::set<int> color2{2,1};
  std::set<int> color3{2};
  grafo.agregar_vertice(color1);
  grafo.agregar_vertice(color2);
  //grafo.agregar_vertice(color3);
  grafo.agregar_arista(0,1);
  //grafo.agregar_arista(2,0);
  //grafo.agregar_arista(2,1);
  std::cout << "<<< Imprimo Grafo original >>>" << std::endl;
  grafo.imprimir();
  std::cout << "<<< Termino Grafo original >>>" << std::endl;

  Digrafo digrafo(grafo);

  std::cout << "<<< Imprimo Digrafo original >>>" << std::endl;
  digrafo.imprimir();
  std::cout << "<<< Termino Digrafo original >>>" << std::endl;
  
  Digrafo invertido = digrafo.invertir_aristas();
  std::cout << "<<< Imprimo Digrafo invertido >>>" << std::endl;
  invertido.imprimir();
  std::cout << "<<< Termino Digrafo invertido >>>" << std::endl;
  //std::cout << "vecinos 0" << std::endl;
  //invertido.dame_vecinos(0);
  //std::cout << "vecinos 1" << std::endl;
  //invertido.dame_vecinos(1);
  //std::cout << "vecinos 2" << std::endl;
  //invertido.dame_vecinos(2);

  return 0;
}
