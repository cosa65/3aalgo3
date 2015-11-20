#include "vertice_mayor_vertice.h"

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

void Vertice::aumentar_grado() {
  grado_++;
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

void Vertice::desvisitar() {
  visto_ = false;
}

bool Vertice::fue_visitado() {
  return visto_;
}

int Vertice::dame_nombre() {
  return num_;
}

void Vertice::eliminar_color(int color) {
  std::set<int>::iterator it;
  it = colores_disponibles_.find(color);
  if (it != colores_disponibles_.end()) colores_disponibles_.erase(it);
}

void Vertice::agregar_color(int color) {
  colores_disponibles_.insert(color);
}

void Vertice::pintar(int color) {
  color_ = color;
}

bool Vertice::coincide_color(Vertice otro){
  return (color_ == otro.dame_color());
}

// Estas operaciones de comparacion estan hechas
// para el ejercicio 3.
// De esta manera puedo encolar en una cola de prioridad
// por maximo grado y por minima cantidad de colores disponibles

bool Vertice::operator <(Vertice v) const {
 return grado_ > v.dame_grado(); 
}

bool Vertice::operator >(Vertice v) const {
 return grado_ < v.dame_grado(); 
}

// bool Vertice::operator <(Vertice v) const {
//   return colores_disponibles_.size() < v.dame_colores_posibles().size(); 
// }

// bool Vertice::operator >(Vertice v) const {
//   return colores_disponibles_.size() > v.dame_colores_posibles().size(); 
// }
