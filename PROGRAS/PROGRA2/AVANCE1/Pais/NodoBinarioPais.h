#ifndef _NODOBINARIOPAIS_H
#define	_NODOBINARIOPAIS_H
#include <cstddef>
#include <string>

using namespace std;

class NodoBinarioPais {
   public:

    NodoBinarioPais(int num, string nombre, NodoBinarioPais *der = NULL, NodoBinarioPais *izq = NULL, NodoBinarioPais *sig=NULL, NodoBinarioPais *ant=NULL):
        Hizq(izq), Hder(der), valor(num), pais(nombre), siguiente(sig), anterior(ant), FB(0) {}


    int valor;
    int FB;
//    BinarioCiudad *B;
    string pais;
    NodoBinarioPais *Hizq, *Hder, *siguiente, *anterior;
//    BinarioCiudad *Ciudad;

    friend class PilaPais;
    friend class PaisBinario;

    void InsertaBinarioPais(int num, string nombre);
};

typedef NodoBinarioPais *pnodoPais;
typedef NodoBinarioPais *pNodoBinarioPais;

void PreordenR(NodoBinarioPais* R);
void InordenR(NodoBinarioPais* R);
void PostordenR(NodoBinarioPais* R);
#endif	

