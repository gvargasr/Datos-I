
#ifndef _BINARIOProducto_H
#define	_BINARIOProducto_H
#include "NodoBinarioProducto.h"
#include <string>

using namespace std;

class AVLProducto{
public:
    pNodoBinarioProducto raiz;

    AVLProducto():raiz(NULL){}

    void InsertaNodoProducto(int num, string nombre, int Kcal, int Precio, int Cantidad);
    void PreordenI();
    void InordenI();
    void PostordenI();
    void PostordenR(NodoBinarioProducto *R);
    void reporteProducto(string nombre);
    NodoBinarioProducto* ProductoMasBuscado(NodoBinarioProducto* nodoB);
	void InordenR(NodoBinarioProducto* R, NodoBinarioProducto*& masBuscado, int& maxContador);
	NodoBinarioProducto* PrecioProducto(NodoBinarioProducto* nodoB, int num);
	bool BuscarProductoPrecio(NodoBinarioProducto* nodoB, int num);
	bool BuscarProductoCantidad(NodoBinarioProducto* nodoB, int num);


    
    
    
    


    bool Hh=false;
    
    NodoBinarioProducto* MinValorNodo(NodoBinarioProducto* nodo);
    void Borrar(NodoBinarioProducto *&nodoB, bool);
    void BorrarBalanceadoProducto(NodoBinarioProducto *&r, bool &Hh, int eliminar);
    void Equilibrar1(NodoBinarioProducto *&n, bool &Hh);
    void Equilibrar2(NodoBinarioProducto *&n, bool &Hh);
    void InsertarBalanceadoProducto(NodoBinarioProducto* &ra, bool &Hh, int x, string nombre, int cal, int precio, int cant);
    void RotacionDobleIzquierda(NodoBinarioProducto *&n1, NodoBinarioProducto *&n2);
    void RotacionDobleDerecha(NodoBinarioProducto *&n1, NodoBinarioProducto *&n2);
    void RotacionSimpleIzquierda(NodoBinarioProducto *&n1, NodoBinarioProducto *&n2);
    void RotacionSimpleDerecha(NodoBinarioProducto *&n1, NodoBinarioProducto *&n2);
	NodoBinarioProducto* BuscarProducto(NodoBinarioProducto* nodoB, int num);
    bool BuscarProductoBool(NodoBinarioProducto* nodoB, int num);

};



#endif	/* _BINARIO_H */

