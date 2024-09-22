#include <iostream>
#include "ArbolKD.h"  // Asegúrate de que este archivo incluya la definición de Punto y NodoKD.

int main() {
    ArbolKD arbol;

    // Crear algunos puntos para insertar
    Punto p1 = {32, 25};
    Punto p2 = {30, 35};
    Punto p3 = {35, 30};
    Punto p4 = {37, 12};
    Punto p5 = {25, 45};
    Punto p6 = {45, 32};
    Punto p7 = {5, 15};
    Punto p8 = {40, 42};

    // Insertar puntos en el árbol
    arbol.insertar(p1);
    arbol.insertar(p2);
    arbol.insertar(p3);
    arbol.insertar(p4);
    arbol.insertar(p5);
    arbol.insertar(p6);
    arbol.insertar(p7);
    arbol.insertar(p8);

    // Imprimir en diferentes órdenes
    std::cout << "Recorrido en pre-orden:" << std::endl;
    arbol.preOrden();

    std::cout << "\nRecorrido en in-orden:" << std::endl;
    arbol.inOrden();

    std::cout << "\nRecorrido en pos-orden:" << std::endl;
    arbol.posOrden();

    std::cout << "\nRecorrido en nivel-orden:" << std::endl;
    arbol.nivelOrden();
    std::cout<<std::endl;

    return 0;
}
