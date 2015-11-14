#include <queue>
#include <map>

void goloso_por_colores_posibles_vertice(Grafo& g) {
  int vistos = 0;
  int cant_vertices = g.cant_vertices();

  std::priority_queue<Vertice> vertices_usados;

  // Creo vector para obtener el maximo
  for (int i = 0 ; i < cant_vertices ; ++i) {
    vertices_usados.push(g.dame_vertice(i));
  }

  // Recorro todos los vertices del grafo
  while (vistos < cant_vertices) {

    // Hallar el vertice de mayor grado
    Vertice vertice = vertices_usados.top();
    vertices_usados.pop();
    std::set<int> colores_vertice = vertice.dame_colores_posibles(); 

    // Creo un diccionario para ver cual es el color 
    // que mas se repite entre los vecinos
    std::map<int, int> colores_usados;
    for (int color : colores_vertice) {
      colores_usados.insert(std::pair<int, int> (color, 0));
    }

    // recorro los vecinos del maximo
    std::set<int> vecinos = g.dame_vecinos(vertice.dame_nombre());
    for (int v : vecinos) {

      // Si tengo mas de un color disponible para pintarlo al maximo
      if (colores_vertice.size() > 1) {

        int color_vecino = g.dame_color(v);
        if (color_vecino != -1) { // Ya esta pintado el vecino y no puedo usar ese color
          // Me fijo si el de grado maximo tiene ese color como disponible
          std::set<int>::iterator it = colores_vertice.find(color_vecino);
          if (it != colores_vertice.end()) { 
            // Si es asi lo borro del conjunto de colores y del diccionario
            colores_vertice.erase(it);
            std::map<int, int>::iterator it = colores_usados.find(color_vecino);
            colores_usados.erase(it);
          }

        } else {
          // Si no esta pintado el vecino
          std::set<int> colores_vecino = g.dame_colores_posibles(v);

          // Por cada color que entre en conflicto sumo 1 en el diccionario
          for (int color : colores_vecino) {
            std::set<int>::iterator it = colores_vertice.find(color);
            if (it != colores_vertice.end()) {
              colores_usados[color]++;
            }
          }
        }
      }
    }
    int color;
    int min = 99;
    for (std::pair<const int, int>& par : colores_usados) {
      if (par.second < min) {
        min = par.second;
        color = par.first;
      }
    }
    g.pintar(vertice.dame_nombre(), color);
    vistos++;
  }

}

void goloso_por_grado_vertice(Grafo& g) {
  int vistos = 0;
  int cant_vertices = g.cant_vertices();

  std::priority_queue<Vertice, std::vector<Vertice>, std::greater<Vertice> > vertices_usados;

  // Creo vector para obtener el maximo
  for (int i = 0 ; i < cant_vertices ; ++i) {
    vertices_usados.push(g.dame_vertice(i));
  }

  // Recorro todos los vertices del grafo
  while (vistos < cant_vertices) {

    // Hallar el vertice de mayor grado
    Vertice vertice = vertices_usados.top();
    vertices_usados.pop();
    std::set<int> colores_vertice = vertice.dame_colores_posibles(); 

    // Creo un diccionario para ver cual es el color 
    // que mas se repite entre los vecinos
    std::map<int, int> colores_usados;
    for (int color : colores_vertice) {
      colores_usados.insert(std::pair<int, int> (color, 0));
    }

    // recorro los vecinos del maximo
    std::set<int> vecinos = g.dame_vecinos(vertice.dame_nombre());
    for (int v : vecinos) {

      // Si tengo mas de un color disponible para pintarlo al maximo
      if (colores_vertice.size() > 1) {

        int color_vecino = g.dame_color(v);
        if (color_vecino != -1) { // Ya esta pintado el vecino y no puedo usar ese color
          // Me fijo si el de grado maximo tiene ese color como disponible
          std::set<int>::iterator it = colores_vertice.find(color_vecino);
          if (it != colores_vertice.end()) { 
            // Si es asi lo borro del conjunto de colores y del diccionario
            colores_vertice.erase(it);
            std::map<int, int>::iterator it = colores_usados.find(color_vecino);
            colores_usados.erase(it);
          }

        } else {
          // Si no esta pintado el vecino
          std::set<int> colores_vecino = g.dame_colores_posibles(v);

          // Por cada color que entre en conflicto sumo 1 en el diccionario
          for (int color : colores_vecino) {
            std::set<int>::iterator it = colores_vertice.find(color);
            if (it != colores_vertice.end()) {
              colores_usados[color]++;
            }
          }
        }
      }
    }
    int color;
    int min = 99;
    for (std::pair<const int, int>& par : colores_usados) {
      if (par.second < min) {
        min = par.second;
        color = par.first;
      }
    }
    g.pintar(vertice.dame_nombre(), color);
    vistos++;
  }
}