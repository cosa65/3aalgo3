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

bool paso_busqueda_local_intercambiar(Grafo& in){             //Devuelve true si consiguió dar un paso que mejorara el estado anterior
  int verts = in.cant_vertices();
  int conflictos = 0;
  int mejorPasov1, mejorPasov2;
  std::set<int> posibles; 

  for(int i=0; i<verts; i++){
    for(int j=i; j<verts; j++){
      if(in.son_colores_intercambiables(i,j)){
        int actual = in.valor_de_intercambio(i,j);
        if(actual > conflictos){
          conflictos = actual;
          mejorPasov1 = i;
          mejorPasov2 = j;
        } 
      }
    }
  }
  if(conflictos == 0){
    return false;

  } else {
    in.intercambiar_color(mejorPasov1,mejorPasov2);
    return true;
  } 
}

bool paso_busqueda_local_individual(Grafo& in){
  int verts = in.cant_vertices();
  int conflictos = 0;
  int mejorPasov1, mejorPasoCol;

  for(int i=0; i<verts; i++){
    for(int col : in.dame_vertice(i).dame_colores_posibles()){
      int actual = in.valor_de_pintar(i,col);
      if(actual > conflictos){
        conflictos = actual;
        mejorPasov1 = i;
        mejorPasoCol = col;
      }
    }
  }

  if(conflictos == 0){
    return false;
  } else {
    in.pintar(mejorPasov1,mejorPasoCol);
    return true; 
  } 
}

double busqueda_local_intercambiar(Grafo& in){
  init_time();
  bool mejoro = true;
  while(mejoro){
    mejoro = paso_busqueda_local_intercambiar(in);
  }
  double result = get_time();
  return result;
}

double busqueda_local_individual(Grafo& in){
  init_time();
  bool mejoro = true;
  while(mejoro){
    mejoro = paso_busqueda_local_individual(in);
  }
  double result = get_time();
  return result;
}

void pintarRandom(Grafo& in){
  srand(time(NULL));
  std::set<int> posibles;

  for(int i=0; i<in.cant_vertices(); i++){
    posibles = in.dame_colores_posibles(i);
    std::set<int>::iterator it = posibles.begin();
    for(int random = rand()%(posibles.size());random>=0;random--) {
      it++;
    }
    in.pintar(i,*it);
  }
}

int evaluarTests(std::string fileTestData, std::string fileTestResult, std::string fileTestWrite, std::string type) {
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

    pintarRandom(grafo);  

    int conflictosAntes = grafo.conflictos_totales();

    double tiempo;

    if(type.compare("intercambiar")==0){      //Por default hace busqueda local individual.
      tiempo = busqueda_local_intercambiar(grafo);
    } else {
      tiempo = busqueda_local_individual(grafo);
    }

    std::ofstream fileTime(fileTestWrite,std::ofstream::app);

    grafo.desvisitar_vertices();

    fileTime << type << " " << "Nodos: " << std::fixed << n << " Colores: " << c << " Tiempo: " << tiempo << " Conflictos: " << grafo.conflictos_totales() << " Conflictos Antes: " << conflictosAntes << std::endl;

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

  evaluarTests(fileTestData, fileTestResult, fileTestWrite,type);
  
  return 0;
}