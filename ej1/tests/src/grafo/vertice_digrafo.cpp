#include "vertice_digrafo.h"

Vertice_digrafo::Vertice_digrafo() {
  return;
}

Vertice_digrafo::Vertice_digrafo(int color, int num, int id, bool v) {
  color_ = color;
  num_ = num;
  id_ = id;
  valor_de_verdad_ = v;
  visto_ = false;
}

int Vertice_digrafo::dame_color() {
  return color_;
}

int Vertice_digrafo::dame_nombre() {
  return num_;
}

int Vertice_digrafo::dame_id() {
  return id_;
}

void Vertice_digrafo::visitar() {
  visto_ = true;
}

bool Vertice_digrafo::fue_visitado() {
  return visto_;
}

bool Vertice_digrafo::dame_valor_de_verdad() {
  return valor_de_verdad_;
}

void Vertice_digrafo::pintar(int color) {
  color_ = color;
}
