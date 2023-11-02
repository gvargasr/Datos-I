#ifndef _PILA_PAIS
#define	_PILA_PAIS
#include "NodoBinarioPais.h"
using namespace std;


class PilaPais {
   public:
    PilaPais() : plista(NULL) {}
    void Push(pnodoPais);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoPais Pop();
    int Size();
    
    pnodoPais plista;
};

#endif	/* _PILA_PAIS */

