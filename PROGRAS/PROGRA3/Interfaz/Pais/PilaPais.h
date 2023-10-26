#ifndef _PILAPAIS_H
#define	_PILAPAIS_H
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

#endif	/* _PILAPAIS_H */

