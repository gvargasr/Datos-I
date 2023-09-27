#include <iostream>
#include "PilaPais.h"
#include "NodoBinarioPais.h"

using namespace std;

void Pila::Push(pnodoPais v)
{
   if(Vacia()) {
      plista = v;
   }else{
    NodoBinarioPais *aux=plista;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;
    
   }
}

pnodoPais Pila::Pop()
{
    NodoBinarioPais *borrar;
    NodoBinarioPais *salida;
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

int Pila::Size(){
    while(plista && plista->anterior) plista = plista->anterior;
    int cont=0;
    NodoBinarioPais *aux;
    aux=plista;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void Pila::Mostrar(){
    if(Vacia()){
        cout<<"Vacia";
    }
    NodoBinarioPais *aux = plista;
    while(aux){
        cout<< aux->valor<<":"<<aux->pais<<" - ";
        aux=aux->siguiente;
    }
}
