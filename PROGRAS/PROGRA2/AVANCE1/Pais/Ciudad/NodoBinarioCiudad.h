#ifndef _NODOBINARIOCIUDAD_H
#define	_NODOBINARIOCIUDAD_H
#include <cstddef>
#include <string>

using namespace std;

class NodoBinarioCiudad {
   public:

    NodoBinarioCiudad(int num, string nombre, NodoBinarioCiudad *der = NULL, NodoBinarioCiudad *izq = NULL, NodoBinarioCiudad *sig=NULL, NodoBinarioCiudad *ant=NULL):
        Hizq(izq), Hder(der), valor(num), ciudad(nombre), siguiente(sig), anterior(ant), FB(0) {}


    int valor;
    int FB;
    string ciudad;
    NodoBinarioCiudad *Hizq, *Hder, *siguiente, *anterior;

    friend class PilaCiudad;
    friend class BinarioCiudad;

    void InsertaBinarioCiudad(int num, string pais);


};

typedef NodoBinarioCiudad *pnodoCiudad;
typedef NodoBinarioCiudad *pNodoBinarioCiudad;

void PreordenR(NodoBinarioCiudad* R);
void InordenR(NodoBinarioCiudad* R);
void PostordenR(NodoBinarioCiudad* R);
#endif	

