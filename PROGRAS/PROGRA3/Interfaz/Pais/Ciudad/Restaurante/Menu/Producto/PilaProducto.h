#pragma once
#ifndef _PILA_PROD
#define	_PILA_PROD
#include "NodoBinarioProducto.h"
using namespace std;


class PilaProducto {
   public:
    PilaProducto() : plista(NULL) {}

    void Push(pnodoProducto);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoProducto Pop();
    int Size();
    
    pnodoProducto plista;
};


#endif	/* _PILA_PROD */

