#ifndef _LISTA_H
#define	_LISTA_H
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

#endif	/* _LISTADOBLES_H */

