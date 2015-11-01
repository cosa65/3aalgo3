#include "vertice.h"

Vertice::Vertice() {
  return;
}

Vertice::Vertice(std::set<int> colores, int num) {
  colores_disponibles_ = colores;
  grado_ = 0;
  color_ = -1;
  visto_ = false;
  num_ = num;
}

std::set<int> Vertice::dame_colores_posibles() {
  return colores_disponibles_;
}

int Vertice::dame_grado() {
  return grado_;
}

int Vertice::dame_color() {
  return color_;
}

void Vertice::visitar() {
  visto_ = true;
}

bool Vertice::fue_visitado() {
  return visto_;
}

int Vertice::dame_nombre() {
  return num_;
}

void Vertice::pintar(int color) {
  color_ = color;
}

bool Vertice::operator <(Vertice v) const {
  return grado_ < v.dame_grado(); 
}

bool Vertice::operator >(Vertice v) const {
  return grado_ > v.dame_grado(); 
}
