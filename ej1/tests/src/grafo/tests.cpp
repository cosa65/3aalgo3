#include "grafo.h"
#include "digrafo.h"

void test_vertice_con_un_color() {
  std::cout << "<<< TEST VERTICE UN COLOR >>>" << std::endl;
  Grafo grafo;
  std::set<int> color{0};
  grafo.agregar_vertice(color);
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
} 

void test_vertice_con_dos_colores() {
  std::cout << "<<< TEST VERTICE DOS COLORES >>>" << std::endl;
  Grafo grafo;
  std::set<int> color{0,1};
  grafo.agregar_vertice(color);
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
} 

void test_arista_entre_vertice_interseccion_un_color() {
  std::cout << "<<< TEST INTERSECCION UN COLOR >>>" << std::endl;
  Grafo grafo;
  std::set<int> color{0};
  grafo.agregar_vertice(color);
  grafo.agregar_vertice(color);
  grafo.agregar_arista(0,1);
  std::cout << "<<< Imprimo Grafo original >>>" << std::endl;
  grafo.imprimir();
  std::cout << "<<< Termino Grafo original >>>" << std::endl;

  Digrafo digrafo(grafo);

  std::cout << "<<< Imprimo Digrafo original >>>" << std::endl;
  digrafo.imprimir_solo_vecinos();
  std::cout << "<<< Termino Digrafo original >>>" << std::endl;
  
  Digrafo invertido = digrafo.invertir_aristas();
  std::cout << "<<< Imprimo Digrafo invertido >>>" << std::endl;
  invertido.imprimir_solo_vecinos();
  std::cout << "<<< Termino Digrafo invertido >>>" << std::endl;
} 

void test_arista_entre_vertice_interseccion_dos_colores() {
  std::cout << "<<< TEST INTERSECCION DOS COLORES >>>" << std::endl;
  Grafo grafo;
  std::set<int> color1{0,1};
  std::set<int> color2{0,1};
  grafo.agregar_vertice(color1);
  grafo.agregar_vertice(color2);
  grafo.agregar_arista(0,1);
  std::cout << "<<< Imprimo Grafo original >>>" << std::endl;
  grafo.imprimir();
  std::cout << "<<< Termino Grafo original >>>" << std::endl;

  Digrafo digrafo(grafo);

  std::cout << "<<< Imprimo Digrafo original >>>" << std::endl;
  digrafo.imprimir_solo_vecinos();
  std::cout << "<<< Termino Digrafo original >>>" << std::endl;
  
  Digrafo invertido = digrafo.invertir_aristas();
  std::cout << "<<< Imprimo Digrafo invertido >>>" << std::endl;
  invertido.imprimir_solo_vecinos();
  std::cout << "<<< Termino Digrafo invertido >>>" << std::endl;
} 

void test_arista_entre_vertice_interseccion_nula() {
  std::cout << "<<< TEST INTERSECCION NULA >>>" << std::endl;
  Grafo grafo;
  std::set<int> color1{0};
  std::set<int> color2{1};
  grafo.agregar_vertice(color1);
  grafo.agregar_vertice(color2);
  grafo.agregar_arista(0,1);
  std::cout << "<<< Imprimo Grafo original >>>" << std::endl;
  grafo.imprimir();
  std::cout << "<<< Termino Grafo original >>>" << std::endl;

  Digrafo digrafo(grafo);

  std::cout << "<<< Imprimo Digrafo original >>>" << std::endl;
  digrafo.imprimir_solo_vecinos();
  std::cout << "<<< Termino Digrafo original >>>" << std::endl;
  
  Digrafo invertido = digrafo.invertir_aristas();
  std::cout << "<<< Imprimo Digrafo invertido >>>" << std::endl;
  invertido.imprimir_solo_vecinos();
  std::cout << "<<< Termino Digrafo invertido >>>" << std::endl;
} 

int main() {
  //test_vertice_con_un_color();
  //test_vertice_con_dos_colores();
  //test_arista_entre_vertice_interseccion_un_color();
  //test_arista_entre_vertice_interseccion_dos_colores();
  //test_arista_entre_vertice_interseccion_nula();
 
  return 0;
}
