#include <iostream>
#include "PilaCiudad.h"
//#include "NodoBinarioCiudad.h"

using namespace std;

/*class PilaCiudad {
   public:
    PilaCiudad() : plista(NULL) {}

    void Push(pnodoCiudad);
    void Mostrar();
    bool Vacia() { return plista == NULL; }
    pnodoCiudad Pop();
    int Size();
    
    pnodoCiudad plista;
};*/

//PilaCiudad::PilaCiudad() : plista(NULL) {}

void PilaCiudad::Push(pnodoCiudad v)
{
   if(Vacia()) {
      plista = v;
   }else{
    NodoBinarioCiudad *aux=plista;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;
    
   }
}

pnodoCiudad PilaCiudad::Pop()
{
    NodoBinarioCiudad *borrar;
    NodoBinarioCiudad *salida;
    if(Vacia()){
        cout<<"Pila Vacia"<<endl;
    }else{
    borrar=plista;
    while(borrar->siguiente){
        borrar=borrar->siguiente;
    }
    if(Size()>1){
        salida=borrar;
        borrar->anterior->siguiente=NULL;
        borrar=NULL;
        delete borrar;
    }else{
        salida =plista;        
        plista = NULL;
    }
    }    
    return salida;
}

int PilaCiudad::Size(){
    while(plista && plista->anterior) plista = plista->anterior;
    int cont=0;
    NodoBinarioCiudad *aux;
    aux=plista;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void PilaCiudad::Mostrar(){
    if(Vacia()){
        cout<<"Vacia";
    }
    NodoBinarioCiudad *aux = plista;
    while(aux){
        cout<< aux->valor<<":"<<aux->ciudad<<" - ";
        aux=aux->siguiente;
    }
}
