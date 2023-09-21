#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


class NodoArbol { // Constructores
   public:
   	NodoArbol(){
   		valor = "";
   		hder = NULL;
   		hizq = NULL;
	}
	
   	NodoArbol(string v){ 
        valor = v;
        hder = NULL;
   		hizq = NULL;
    } 

//   private:
	string valor;
	NodoArbol *hder;
	NodoArbol *hizq;
    
        
   friend class ArbolBinario;
};

typedef NodoArbol *pnodoA; //Alias

class ArbolBinario {
   public:
    ArbolBinario() { raiz =  NULL; }//constructor
    ArbolBinario(pnodoA r){ raiz = r; }
    ~ArbolBinario();//destructor
    NodoArbol InsertarHijos(string v, NodoArbol* &hIzquierdo, NodoArbol* &hDerecho);
    void RecorridoPreorden(pnodoA nodo);
    void RecorridoInorden(pnodoA nodo);
    void RecorridoPostorden(pnodoA nodo);
    void Evaluacion(pnodoA nodo);
    


//   private:
    pnodoA raiz;
};

ArbolBinario::~ArbolBinario()
{
   pnodoA aux;
   
   while(raiz) {
      aux = raiz;
      delete aux;
   }
   raiz = NULL;
}


NodoArbol ArbolBinario::InsertarHijos(string v, NodoArbol* &hIzquierdo, NodoArbol* &hDerecho){
		pnodoA aux = new NodoArbol(v);
		aux->hder = hDerecho;
		aux->hizq = hIzquierdo;
		raiz = aux;
		return *raiz;
}

 void ArbolBinario::RecorridoPreorden(pnodoA nodo) {
        if (nodo != NULL) {
            cout << nodo->valor << " ";
            RecorridoPreorden(nodo->hizq);
            RecorridoPreorden(nodo->hder);
        }
    } 
    
void ArbolBinario::RecorridoInorden(pnodoA nodo) {
        if (nodo != NULL) {
            RecorridoInorden(nodo->hizq);
            cout << nodo->valor << " ";
            RecorridoInorden(nodo->hder);
        }
    } 
    
void ArbolBinario::RecorridoPostorden(pnodoA nodo) {
    if (nodo != NULL) {
        RecorridoPostorden(nodo->hizq);
        RecorridoPostorden(nodo->hder);
        cout << nodo->valor << " ";
    }
}
