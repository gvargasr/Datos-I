
#include <iostream>
#include <string>
using namespace std;

class nodoLDCompra {
   public:
   	nodoLDCompra()
    {
    	cod = -1;
    	nomProd = "";
		kcal = -1;
    	precio = -1;
    	cantidad = -1;
    	siguiente = NULL;
    	anterior =NULL;
	}
    nodoLDCompra(int codigo, string nombre,int cal, int price,int cant)
    {
       cod = codigo;
       nomProd = nombre;
       kcal = cal;
       precio = price;
       cantidad = cant;
       siguiente = NULL;
       anterior =NULL;
    }

nodoLDCompra(int codigo, string nombre, int kcal, int precio, int cant, nodoLDCompra * signodo)
    {
       cod = codigo;
       nomProd = nombre;
       kcal = kcal;
       precio = precio;
       cantidad = cant;
       siguiente = signodo;
    }

//   private:
    int cod,kcal,precio,cantidad;
    string nomProd;
    nodoLDCompra *siguiente;
    nodoLDCompra *anterior;
    
        
   friend class listaDProducto;
};

typedef nodoLDCompra *pnodoComp;

class listaDCompra {
   public:
    listaDCompra() { primero =  NULL; }
    ~listaDCompra();
    
    void InsertarInicio(int codigo, string nombre, int kcal, int precio,int cant);
    void InsertarFinal(int codigo, string nombre, int kcal, int precio,int cant);
    void InsertarPos (int codigo, string nombre, int kcal, int precio,int cant, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    pnodoComp GetPrimero();
    int buscarPos(int codigo);
    void MostrarPosicion(int pos);
	void ModPosicion(int codigo, string nombre, int kcal, int precio,int pos,int cant);
	void InsertarModInicio(int codigo, string nombre, int kcal, int precio,int cant);
	void BorrarModPosicion(int pos);
    
 //  private:
    pnodoComp primero;
  
};

listaDCompra::~listaDCompra()
{
   pnodoComp aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaDCompra::largoLista(){
    int cont=0;

    pnodoComp aux;
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

void listaDCompra::InsertarInicio(int codigo, string nombre, int kcal, int precio,int cant)
{
   if (ListaVacia())
   {
     primero = new nodoLDCompra( codigo, nombre, kcal, precio, cant);
     primero->anterior=NULL;     
   }
   else
   {
   	pnodoComp aux = primero;	  
        while (aux->siguiente != NULL && aux->cod!=codigo)
        aux= aux->siguiente;
        if(aux->cod!=codigo){
        	primero=new nodoLDCompra (codigo, nombre, kcal, precio, cant, primero);
     		primero->siguiente->anterior=primero;
			cout<<"Producto agregado: "<<codigo<<":"<<nombre<<":"<<kcal<<":"<<precio<<":"<<cant<<endl;
		}
		else{
			aux->cantidad=aux->cantidad + cant;
   }
}
}



void listaDCompra::InsertarFinal(int codigo, string nombre,int kcal, int precio,int cant)
{
   if (ListaVacia()){
    	primero = new nodoLDCompra(codigo, nombre, kcal, precio,cant);
     	cout<<"Producto agregado: "<<codigo<<":"<<nombre<<":"<<kcal<<":"<<precio<<":"<<cant<<endl;
   }
   else{ 
		pnodoComp aux = primero;	  
        while ( aux->siguiente != NULL && aux->cod!=codigo)
        aux= aux->siguiente;
        if(aux->cod!=codigo){
        	aux->siguiente=new nodoLDCompra(codigo, nombre, kcal, precio,cant);
        	aux->siguiente->anterior=aux;
			cout<<"Producto agregado: "<<codigo<<":"<<nombre<<":"<<kcal<<":"<<precio<<":"<<cant<<endl;
		}
		else{
			aux->cantidad=(aux->cantidad + cant);
		}	
	}
}


void listaDCompra::InsertarPos(int codigo, string nombre, int kcal, int precio,int cant,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoLDCompra(codigo, nombre, kcal, precio,cant);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(codigo, nombre, kcal, precio,cant);    
        else
        {
             pnodoComp aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoComp nuevo= new nodoLDCompra(codigo, nombre, kcal, precio,cant);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaDCompra::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodo
		 {
        	pnodoComp temp=primero;
            primero= NULL;
            cout << "Producto borrado: "<<temp->cod<<":"<<temp->nomProd<< endl;
            delete temp;
            } 
			else 
			{

                pnodoComp aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              	pnodoComp temp = aux->siguiente;
                cout << "Producto borrado: "<<temp->cod<<":"<<temp->nomProd<< endl;            
                aux->siguiente= NULL;      
                delete temp;
            }
        }
}

void listaDCompra::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoComp temp=primero;
            primero= NULL;
            cout << "Producto borrado: "<<temp->cod<<":"<<temp->nomProd<< endl;
            delete temp;
            } 
			else
			{

                pnodoComp aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;
				cout << "Producto borrado: "<<aux->cod<<":"<<aux->nomProd<< endl;            
                delete aux;
            }
        }
}

int listaDCompra::buscarPos(int codigo){
	if(ListaVacia()){
		return -1;
	}
	else
	{
		pnodoComp aux=primero;
		int cont = 1;
		while(aux!=NULL)
		{
			if(aux->cod == codigo){
				cout<<cont;
			//cout<<"El string "<<codigo<<" si se encuentra en la lista."<<endl;
			return cont;
		}
			else{
			aux=aux->siguiente;
			cont=cont+1;
			}
		}
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;
		return -1;
	}
}


void listaDCompra:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Aun no hay productos registrados." <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Producto no se encuentra." << endl;
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
            pnodoComp aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoComp temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            cout << "Producto borrado: "<<temp->cod<<":"<<temp->nomProd<< endl;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaDCompra::Mostrar()
{
   nodoLDCompra *aux;
   //int codigo, string nombre, int kcal, int precio
   aux = primero;
   while(aux) {
      cout << aux->cod << ":"<<aux->nomProd<<":"<<aux->kcal<<":"<<aux->precio<< "\n";
      aux = aux->siguiente;
   }
   cout << endl;
}

pnodoComp listaDCompra::GetPrimero(){
	return primero;
}

void listaDCompra::MostrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Aun no hay productos registrados." <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Producto no se encuentra." << endl;
        }
        else
        {
        if(pos==1)
        {
			pnodoComp aux=  primero;
			cout << "Producto encontrado: "<<aux->cod<<":"<<aux->nomProd<<":"<<aux->kcal<<":"<<aux->precio<<endl;        	
		}
        else
        {
            int cont=2;
            pnodoComp aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            aux=aux->siguiente;
            cout << "Producto encontrado: "<<aux->cod<<":"<<aux->nomProd<<":"<<aux->kcal<<":"<<aux->precio<<endl;
          }//else
        }//else
      }//else
}

void listaDCompra::ModPosicion(int codigo, string nombre, int kcal, int precio,int pos,int cant)
{
     if(ListaVacia())
     {
              cout << "Aun no hay productos registrados." <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Producto no se encuentra." << endl;
        }
        else
        {
        if(pos==1)
        {
			pnodoComp aux=  primero;
			BorrarModPosicion(pos);
			InsertarModInicio(codigo, nombre,kcal,precio,cant);     	
		}
        else
        {
            int cont=2;
            pnodoComp aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            aux=aux->siguiente;
            BorrarModPosicion(pos);
            InsertarPos(codigo,nombre,kcal,precio,pos,cant);
          }//else
        }//else
      }//else
}

void listaDCompra:: BorrarModPosicion(int pos)
{
        if(pos==1)
        {
		BorrarInicio();
		}
           
        else
        {
          if (pos == largoLista())   
             BorrarFinal();
          else
          {   
            int cont=2;
            pnodoComp aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoComp temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            delete temp;
          }//else
        }//else

}
void listaDCompra::InsertarModInicio(int codigo, string nombre, int kcal, int precio,int cant)
{
   	pnodoComp aux = primero;	  
        while (aux->siguiente != NULL && aux->cod!=codigo)
        aux= aux->siguiente;
        if(aux->cod!=codigo){
        	primero=new nodoLDCompra (codigo, nombre, kcal, precio, cant, primero);
     		primero->siguiente->anterior=primero;
     		cout << "Producto modificado: "<<aux->cod<<":"<<aux->nomProd<<":"<<aux->kcal<<":"<<aux->precio<<aux->cantidad<<endl;
		}
		else{
			aux->cantidad=aux->cantidad + cant;
			cout << "Producto modificado: "<<aux->cod<<":"<<aux->nomProd<<":"<<aux->kcal<<":"<<aux->precio<<aux->cantidad<<endl;
   }
}


