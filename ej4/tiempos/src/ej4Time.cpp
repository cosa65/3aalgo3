#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <sys/time.h>

#include "../../../grafo/grafo.h"
//#include "goloso.cpp"

timeval start, end;
double acum = 0;

void init_time() {
  gettimeofday(&start, NULL);
}

double get_time() {
  gettimeofday(&end, NULL);
  return (1000000*(end.tv_sec-start.tv_sec) + (end.tv_usec-start.tv_usec))/1000000.0;
}

//Funciones y datos utilizados para la toma de tiempos

bool paso_busqueda_local_vecinos(Grafo& in){             //Devuelve true si consiguió dar un paso que mejorara el estado anterior

  int verts = in.cant_vertices();
  int maxConfs = 0;
  int mejorPasov1,mejorPasoCol, confs;

  for(int i=0; i<verts; i++) {
  confs = in.conflictos(i);

    if((confs > maxConfs)) {
      mejorPasov1 = i;
      maxConfs = confs;
    }
  }

  if(maxConfs == 0) return false;

  confs=0;
  int colMejor = in.dame_color(mejorPasov1);
  
  for(int vecino : in.dame_vecinos(mejorPasov1)){
    
    int mejorColor=in.dame_color(vecino);

    if(mejorColor == colMejor){       //Si este vecino crea conflictos con mi nodo
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

bool paso_busqueda_local_individual(Grafo& in) {
  int verts = in.cant_vertices();
  int maxConfs = 0;
  int mejorPasov1,mejorPasoCol, confs;

  for(int i=0; i<verts; i++) {
  confs = in.conflictos(i);

    if((confs > maxConfs)) {
      mejorPasov1 = i;
      maxConfs = confs;
    }
  }

  if(maxConfs == 0) return false;

  int actual;
  int conflictos=0;
  for(int col : in.dame_colores_posibles(mejorPasov1)){
    actual = in.valor_de_pintar(mejorPasov1, col);
    if(actual > conflictos){
      conflictos = actual;
        mejorPasoCol = col;
    }
  }

  if(conflictos == 0){
    return false;
  } else {
    in.pintar(mejorPasov1,mejorPasoCol);
    return true; 
  } 
}

long busqueda_local_vecinos(Grafo& in){
  init_time();
  bool mejoro = true;
  while(mejoro){
    mejoro = paso_busqueda_local_vecinos(in);
  }
  return get_time();
}

long busqueda_local_individual(Grafo& in){
  init_time();
  bool mejoro = true;
  while(mejoro){
    mejoro = paso_busqueda_local_individual(in);
  }
  return get_time();
}

void pintarRandom(Grafo& in,int seed){
  srand(seed);
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

int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite, std::string type, int seed) {
  std::string line;
  std::ifstream fileData (fileTestData.c_str());
  //std::ifstream fileResult (fileTestResult.c_str());
  std::string s;
  std::string res;
  int z = 1;
  // Abri los archivos de datos y resultados


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

    
    
    //goloso_por_grado_vertice(grafo);
    //grafo.impimir_color(fileTestWrite);
    //grafo.imprimir();

    pintarRandom(grafo,seed);  

    long int conflictosAntes = grafo.conflictos_totales();

    double tiempo;

    if(type.compare("vecinos")==0){      //Por default hace busqueda local individual.
      tiempo = busqueda_local_vecinos(grafo);
    } else {
      tiempo = busqueda_local_individual(grafo);
    }

    std::ofstream fileTime(fileTestWrite,std::ofstream::app);

    grafo.desvisitar_vertices();

    fileTime << type << " " << "Nodos: " << std::fixed << n << " Colores: " << c << " Tiempo: " << tiempo << " Conflictos: " << grafo.conflictos_totales() << " ConflictosAntes: " << conflictosAntes << std::endl;

    //grafo.impimir_color(fileTestWrite);
    ++z;

  }
  return 0;
}

int main(int argc, char** argv) {
  std::string fileTestData(argv[1]);
  std::string fileTestResult(argv[2]);
  std::string fileTestWrite(argv[3]);
  std::string type(argv[4]);
  int seed = atoi(argv[5]);

  evaluarTests(fileTestData, fileTestResult, fileTestWrite,type,seed);
  
  return 0;
}