#include "ArbolKD.h"
#include <queue>

ArbolKD::ArbolKD() {
    this->raiz = NULL;
}


ArbolKD::~ArbolKD() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}


bool ArbolKD::esVacio() {
    return this->raiz == NULL;
}


Punto ArbolKD::datoRaiz() {
    return (this->raiz)->obtenerDato();
}


void ArbolKD::fijarRaiz(NodoKD* nodo) {
    this->raiz = nodo;
}


NodoKD* ArbolKD::obtenerRaiz() {
    return this->raiz;
}

bool ArbolKD::insertar(Punto val) {
  bool insertado = false;
  this->raiz = insertarRec(this->raiz, val, insertado, 'x');
  return insertado;
}

NodoKD* ArbolKD::insertarRec(NodoKD* nodo, Punto val, bool& insertado, char dimension){
    if (nodo == NULL) {
        insertado = true;
        return new NodoKD(val);
    }

    if (val.x == nodo->obtenerDato().x && val.y == nodo->obtenerDato().y) {
        insertado = false; //DUPLICADO
        return nodo;
    }

    if (dimension == 'x') {
        if (val.x <= nodo->obtenerDato().x) {
            nodo->fijarHijoIzq(insertarRec(nodo->obtenerHijoIzq(), val, insertado, 'y'));
        } else if (val.x > nodo->obtenerDato().x) {
            nodo->fijarHijoDer(insertarRec(nodo->obtenerHijoDer(), val, insertado, 'y'));
        }
    }
    if (dimension == 'y') {
        if (val.y <= nodo->obtenerDato().y) {
            nodo->fijarHijoIzq(insertarRec(nodo->obtenerHijoIzq(), val, insertado, 'x'));
        } else if (val.y > nodo->obtenerDato().y) {
            nodo->fijarHijoDer(insertarRec(nodo->obtenerHijoDer(), val, insertado, 'x'));
        }
    }

    return nodo;
}

void ArbolKD::preOrden() {
    if(!this->esVacio()) {
        this->preOrden(this->raiz);
    }
}


void ArbolKD::preOrden(NodoKD* nodo) {
    std::cout << nodo->obtenerDato() << " ";

    if (nodo->obtenerHijoIzq() != NULL) {
        this->preOrden(nodo->obtenerHijoIzq());
    }

    if (nodo->obtenerHijoDer() != NULL) {
        this->preOrden(nodo->obtenerHijoDer());
    }
}


void ArbolKD::inOrden() {
    if (!this->esVacio()) {
        this->inOrden(this->raiz);
    }
}


void ArbolKD::inOrden(NodoKD *nodo) {
    if (nodo != NULL) {
        this->inOrden(nodo->obtenerHijoIzq());
        std::cout << nodo->obtenerDato() << " ";
        this->inOrden(nodo->obtenerHijoDer());
    }
}


void ArbolKD::posOrden() {
    if(!this->esVacio()) {
        this->posOrden(this->raiz);
    }
}


void ArbolKD::posOrden(NodoKD *nodo) {
    if (nodo->obtenerHijoIzq() != NULL) {
        this->posOrden(nodo->obtenerHijoIzq());
    }

    if (nodo->obtenerHijoDer() != NULL) {
        this->posOrden(nodo->obtenerHijoDer());
    }

    std::cout << nodo->obtenerDato() << " ";
}


void ArbolKD::nivelOrden() {
    if (!this->esVacio()) {
        std::queue<NodoKD*> cola;
        cola.push(this->raiz);
        NodoKD* nodo;

        while(!cola.empty()) {
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->obtenerDato() << " ";

            if (nodo->obtenerHijoIzq() != NULL) {
                cola.push(nodo->obtenerHijoIzq());
            }

            if (nodo->obtenerHijoDer() != NULL) {
                cola.push(nodo->obtenerHijoDer());
            }
        }
    }
}