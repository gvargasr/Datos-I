
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
    
        
   friend class listaDC;
};
typedef nodo *pnodo;

class listaDC {
   public:
    listaDC() { primero = NULL; }
    ~listaDC();
    
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
   private:
    pnodo primero;
   
};
                
listaDC::~listaDC()
{
   pnodo aux;
   pnodo temp;
   
   while(primero) {
      temp = primero;
      aux=primero;
      primero = primero->siguiente;
      while (aux->siguiente!=primero)
           aux= aux->siguiente;
      aux->siguiente=primero;
      
      delete temp;
      primero=NULL;
   }
   primero= NULL;
}
   

                        //  aux
int listaDC::largoLista() //3-4-5    cont=0 1 2 3
{
    int cont=0;

    pnodo aux = primero->siguiente;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {   cont=cont+1;
        while(aux!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    return cont;
    }
    
}

void listaDC::InsertarInicio(int v)
{
  
   if (ListaVacia())
   {
     primero = new nodo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodo nuevo=new nodo (v);//1
     nuevo->siguiente=primero;//2
     nuevo->anterior= primero->anterior;//3
     primero->anterior->siguiente=nuevo;//4
     nuevo->siguiente->anterior=nuevo;//5
     primero= nuevo;//6
   }
}
 
void listaDC::InsertarFinal(int v)
{
   if (ListaVacia())
     {
     primero = new nodo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   { 
     pnodo nuevo = new nodo(v);//1
     nuevo->anterior = primero->anterior;//2
     /*nuevo->siguiente=primero->anterior->siguiente;opcion para intruccion 3*/
	 nuevo->siguiente=primero;// coloca alguna de la dos 3
     primero->anterior->siguiente=nuevo;//4
     primero->anterior=nuevo;//5
    }    
}


void listaDC::InsertarPos(int v,int pos)
{
   if (ListaVacia())
   {
     primero = new nodo(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio(v);    
       else
       {
        if (pos==largoLista())
          InsertarFinal(v);
        else
        {     
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);//1
             nuevo->siguiente=aux->siguiente;//2
             aux->siguiente=nuevo;//3
             aux->siguiente->anterior=aux;//4 o puede nuevo->anterio=aux
             nuevo->siguiente->anterior=nuevo;  //5                         
        }
       }
   }
}   

void listaDC::BorrarFinal()
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
         pnodo aux = primero; //1
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodo temp = aux->siguiente;//2
         aux->siguiente= primero;//3
         primero->anterior=aux;//4
         delete temp;//5
      }
    }
}

void listaDC::BorrarInicio()
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
        pnodo aux = primero->anterior;//1
        pnodo temp= primero;//2
        aux->siguiente=primero->siguiente;//3
        primero=primero->siguiente; //4
        primero->anterior=aux;//5
        delete temp;//6
      }
    }
}

void listaDC:: BorrarPosicion(int pos)
{
    
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos==1))
      
   {
   	BorrarInicio();
   	
   }
        
   else
   {
    if(pos>largoLista()||(pos<=0))
    {
       cout << "Error en posicion" << endl;
	}
        
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
       aux->siguiente->anterior=aux;
       delete temp;
     }
    }
  }
}

void listaDC::Mostrar()
{
   pnodo aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
     }
     cout<<aux->valor<<"->";
     //EXTRA
     cout<<endl;
    /* cout<< "primero";
     cout<<endl;
     cout<<aux->siguiente->valor<<"->";
     cout<<endl;
     cout<< "ultimo";
     cout<<endl;
     cout<<primero->anterior->valor<<"->";*/
}   


int main()
{
   listaDC Lista;
   
   
   Lista.InsertarInicio(20);
   Lista.InsertarInicio(2);
   Lista.InsertarInicio(50);
   Lista.InsertarInicio(30);
   
   //30->50->5->2->20->10->96
   
  Lista.InsertarFinal(10);
   /*Lista.InsertarFinal(11);
   Lista.Mostrar();*/
   Lista.InsertarPos(5, 3);
 //  Lista.Mostrar();
   Lista.InsertarPos(96, 14);
   Lista.Mostrar();
   Lista.BorrarPosicion(5);
   Lista.Mostrar();
   Lista.BorrarInicio();
   Lista.Mostrar();
   Lista.BorrarFinal();
   Lista.Mostrar();
   Lista.BorrarInicio();
   Lista.Mostrar();
   cout<<Lista.largoLista();
   Lista.~listaDC();
 
   cin.get();
   return 0;
}
