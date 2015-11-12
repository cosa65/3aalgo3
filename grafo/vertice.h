#ifndef VERTICE_H_ 
#define VERTICE_H_ 

#include <set>

class Vertice {
  
  public:

    Vertice();
    Vertice(std::set<int> colores, int num);

    void aumentar_grado();

    std::set<int> dame_colores_posibles();
    int dame_grado();
    int dame_color();
    int dame_nombre();

    void eliminar_color(int color);
    void agregar_color(int color);

    bool fue_visitado();

    bool operator <(Vertice v) const;
    bool operator >(Vertice v) const;

    void pintar(int color);

    void visitar();

    bool coincide_color(Vertice otro);

  private:

      std::set<int> colores_disponibles_;
      int grado_;
      int color_;
      int num_;
      bool visto_;
};

#endif
