#ifndef __ARBOLKD__H__
#define __ARBOLKD__H__
#include "NodoKD.h"

class ArbolKD
{
protected:
    NodoKD *raiz;

public:
    ArbolKD();
    ArbolKD(Punto val);
    ~ArbolKD();
    Punto datoRaiz();
    NodoKD *obtenerRaiz();
    void fijarRaiz(NodoKD *n_raiz);
    bool esVacio();
    bool insertar(Punto val);
    NodoKD *insertarRec(NodoKD* nodo, Punto val, bool& insertado, char dimension);
    //Recorridos
    void preOrden();
    void preOrden(NodoKD *nodo);
    void inOrden();
    void inOrden(NodoKD *nodo);
    void posOrden();
    void posOrden(NodoKD *nodo);
    void nivelOrden();
};

#include "ArbolKD.hxx"

#endif