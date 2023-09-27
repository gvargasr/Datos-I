#ifndef _LISTA_H
#define	_LISTA_H
#include "NodoBinarioPais.h"
using namespace std;


class Pila {
   public:
    Pila() : plista(NULL) {}

    void Push(pnodoPais);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoPais Pop();
    int Size();
    
    pnodoPais plista;
};

#endif	/* _LISTADOBLES_H */

