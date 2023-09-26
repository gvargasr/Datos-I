
#ifndef _BINARIO_H
#define	_BINARIO_H
#include "NodoBinarioPais.h"
#include <string>

using namespace std;

class BinarioPais{
public:
    pNodoBinarioPais raiz;
	pNodoBinarioCiudad *Ciudad;
    BinarioPais():raiz(NULL){}

    void InsertaNodoPais(int num, string pais);
    void PreordenI();
    void InordenI();
    void PostordenI();
    void PostordenR(NodoBinarioPais *R);

    bool Hh=false;
    
    void BorrarPais(NodoBinarioPais *&nodoB, bool);
    void BorrarBalanceadoPais(NodoBinarioPais *&r, bool &Hh, int eliminar);
    void Equilibrar1(NodoBinarioPais *&n, bool &Hh);
    void Equilibrar2(NodoBinarioPais *&n, bool &Hh);
    void InsertarBalanceado(NodoBinarioPais* &ra, bool &Hh, int x, string nombre);
    void RotacionDobleIzquierda(NodoBinarioPais *&n1, NodoBinarioPais *&n2);
    void RotacionDobleDerecha(NodoBinarioPais *&n1, NodoBinarioPais *&n2);
    void RotacionSimpleIzquierda(NodoBinarioPais *&n1, NodoBinarioPais *&n2);
    void RotacionSimpleDerecha(NodoBinarioPais *&n1, NodoBinarioPais *&n2);


};



#endif	/* _BINARIO_H */

