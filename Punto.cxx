#include "Punto.h"

Punto& Punto::operator=(const Punto &p) {
    if (this != &p) {  // Evitar la auto-asignación
        this->x = p.x;
        this->y = p.y;
    }
    return *this;
}

bool Punto::operator==(const Punto &p) const {
    return (this->x == p.x) && (this->y == p.y);
}

std::ostream& operator<<(std::ostream &o, const Punto &p) {
    o << "(" << p.x << ", " << p.y << ")";
    return o;
}