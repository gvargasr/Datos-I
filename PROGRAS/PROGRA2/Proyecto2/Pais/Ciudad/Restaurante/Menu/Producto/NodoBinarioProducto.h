#ifndef _NODOBINARIOProducto_H
#define	_NODOBINARIOProducto_H
#include <cstddef>
#include <string>

using namespace std;

class NodoBinarioProducto {
   public:

    NodoBinarioProducto(int num, string nombre, int cal, int Pre, int Cant, NodoBinarioProducto *der = NULL, NodoBinarioProducto *izq = NULL, NodoBinarioProducto *sig=NULL, NodoBinarioProducto *ant=NULL):
        Hizq(izq), Hder(der), valor(num), Producto(nombre), Kcal(cal), Precio(Pre), Cantidad(Cant), siguiente(sig), anterior(ant), FB(0) {}


    int valor;//codProd
    int FB;
    string Producto;//Nombre
    int Kcal;
    int Precio;
    int Cantidad;
    int Contador;
    int ContadorCompras;
    NodoBinarioProducto *Hizq, *Hder, *siguiente, *anterior;

    friend class PilaProducto;
    friend class BinarioProducto;

    void InsertaBinarioProducto(int num, string nombre, int Kcal, int Precio, int Cantidad);


};

typedef NodoBinarioProducto *pnodoProducto;
typedef NodoBinarioProducto *pNodoBinarioProducto;

void PreordenR(NodoBinarioProducto* R);
void InordenR(NodoBinarioProducto* R, NodoBinarioProducto*& masBuscado, int& maxContador);
void PostordenR(NodoBinarioProducto* R);
#endif	

