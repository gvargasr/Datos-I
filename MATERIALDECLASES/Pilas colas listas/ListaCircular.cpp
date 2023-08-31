
#include <iostream>
using namespace std;

class nodo { 
public:  
      nodo(int v)  
	   {  valor = v;     
	     siguiente = NULL;    
		 }

nodo(int v, nodo * signodo)
    {
       valor = v;
       siguiente = signodo;
    }

   private:
    int valor;
    nodo *siguiente;
    
        
   friend class listaC;
};

typedef nodo *pnodo;

class listaC {
   public:
    listaC() { primero =  NULL; }
    ~listaC();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
    
};

listaC::~listaC()
{
	pnodo aux=primero;
	
	while (aux)
	{
	
      pnodo aux1=primero;
      pnodo tempo = primero;
   
      while(aux1->siguiente!=primero)
	
        aux1=aux1->siguiente;
    primero = primero->siguiente;
	aux1->siguiente=primero;
	delete tempo;
	aux=primero;
   }
   cout<<"se borro todo";
    
   
   
}

int listaC::largoLista(){
    int cont=0;

    pnodo aux= primero;
    if(ListaVacia())
        return cont;
    else
    {
      while(aux->siguiente!=primero)
      {
        cont++;        
       aux=aux->siguiente;
      }
      cont=cont+1;
      return cont;
     }
}

void listaC::InsertarInicio(int v)
{
   if (ListaVacia())
   {
     pnodo nuevo= new nodo(v);
     primero = nuevo;
     nuevo->siguiente=primero;
   }  
   else
   {
    pnodo nuevo= new nodo(v);
    pnodo aux=primero;
    while (aux->siguiente!=primero)
       aux= aux->siguiente;
    nuevo->siguiente=primero;   
    aux->siguiente=nuevo;
    primero=nuevo;   
   } 
}
 
void listaC::InsertarFinal(int v)
{
   if (ListaVacia())
   {
     pnodo nuevo= new nodo(v);
     primero = nuevo;
     nuevo->siguiente=primero;
   }  
   else
   { 
      pnodo nuevo=new nodo(v);
      pnodo aux = primero;
      while (aux->siguiente!=primero)  
         aux= aux->siguiente;
      nuevo->siguiente= primero;
      aux->siguiente= nuevo; 
      
   }    
}


void listaC::InsertarPos(int v,int pos)
{
   if (ListaVacia())
   {
     pnodo nuevo= new nodo(v);
     primero = nuevo;
     nuevo->siguiente=primero;
   } 
   else
   {
     if(pos <=1)
     {
       InsertarInicio(v);
     }      
     else
     {
       pnodo aux= primero;
       int i =2;
       while((i != pos )&&(aux->siguiente!= primero))
       {
          i++;
          aux=aux->siguiente;
       }
       pnodo nuevo= new nodo(v);
       nuevo->siguiente=aux->siguiente;
       aux->siguiente=nuevo;
       
      }
     }
}
      
void listaC::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodo aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodo temp = aux->siguiente;
         aux->siguiente= primero;
         delete temp;
      }
    }
}

void listaC::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodo temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodo aux = primero;
        pnodo temp= primero;
        while (aux->siguiente!=primero)
            aux= aux->siguiente;
        primero=primero->siguiente;                
        aux->siguiente=primero;
        delete temp;
      }
    }
}

void listaC:: borrarPosicion(int pos)
{
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<=0))
     cout << "Error en posicion" << endl;
   else
    {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       pnodo aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodo temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}
 
void listaC::Mostrar()
{
   pnodo aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
     }
     cout<<aux->valor<<"->";
     cout<<endl;
}   

int main()
{
   listaC Lista;
   
    
  Lista.InsertarInicio(4); 
  Lista.InsertarInicio(56);
  Lista.InsertarInicio(79);
  /*Lista.InsertarInicio(1);  */
  Lista.InsertarFinal(80);
  Lista.InsertarPos(90, 3);
 /* Lista.InsertarPos(6, 4);
  Lista.InsertarPos(17, 1);*/
  Lista.Mostrar();
  cout<< Lista.largoLista()<<endl;
  cout<<endl;
 // Lista.BorrarInicio();
  //Lista.Mostrar();
 //Lista.BorrarFinal();
 // Lista.Mostrar();
  Lista.borrarPosicion(3);
  Lista.Mostrar();
 
 
/* Lista.borrarPosicion(11);
  Lista.Mostrar();*/
  

   cin.get();
   return 0;
}
