#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/time.h>

#include <queue>
#include <map>

#include "../../grafo/grafo.h"


timeval start, end;
double acum = 0;

void init_time() {
  gettimeofday(&start, NULL);
}

double get_time() {
  gettimeofday(&end, NULL);
  return (1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec))/1000000.0;
}

//////////////////////////////////////////////////////////Goloso///////////////////////////////////////////////////////////

int dame_el_de_maxima_aparicion(std::map<int, int>& colores_usados) {
  int max = 0;
  int color;
  for (std::pair<const int, int>& par : colores_usados) {
    if (par.second > max) {
      max = par.second;
      color = par.first;
    }
  }
  for (std::pair<const int, int>& par : colores_usados) {
    if (par.first == color)
      par.second = 0;
  }
  if (max == 0) 
    color = -1;
  return color;
}

double pintar_vertices(Grafo& g, 	std::priority_queue<Vertice, std::vector<Vertice>, std::greater<Vertice> > vertices) {
  init_time();
  int vistos = 0;
  int cant_vertices = g.cant_vertices();
  // Creo vector para obtener el maximo
  for (int i = 0 ; i < cant_vertices ; ++i) {
    vertices.push(g.dame_vertice(i));
  }

  // Recorro todos los vertices del grafo
  while (vistos < cant_vertices) {
    //std::cout << "vistos: " << vistos << " cant_vertices " << cant_vertices << std::endl;

    // Hallar el vertice de mayor grado
    Vertice vertice = vertices.top();
    //std::cout << "vertice: " << vertice.dame_nombre() << std::endl;
    vertices.pop();
    std::set<int> colores_vertice = vertice.dame_colores_posibles(); 

    // Creo un diccionario para ver cual es el color 
    // que mas usan los vecinos 
    // y otro para ver cual es el que mas se repite entre los 
    // colores posibles de los vecinos
    std::map<int, int> colores_usados;
    std::map<int, int> colores_posibles;
    for (int color : colores_vertice) {
      colores_usados.insert(std::pair<int, int> (color, 0));
      colores_posibles.insert(std::pair<int, int> (color, 0));
    }

    // recorro los vecinos del maximo
    std::set<int> vecinos = g.dame_vecinos(vertice.dame_nombre());
    for (int v : vecinos) {

      int color_vecino = g.dame_color(v);
      if (color_vecino != -1) { // Ya esta pintado el vecino y no puedo usar ese color
        // Me fijo si el vertice sobre el cual estoy parado tiene a ese 
        // color como disponible y de ser así lo aumento en el diccionario de colores
        std::set<int>::iterator it = colores_vertice.find(color_vecino);
        if (it != colores_vertice.end())
          colores_usados[color_vecino]++;

      } else {
        // Si no esta pintado el vecino
        std::set<int> colores_vecino = g.dame_colores_posibles(v);

        // Por cada color que entre en conflicto sumo 1 en el diccionario
        for (int color : colores_vecino) {
          std::set<int>::iterator it = colores_vertice.find(color);
          if (it != colores_vertice.end()) {
            colores_posibles[color]++;
          }
        }
      }
    }
    // Tengo dos diccionarios que determinan para cada color que tiene el vértice
    // la cantidad de vecinos que tienen ese color pintado
    // y la cantidad de vecinos que tienen ese color como posibilidad
    
    // Recorro el diccionario de colores usados por mis vecinos 
    for (int i = 0 ; i < colores_usados.size() ; ++i) {
      if (colores_vertice.size() > 1) {
        // Elijo el color que es el mas utilizado por mis vecinos
        int color_con_mas_apariciones = dame_el_de_maxima_aparicion(colores_usados);
        // Lo borro
        if (color_con_mas_apariciones != -1 )
          colores_vertice.erase(color_con_mas_apariciones);
      }
    }

    // O salgo del for anterior con muchos colores disponibles porque mis vecinos no
    // estaban pintados
    // o tengo un único color disponible para pintarme
    int color;
    if (colores_vertice.size() == 1) {
      // Si me queda un único color en mi conjunto es el que menos conflictos me causaba
      // por ende pinto al grafo de esa manera
      std::set<int>::iterator it = colores_vertice.begin();
      color = *it;
    } else {
      // Si me queda más de un color disponible busco en los posibles colores 
      // de mis vecinos el que quizas me trae menos conflictos
      int min = 999;
      for (std::pair<const int, int>& par : colores_posibles) {
        if (par.second < min) {
          std::set<int>::iterator it = colores_vertice.find(par.first);
          if (it != colores_vertice.end()) {
            min = par.second;
            color = par.first;
          }
        }
      }
    }
    g.pintar(vertice.dame_nombre(), color);
    //g.imprimir();
    vistos++;
  }
  double res = get_time(); 
  return res;
}

double goloso_por_grado_vertice(Grafo& g) {
	std::priority_queue<Vertice, std::vector<Vertice>, std::greater<Vertice> > vertices;
	double res = pintar_vertices(g, vertices);
	return res;
}

///////////////////////////////////////////////////////Busqueda Local///////////////////////////////////////////////////////

bool paso_busqueda_local_vecinos(Grafo& in){             //Devuelve true si consiguió dar un paso que mejorara el estado anterior

  int verts = in.cant_vertices();
  int maxConfs = 0;
  int mejorPasov1,mejorPasoCol, confs;
  bool encontreUno=false;

  for(int i=0; i<verts; i++) {
	confs = in.conflictos(i);

  	if((confs > maxConfs)) {
  		mejorPasov1 = i;
  		maxConfs = confs;
      encontreUno=true;
  	} 
  }

  if(encontreUno==false){
    return false;
  }

  confs=0;
  int colMejor = in.dame_color(mejorPasov1);
  
  for(int vecino : in.dame_vecinos(mejorPasov1)){
  	
	  int mejorColor=in.dame_color(vecino);

  	if(mejorColor == colMejor){				//Si este vecino crea conflictos con mi nodo
	  int actual;
	  int conflictos=0;
	  for(int col : in.dame_colores_posibles(vecino)){
	  	actual = in.valor_de_pintar(vecino, col);
	  	if(actual > conflictos){
	  		conflictos = actual;
	      mejorColor = col;
	  	}
	  }
	  confs += conflictos;
	  in.pintar(vecino,mejorColor);
  	}

  }

  if(confs == 0){
    return false;
  } else {
    return true;
  }
}

double busqueda_local_vecinos(Grafo& in){
	init_time();
  bool mejoro = true;
  while(mejoro){
    mejoro = paso_busqueda_local_vecinos(in);
  }
  double res = get_time();
  return res;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void pintarRandom(Grafo& in, int randd){
  srand(randd);
  std::set<int> posibles;

  for(int i=0; i<in.cant_vertices(); i++){
    posibles = in.dame_colores_posibles(i);
    std::set<int>::iterator it = posibles.begin();
    for(int random = rand()%(posibles.size());random>0;random--) {
      it++;
    }
    in.pintar(i,*it);
  }
}

void evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite, std::string type, int randd) {
  std::string line;
  std::ifstream fileData(fileTestData.c_str());
  std::ofstream fileWrite(fileTestWrite.c_str(), std::ofstream::app);
  //std::ifstream fileResult (fileTestResult.c_str());
  std::string s;
  std::string res;
  int z = 1;
  // Abri los archivos de datos y resultados
  // e instancie las variables necesarias para el problema
  // el vector de exploradoras y el vector de amistades 


  while (getline (fileData, line)) {
    Grafo grafo;
    int n;
    int m;
    int c;
    getline(fileData, line);
    std::istringstream iss(line);

    iss >> n;
    iss >> m;
    iss >> c;

    for (int i = 0 ; i < n ; ++i) {
      getline(fileData, line);
      std::istringstream iss(line);

      int cantidad_colores;
      iss >> cantidad_colores;

      std::set<int> colores; 
      for (int j = 0 ; j < cantidad_colores ; ++j) {
        int color;
        iss >> color;
        colores.insert(color);
      }

      grafo.agregar_vertice(colores);

    }


    for (int i = 0 ; i < m ; ++i) {
      getline(fileData, line);
      std::istringstream iss(line);

      int v1;
      int v2;
      iss >> v1;
      iss >> v2;

      grafo.agregar_arista(v1, v2);
    }

    
    
	  
	  
	  //grafo.impimir_color(fileTestWrite);
	  //grafo.imprimir();

    int conflictosAntes,conflictosDespues;
    double tiempoAntes, tiempoDespues;

	  if(type.compare("busq_local")==0){			//Por default hace busqueda local individual.
	   	pintarRandom(grafo, randd);
	   	busqueda_local_vecinos(grafo);
		} else if(type.compare("goloso")==0) {
			goloso_por_grado_vertice(grafo);
		} else if(type.compare("ambos")==0) {
			tiempoAntes = goloso_por_grado_vertice(grafo);
			conflictosAntes = grafo.conflictos_totales();
			tiempoDespues = busqueda_local_vecinos(grafo);
			grafo.desvisitar_vertices();
			conflictosDespues = grafo.conflictos_totales();
		}

		fileWrite << type << " " << "Nodos: " << std::fixed << n << " Colores: " << c << " TiempoGoloso: " << tiempoAntes << " TiempoBusq: " << tiempoDespues << " Conflictos: " << conflictosDespues << " ConflictosAntes: " << conflictosAntes << std::endl;

    ++z;

  }
}

int main(int argc, char** argv) {
  std::string fileTestData(argv[1]);
  std::string fileTestResult(argv[2]);
  std::string fileTestWrite(argv[3]);
  std::string type(argv[4]);
  int randd = atoi(argv[5]);
  // Recibo por parametro tres archivos
  // El primero del cual leo los datos a evaluar
  // El segundo en el cual evaluo si los resultados fueron correctos
  // El tercero donde puedo escribir datos (tiempos)

  evaluarTests(fileTestData, fileTestResult, fileTestWrite,type,randd);
  
  return 0;
}