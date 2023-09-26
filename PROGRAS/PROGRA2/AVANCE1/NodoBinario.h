#ifndef _NODOBINARIO_H
#define	_NODOBINARIO_H
#include <cstddef>
#include <string>

using namespace std;

class NodoBinario {
   public:

    NodoBinario(int num, string pais, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(num), pais(pais), siguiente(sig), anterior(ant), FB(0) {}


    int valor;
    int FB;
    string pais;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;
    NodoBinario *Ciudades;

    friend class Pila;
    friend class Binario;

    void InsertaBinario(int num, string pais);
};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void PreordenR(NodoBinario* R);
void InordenR(NodoBinario* R);
void PostordenR(NodoBinario* R);
#endif	

