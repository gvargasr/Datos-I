#ifndef _NODOBINARIO_H
#define	_NODOBINARIO_H

class NodoBinario {
   public:

    NodoBinario(int num, NodoBinario *der = NULL, NodoBinario *izq = NULL, NodoBinario *sig=NULL, NodoBinario *ant=NULL):
        Hizq(izq), Hder(der), valor(num), siguiente(sig), anterior(ant), FB(0) {}


    int valor;
    int FB;
    NodoBinario *Hizq, *Hder, *siguiente, *anterior;

    friend class Pila;
    friend class Binario;

    void InsertaBinario(int num);
};

typedef NodoBinario *pnodo;
typedef NodoBinario *pNodoBinario;

void PreordenR(NodoBinario* R);
void InordenR(NodoBinario* R);
void PostordenR(NodoBinario* R);
#endif	

