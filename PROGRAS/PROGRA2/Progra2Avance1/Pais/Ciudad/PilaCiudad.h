#ifndef _LISTA_H
#define	_LISTA_H
#include "NodoBinarioCiudad.h"
using namespace std;


class PilaCiudad {
   public:
    PilaCiudad() : plista(NULL) {}

    void Push(pnodoCiudad);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoCiudad Pop();
    int Size();
    
    pnodoCiudad plista;
};

#endif	/* _LISTADOBLES_H */

