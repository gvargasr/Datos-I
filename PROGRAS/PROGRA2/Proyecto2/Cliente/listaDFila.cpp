
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
       listaComp = new listaDCompra;
    }

nodoFila(int v, string n,nodoFila  *signodoFila)
    {
       valor = v;
       nombre = n;
       siguiente = signodoFila;
       listaComp = new listaDCompra;
    }


   	//private:
   	string nombre="";
    int valor=0;
    nodoFila *siguiente;// Clase Autoreferencia
    listaDCompra *listaComp = NULL;
        
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
    bool BuscadorBool(int ced);
    pnodoFila Buscador(int ced);
    void Comprar(int ced, string nom , int codigo, string nombre, int kcal, int precio, int cantidad);
    void BorrarInicio();
    int ReturnCedula(int ced);
    
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

pnodoFila listaDFila::Buscador(int ced) {
	pnodoFila aux = primero;
	while (aux!=NULL){
		if (aux->valor == ced){
			return aux;
		}
		aux=aux->siguiente;
	}
	
}

bool listaDFila::BuscadorBool(int ced) {
	pnodoFila aux = primero;
	bool encontrado = false;
	while (aux!=NULL){
		if (aux->valor == ced){
			 encontrado = true;
			break;
		}
		aux=aux->siguiente;
	}
	return encontrado;
}

void listaDFila::Comprar(int ced, string nom , int codigo, string nombre, int kcal, int precio, int cantidad){
	if (BuscadorBool(ced)){
		pnodoFila aux = Buscador(ced);
		aux->listaComp->InsertarFinal( codigo,  nombre,  kcal,  precio, cantidad);
	} else {
		InsertarFinal(ced,nom);
		pnodoFila aux = Buscador(ced);
		aux->listaComp->InsertarFinal( codigo,  nombre,  kcal,  precio, cantidad);
	}	
}

int listaDFila::ReturnCedula(int ced){
		if (BuscadorBool(ced)){
		pnodoFila aux = Buscador(ced);
		return aux->valor;
	} else {
	
	return -1; 	
}
}

void listaDFila::BorrarInicio(){
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoFila temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodoFila aux = primero;
                primero=primero->siguiente;   
                delete aux;
            }
        }
}
}


