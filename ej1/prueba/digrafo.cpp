#include "digrafo.h"
#include <iterator>
#include <stack>
#include <queue>
#include <ostream>
#include "utils.h"

Digrafo::Digrafo() {
  return;
}

Digrafo::Digrafo(Grafo& g) {
  int cant_vertices = g.cant_vertices();

  for (int i = 0 ; i < cant_vertices ; ++i) {
    // Encuentro los colores del vértice en el grafo inicial
    set<int> colores = g.dame_colores_posibles(i);

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
    set<int> vecinos = g.dame_vecinos(i);
    for (int v : vecinos) {
      set<int> colores_i = g.dame_colores_posibles(i);
      set<int> colores_v = g.dame_colores_posibles(v);

      set<int> interseccion;
      set<int>::iterator it = interseccion.begin();

      // Calculo la interseccion entre los colores de los dos 
      // vertices
      set_intersection(colores_i.begin(), colores_i.end(), 
                            colores_v.begin(), colores_v.end(), 
                            inserter(interseccion, it)); 

      // Caso tienen un color en comun
      if (interseccion.size() == 1) {
        agregar_arista_1_color(interseccion, i, v);
      }

      // Caso tienen dos colores en comun
      if (interseccion.size() == 2) {
        agregar_arista_2_colores(interseccion, i, v);
      }
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
  Vertice v(color, num, id, valor_de_verdad);
  list<int> l; 
  vertices_.push_back(v);
  vecinos_.push_back(l);
  return id;
}

void Digrafo::imprimir() {
  cout.setf(ios::boolalpha); // http://stackoverflow.com/questions/8261674/c-bool-returns-0-1-instead-of-true-false
  for (Vertice& v : vertices_) {
    cout << "{ " << endl; 
    cout << "  vertice:         " << v.num << endl;
    cout << "  id     :         " << v.id << endl;
    cout << "  color  :         " << v.color << endl;
    cout << "  valor de verdad: " << v.valor_de_verdad << endl;

    cout << "  Vecinos y su color";
    for (int i : vecinos_[v.id]) {
      cout << " --> (" << vertices_[i].id << " ," << vertices_[i].num;
      if (vertices_[i].valor_de_verdad) {
        cout << ", True)";
      } else {
        cout << ", False)"; 
      }
    }
    cout << endl;

    cout << "                 ";
    for (int i : vecinos_[v.id]) {
      cout << "              " << vertices_[i].color;
    }
    cout << endl;

    cout << "}" << endl;
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

set<int> Digrafo::dame_vecinos(int vertice) {
  assert (existe_vertice(vertice)); 

  set<int> vecinos;
  for (int i : vecinos_[vertice]) {
    vecinos.insert(i);
  }
  return vecinos;
}

Digrafo Digrafo::invertir_aristas() {
  Digrafo invertido;

  for (Vertice& v : vertices_)
    invertido.agregar_vertice(v.color, v.num, v.valor_de_verdad);

  for (Vertice& v : vertices_) {
    for (int i : vecinos_[v.id]) {
      invertido.agregar_arista(i, v.id);
    }
  }
  return invertido;
}


void Digrafo::dfs( vector<bool>& visitados, stack<int>& finish_time) // El parámetro visitados es reemplazado por un putero al primer elemento del array ;). Para evitar el cambio implícito, usar una referencia. Lo cambié por un vector, el comentario queda anuado.
{
	for (int i = 0; i < vertices_.size(); ++i)
		if (!visitados[i])
			recorrer(i, visitados, finish_time);
}

void Digrafo::recorrer(int i, vector<bool>& visitados, stack<int>& finish_time)
{
	visitados[i] = true;
	for (int v: vecinos_[i])
		if (!visitados[v]) 
			recorrer(v, visitados, finish_time);

	// A esta altura, todos los alcanzables desde i están visitados
	finish_time.push(i);
}

list<list<int>> Digrafo::dfs2( vector<bool>& visitados, stack<int>& finish_time)
{
	// Armo lista de componentes fuertemente conexas en orden topológico. De esto último no estoy seguro.
	list<list<int>>* cfc = new list<list<int>>;

	while (!finish_time.empty())
	{
		int i = finish_time.top();
		finish_time.pop();

		if (!visitados[i])
		{
			list<int>* componente = new list<int>;
			cfc->push_back( recorrer2(i, visitados, *componente) );
		}
	}
	return *cfc;
}

list<int> Digrafo::recorrer2(int i, vector<bool>& visitados, list<int>& componente)
{
	visitados[i] = true;
	componente.push_back(i);

	for (int v: vecinos_[i])
		if (!visitados[v])
			recorrer2(v, visitados, componente);

	return componente;
}

// Algoritmo de Kosaraju, para calcular componentes fuertemente conexas
list<list<int>> Digrafo::Kosaraju()
{
	// Creo vector de visitados y lo inicializo. Al principio no hay visitados
	vector<bool> visitados(vertices_.size());
	fill(visitados.begin(), visitados.end(), false);
  
  // Primer DFS: me armo un stack de acuerdo al orden en que visito cada nodo
  stack<int> finish_time;
  dfs( visitados, finish_time );

	// Busco el grafo Invertido
	Digrafo invertido = invertir_aristas();

	// Vuelvo a inicializar el vector para el segundo dfs
	fill(visitados.begin(), visitados.end(), false);

  // Segundo DFS: recorro el stack que me armé
  return invertido.dfs2( visitados, finish_time );
}



/////////////////////////////////////////////////////////////////////////


// list<Digrafo> Digrafo::Kosaraju_poco_amistoso( int init )
// {
//   stack<int> finish_time;
//   set<int> visitados; 

//   visitados.insert(init);
//   vertices_[init].visto = true;

//   while ( visitados.size() < vertices_.size() )
//   {
//     for ( auto& noda: vertices_)
//     {
//       if ( !noda.visitado )
//       {

//         while (!visitados.empty())
//         {

//           int vertice = visitados.top();
//           int ultimo_visto = true;

//           for (auto nodo : vertices_[vecinos_[vertice]])
//           {
//             if (!nodo.visto)
//             {
//               nodo.visto = true;
//               visitados.push(nodo);
//               ultimo_visto = false;
//             }
//           }

//           if (ultimo_visto)
//           {
//             finish_time.push(visitados.top());
//             visitados.pop();
//           }

//         }
        
//       }
//     }
//   }

//   Digrafo complemento = invertir_aristas();

//   list<Digrafo> cfc = new list<Digrafo>;

//   while (!finish_time.empty())
//   {

//     int vertice = finish_time.top();
//     finish_time.pop();

//     if (!vertices_[vertice].visto)
//     {
//       cfc.add( dfs(vertice) );
//     }

// }

// Funciones privadas

void Digrafo::expandir_vertice_1_color(set<int> colores, int vertice) {
  set<int>::iterator it = colores.begin();
  int color = *it;

  agregar_vertice(color, vertice, true);
  agregar_vertice(color, vertice, false);

  // Creo dos vértices para el nodo inicial, su color 
  // y su negación

  agregar_vertice(color, vertice, true);
  agregar_vertice(color, vertice, false);

  // Creo dos vértices "fantasmas" ya que necesito poder 
  // volver a acceder a los vértices de manera relativa 
  // para poder unirlos mediante sus aristas
  // De esta manera me queda que si quiero conectar V_3 
  // con V_5, V_3 empieza en la posición 3*4=12 del vector 
  // de vértices y V_5 en 5*4=20.
  // De esta manera se puede buscar fácil la ubicación del vértice 
  // original y, a partir de esa posición, tiene 4 posiciones 
  // fijas para sus nuevos vértices creados.

  // Si tenía un solo color no tiene ningun conexión entre 
  // sus nuevos vértices (??????????)
}

void Digrafo::expandir_vertice_2_colores(set<int> colores, int vertice) {
  set<int>::iterator it = colores.begin();
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

void Digrafo::agregar_arista_1_color(set<int> interseccion, int v1, int v2) {
  set<int>::iterator it = interseccion.begin();
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

void Digrafo::agregar_arista_2_colores(set<int> interseccion, int v1, int v2) {
  set<int>::iterator it = interseccion.begin();
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

int Digrafo::dame_posicion_vertice(int vertice, int color, bool valor_de_verdad) {
  int posicion_inicial = vertice * 4;
  int posicion_final;
  for (int i = 0 ; i < 4 ; ++i) {
    int pos = posicion_inicial + i;
    if (vertices_[pos].color == color && vertices_[pos].valor_de_verdad == valor_de_verdad)
      posicion_final = pos;
  }
  return posicion_final;
}


