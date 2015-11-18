#ifndef VERTICE_DIGRAFO_H_ 
#define VERTICE_DIGRAFO_H_ 

#include <set>

class Vertice_digrafo {
  
  public:

    Vertice_digrafo();
    Vertice_digrafo(int color, int num, int id, bool v);

    int dame_color();
    int dame_nombre();
    int dame_id();
    bool dame_valor_de_verdad();

    bool fue_visitado();

    void pintar(int color);

    void visitar();

  private:

      int color_;
      int num_;
      int id_;
      bool valor_de_verdad_;
      bool visto_;
};

#endif
