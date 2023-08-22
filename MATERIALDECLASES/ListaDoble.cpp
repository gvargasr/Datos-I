
#include <iostream>
using namespace std;

class nodo {
   public:
    nodo(int v)
    {
       valor = v;
       siguiente = NULL;
       anterior =NULL;
    }

nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo *siguiente;
    nodo *anterior;
    
        
   friend class listaD;
};

typedef nodo *pnodo;

class listaD {
   public:
    listaD() { primero =  NULL; }
    ~listaD();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    
   private:
    pnodo primero;
  
};
listaD::~listaD()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaD::largoLista(){
    int cont=0;

    pnodo aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void listaD::InsertarInicio(int v)
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodo (v,primero);
     primero->siguiente->anterior=primero;
   }
}
//Otra forma ultimas dos lineas
// pnodo nuevo=new nodo(v);
//nuevo->siguiente=primero;
//primero->anterior=nuevo;
//primero=nuevo;
 
void listaD::InsertarFinal(int v)
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);
       
   }
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
        aux->siguiente->anterior=aux;       
      }    
}
//Otra forma cambia las ultimas dos instrucciones
//pnodo nuevo= new nodo(v);
//nuevo->anterior=aux;
//aux->siguiente=nuevo;


void listaD::InsertarPos(int v,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodo(v);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(v);    
        else
        {
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaD::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodo
		 {
        	pnodo temp=primero;
            primero= NULL;
            delete temp;
            } 
			else 
			{

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaD::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodo temp=primero;
            primero= NULL;
            delete temp;
            } 
			else
			{

                pnodo aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;            
                delete aux;
            }
        }
}



void listaD:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Lista vacia" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Error en posicion" << endl;
        }
        else
        {
        if(pos==1)
           BorrarInicio();
        else
        {
          if (pos == largoLista())   
             BorrarFinal();
          else
          {   
            int cont=2;
            pnodo aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaD::Mostrar()
{
   nodo *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
   }
   cout << endl;
}


int main()
{
   listaD Lista;
   
    
   
   Lista.InsertarInicio(20);    // 2 20 10 11
   Lista.InsertarInicio(2);
   Lista.InsertarFinal(10);
   Lista.InsertarFinal(11);
   Lista.InsertarFinal(110);
   Lista.InsertarFinal(116);
   Lista.InsertarPos(5, 4);
 /*  Lista.InsertarPos(6, 4);
   Lista.InsertarInicio(30);
   Lista.InsertarInicio(1);   
   Lista.InsertarFinal(5);
   Lista.InsertarPos(1, 3);*/
  Lista.Mostrar();
  /* Lista.BorrarInicio();
   Lista.Mostrar();
   Lista.BorrarFinal();
   Lista.Mostrar();*/
   /*Lista.InsertarInicio(2);
   Lista.Mostrar();*/
 //  Lista.BorrarPosicion(5);
   //Lista.Mostrar();
     cout << Lista.largoLista();
    Lista.~listaD();

   
  
  
   cin.get();
   return 0;
}
