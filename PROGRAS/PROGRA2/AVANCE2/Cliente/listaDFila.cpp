
#include <iostream>
#include <string>
using namespace std;

class nodoFila { // Constructores
   public:
   	
   	
nodoFila(int v, string n)//3
    {
       valor = v;
       nombre = n;
       siguiente = NULL;
 //      listaComp = new listaDCompra;
    }

nodoFila(int v, string n,nodoFila  *signodoFila)
    {
       valor = v;
       nombre = n;
       siguiente = signodoFila;
  //     listaComp = new listaDCompra;
    }


   	//private:
   	string nombre="";
    int valor=0;
    nodoFila *siguiente;// Clase Autoreferencia
//    listaDCompra *listaComp = NULL;
        
   friend class listaDFila;
};

typedef nodoFila *pnodoFila;

class listaDFila {
   public:
    listaDFila() { primero =  NULL; }
    ~listaDFila();
    
    void InsertarFinal(int v, string n);
    void InsertarInicio(int v, string n);
    bool ListaVacia() { return primero == NULL; }
    int largoLista();
    pnodoFila GetPrimero();
    
   private:
    pnodoFila primero;
   
};

listaDFila::~listaDFila()
{
   pnodoFila aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero= NULL;
}


void listaDFila::InsertarFinal(int v, string n) {
    pnodoFila nuevo = new nodoFila(v, n);
    
    if (ListaVacia()) {
        primero = nuevo;
    } else {
        pnodoFila temp = primero;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
                temp->siguiente = nuevo;
    }
}



void listaDFila::InsertarInicio(int v, string n)//3 10 265
{
   if (ListaVacia())
   {
   
     primero = new nodoFila(v, n);//6
     
   }
   else
   {
     
    pnodoFila nuevo=new nodoFila(v, n);
    nuevo->siguiente=primero;
    primero=nuevo; 
   }
}

int listaDFila::largoLista(){
    int cont=0;

    pnodoFila aux= primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    cout<< endl;
    }
    
}

pnodoFila listaDFila::GetPrimero(){
	pnodoFila aux = primero;
	return aux;
}
