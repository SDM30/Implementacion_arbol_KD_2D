#ifndef __PUNTO__H__
#define __PUNTO__H__
#include <iostream>

struct Punto {
    int x;
    int y;

    Punto& operator = (const Punto &p);

    bool operator == (const Punto &p) const;

    friend std::ostream& operator << (std::ostream &o, const Punto &p);

};

#endif