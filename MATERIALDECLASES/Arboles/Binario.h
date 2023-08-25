
#ifndef _BINARIO_H
#define	_BINARIO_H
#include "NodoBinario.h"

using namespace std;

class Binario{
public:
    pNodoBinario raiz;

    Binario():raiz(NULL){}

    void InsertaNodo(int num);
    void PreordenI();
    void InordenI();
    void PostordenI();

    bool Hh;
    
    void Borrar(NodoBinario *nodoB, bool);
    void BorrarBalanceado(NodoBinario *r, bool, int eliminar);
    void Equilibrar1(NodoBinario *n, bool);
    void Equilibrar2(NodoBinario *n, bool);
    void InsertarBalanceado(NodoBinario *r, bool, int x);
    void RotacionDobleIzquierda(NodoBinario *n1, NodoBinario *n2);
    void RotacionDobleDerecha(NodoBinario *n1, NodoBinario *n2);
    void RotacionSimpleIzquierda(NodoBinario *n1, NodoBinario *n2);
    void RotacionSimpleDerecha(NodoBinario *n1, NodoBinario *n2);


};



#endif	/* _BINARIO_H */

