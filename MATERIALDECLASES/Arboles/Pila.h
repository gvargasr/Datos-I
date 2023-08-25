#ifndef _LISTA_H
#define	_LISTA_H
#include "NodoBinario.h"
using namespace std;


class Pila {
   public:
    Pila() : plista(NULL) {}

    void Push(pnodo);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodo Pop();
    int Size();
    
    pnodo plista;
};

#endif	/* _LISTADOBLES_H */

