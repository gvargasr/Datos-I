
#ifndef _BINARIOCIUDAD_H
#define	_BINARIOCIUDAD_H
#include "NodoBinarioCiudad.h"
#include "PilaCiudad.h"
#include <string>

using namespace std;

class AVLCiudad{
public:
    pNodoBinarioCiudad raiz;

    AVLCiudad():raiz(NULL){}

    void InsertaNodoCiudad(int num, string nombre);
    void PreordenI();
    void InordenI();
    void PostordenI();
    void PostordenR(NodoBinarioCiudad *R);

    bool Hh=false;
    
    void Borrar(NodoBinarioCiudad *&nodoB, bool);
    void BorrarBalanceadoCiudad(NodoBinarioCiudad *&r, bool &Hh, int eliminar);
    void Equilibrar1(NodoBinarioCiudad *&n, bool &Hh);
    void Equilibrar2(NodoBinarioCiudad *&n, bool &Hh);
    void InsertarBalanceadoCiudad(NodoBinarioCiudad* &ra, bool &Hh, int x, string nombre);
    void RotacionDobleIzquierda(NodoBinarioCiudad *&n1, NodoBinarioCiudad *&n2);
    void RotacionDobleDerecha(NodoBinarioCiudad *&n1, NodoBinarioCiudad *&n2);
    void RotacionSimpleIzquierda(NodoBinarioCiudad *&n1, NodoBinarioCiudad *&n2);
    void RotacionSimpleDerecha(NodoBinarioCiudad *&n1, NodoBinarioCiudad *&n2);


};



#endif	/* _BINARIO_H */

