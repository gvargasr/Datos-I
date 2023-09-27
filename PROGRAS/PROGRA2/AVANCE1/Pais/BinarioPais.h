
#ifndef _BINARIO_H
#define	_BINARIO_H
#include "NodoBinarioPais.h"
#include <string>


using namespace std;

class BinarioPais{
public:
    pNodoBinarioPais raiz;
    BinarioPais():raiz(NULL){}

    void InsertaNodoPais(int num, string pais);
    void PreordenI();
    void InordenI();
    void PostordenI();
    void PostordenR(NodoBinarioPais *R);

    bool Hh=false;
    
    NodoBinarioPais* MinValorNodo(NodoBinarioPais* nodoB);
	void EliminarPais(NodoBinarioPais*& nodoB, int pais);
    void BorrarPais(NodoBinarioPais *&nodoB, bool);
    void BorrarBalanceadoPais(NodoBinarioPais *&r, bool &Hh, int eliminar);
    void Equilibrar1(NodoBinarioPais *&n, bool &Hh);
    void Equilibrar2(NodoBinarioPais *&n, bool &Hh);
    void InsertarBalanceado(NodoBinarioPais* &ra, bool &Hh, int x, string nombre);
    void RotacionDobleIzquierda(NodoBinarioPais *&n1, NodoBinarioPais *&n2);
    void RotacionDobleDerecha(NodoBinarioPais *&n1, NodoBinarioPais *&n2);
    void RotacionSimpleIzquierda(NodoBinarioPais *&n1, NodoBinarioPais *&n2);
    void RotacionSimpleDerecha(NodoBinarioPais *&n1, NodoBinarioPais *&n2);
	NodoBinarioPais* BuscarPais(NodoBinarioPais* nodoB, int num);
	bool BuscarPaisBool(NodoBinarioPais* nodoB, int num);




};



#endif	/* _BINARIO_H */

