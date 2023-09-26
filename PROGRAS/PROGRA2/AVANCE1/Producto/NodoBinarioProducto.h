#ifndef _NODOBINARIOPRODUCTO_H
#define	_NODOBINARIOPRODUCTO_H
#include <cstddef>
#include <string>

using namespace std;

class NodoBinario {
   public:

    NodoBinario(int num, string prod, int kcal, int price,int cant, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(num), producto(prod), caloria(kcal), precio(price), cantidad(cant), siguiente(sig), anterior(ant), FB(0) {}


    int valor;
    int FB;
    string producto;
    int caloria;
    int precio;
    int cantidad;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;
    NodoBinario *Ciudades;

    friend class Pila;
    friend class Binario;

    void InsertaBinario(int num, string pais,int kcal, int price,int cant);
};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void PreordenR(NodoBinario* R);
void InordenR(NodoBinario* R);
void PostordenR(NodoBinario* R);
#endif	

