
#ifndef _BINARIO_H
#define	_BINARIO_H
#include "NodoBinario.h"
#include <string>

using namespace std;

class Binario{
public:
    pNodoBinario raiz;

    Binario():raiz(NULL){}

    void InsertaNodo(int num, string pais);
    void PreordenI();
    void InordenI();
    void PostordenI();
    void PostordenR(NodoBinario *R);

    bool Hh=false;
    
    void Borrar(NodoBinario *&nodoB, bool);
    void BorrarBalanceado(NodoBinario *&r, bool &Hh, int eliminar);
    void Equilibrar1(NodoBinario *&n, bool &Hh);
    void Equilibrar2(NodoBinario *&n, bool &Hh);
    void InsertarBalanceado(NodoBinario* &ra, bool &Hh, int x, string nombre);
    void RotacionDobleIzquierda(NodoBinario *&n1, NodoBinario *&n2);
    void RotacionDobleDerecha(NodoBinario *&n1, NodoBinario *&n2);
    void RotacionSimpleIzquierda(NodoBinario *&n1, NodoBinario *&n2);
    void RotacionSimpleDerecha(NodoBinario *&n1, NodoBinario *&n2);


};



#endif	/* _BINARIO_H */

