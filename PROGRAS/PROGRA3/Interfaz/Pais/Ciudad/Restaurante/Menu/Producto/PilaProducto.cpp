#pragma once
#include <iostream>
#include "PilaProducto.h"
#include "NodoBinarioProducto.h"


using namespace std;


void PilaProducto::Push(pnodoProducto v)
{
   if(Vacia()) {
      plista = v;
   }else{
    NodoBinarioProducto *aux=plista;
    while(aux->siguiente){
        aux=aux->siguiente;
    }
    aux->siguiente=v;
    v->anterior=aux;
    
   }
}

pnodoProducto PilaProducto::Pop()
{
    NodoBinarioProducto *borrar;
    NodoBinarioProducto *salida;
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

int PilaProducto::Size(){
    while(plista && plista->anterior) plista = plista->anterior;
    int cont=0;
    NodoBinarioProducto *aux;
    aux=plista;
    while(aux){
        cont++;
        aux=aux->siguiente;
    }
    return cont;
}

void PilaProducto::Mostrar(){
    if(Vacia()){
        cout<<"Vacia";
    }
    NodoBinarioProducto *aux = plista;
    while(aux){
        cout<< aux->valor<<":"<<aux->Producto<<" - ";
        aux=aux->siguiente;
    }
}
