 
#include <iostream>
#include <fstream>
#include <string>
#include "listaCompra.cpp"
using namespace std;

class nodo { // Constructores
   public:
   	
   	
nodo(int v, string n)//3
    {
       valor = v;
       nombre = n;
       siguiente = NULL;
       listaComp = new listaDCompra();
    }

nodo(int v, string n, nodo  *signodo)
    {
       valor = v;
       nombre = n;
       siguiente = signodo;
       listaComp = new listaDCompra();
    }


   //private:
   	string nombre="";
    int valor=0;
    nodo *siguiente;// Clase Autoreferencia
    listaDCompra *listaComp = NULL;
        
   friend class listaClientes;
};

typedef nodo *pnodo; //Alias

//void no retorna nada
//bool retorna False o True
//int retorna entero

class listaClientes {
   public:
    listaClientes() { primero =  NULL; }//constructor
    ~listaClientes();//destructor
    
    void InsertarInicio(int v, string n);//No retornan nada
    void InsertarFinal(int v, string n);
    void InsertarPos (int v, string n, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();// retorno un valor numerico
    int buscarPos(int codigo);
	void MostrarPosicion(int pos);
	pnodoComp GetListaComp();
	void ModPosicion(int pos);
    void InsertarCompra(int codigo, string nombre, int kcal, int precio, int cant, listaDCompra *listaP);
    pnodo GetPrimero();
    void reporteClientes();

    
    
   //private:
    pnodo primero;
   
};

listaClientes::~listaClientes()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero= NULL;
}

void listaClientes::InsertarCompra(int codigo, string nombre, int kcal, int precio, int cant, listaDCompra *listaC){
	listaC->InsertarFinal(codigo,nombre,kcal,precio,cant);
}

pnodoComp listaClientes::GetListaComp(){
	pnodo aux = primero;
	return aux->listaComp->GetPrimero();
}

pnodo listaClientes::GetPrimero(){
	pnodo aux = primero;
	return aux;
}

int listaClientes::largoLista(){
    int cont=0;

    pnodo aux= primero;
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

void listaClientes::InsertarInicio(int v, string n)//3 10 265
{
   if (ListaVacia())
   {
   
     primero = new nodo(v, n);//6
     
   }
   else
   {
     //primera forma
 //  primero=new nodo (v,primero);
    //segunda forma
    pnodo nuevo=new nodo(v, n);
    nuevo->siguiente=primero;
    primero=nuevo;
     
    
    
     
   }
}
 
void listaClientes::InsertarFinal(int v, string n)//76
{
    if (ListaVacia()){
    primero = new nodo(v, n);
    cout<<"Cliente agregado: "<<v<<":"<<n<<endl; 	
	}
    else{ 
		pnodo aux = primero;	  
        while ( aux->siguiente != NULL && aux->valor!=v)
        	aux= aux->siguiente;
    	if(aux->valor!=v){
        	pnodo nuevo=new nodo(v, n);
        	aux->siguiente=nuevo;
   	     	cout<<"Cliente agregado: "<<v<<":"<<n<<endl; 
		}
		else{
			cout<<"Cedula de cliente ya se encuentra, no fue agregado"<<endl;	
		}	
	}
}


void listaClientes::InsertarPos(int v, string n, int pos)
{
   if (ListaVacia())
     primero = new nodo(v, n);
   else{
        if(pos <=1)
		{
        	//OPcion1
          pnodo nuevo = new nodo(v, n);
          nuevo->siguiente= primero;
          primero= nuevo;     
          //OPcion 2
          //InsertarInicio(v);
        }      
        else{
             nodo *aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v, n);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void listaClientes::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;;
            }
			 else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void listaClientes::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;
        } 
		else 
		{

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
        }
}

int listaClientes::buscarPos(int codigo){
	if(ListaVacia()){
		return -1;
	}
	else
	{
		pnodo aux=primero;
		int cont = 1;
		while(aux!=NULL)
		{
			if(aux->valor == codigo){
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


void listaClientes:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Aun no hay clientes registrados." <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Cliente no se encuentra." << endl;
        }else{
        if(pos==1)
		{
        	pnodo temp=primero;
        	primero=primero->siguiente;
        	cout << "Cliente borrado: "<<temp->valor<<":"<<temp->nombre<< endl;
        	delete temp; 
        }
		else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            cout << "Cliente borrado: "<<temp->valor<<":"<<temp->nombre<< endl;
            delete temp;
            }
        }
     }

}


void listaClientes::reporteClientes()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay clientes registrados";  
   else
   {
   		aux = primero;
   		ofstream archivo_salida("Reporte_Clientes.txt");
    	if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
   		}	
    	archivo_salida << "REPORTE LISTA DE CLIENTES"<<endl<<endl<<endl;
		while(aux) 
		{
			archivo_salida << aux->valor << ":"<<aux->nombre<< "\n";
		    aux = aux->siguiente;
		}
		cout << endl;
		archivo_salida.close();
    	cout << "Reporte generado";
   }
}


void listaClientes::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay clientes registrados";  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << ":"<<aux->nombre<<endl;
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}

void listaClientes:: MostrarPosicion(int pos){
    if(ListaVacia())
	{
    	cout << "Aun no hay clientes registrados." <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Cliente no se encuentra." << endl;
        }else{
        	if(pos==1)
			{
        		pnodo aux=  primero;
        		cout << "Cliente encontrado: "<<aux->valor<<":"<<aux->nombre<< endl;
        	}else{
          		int cont=2;
        		pnodo aux=  primero;
            	while(cont<pos){
             		aux=aux->siguiente;
             		cont++;
            	}
				aux=aux->siguiente;
            	cout << "Cliente encontrado: "<<aux->valor<<":"<<aux->nombre<< endl;
            }//else
        }//else
    }//else

}

void listaClientes:: ModPosicion(int pos){
    if(ListaVacia())
	{
    	cout << "Aun no hay clientes registrados." <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Cliente no se encuentra." << endl;
        }else{
        	if(pos==1)
			{
        		pnodo aux=  primero;
        		cout << "Inserte nuevo nombre"<< endl;
        		char name;
				cin >> name;
				aux->nombre = name;
        		cout << "Cliente modificado: "<<aux->valor<<":"<<aux->nombre<< endl;
        	}else{
          		int cont=2;
        		pnodo aux=  primero;
            	while(cont<pos){
             		aux=aux->siguiente;
             		cont++;
            	}
				aux=aux->siguiente;
				cout << "Inserte nuevo nombre"<< endl;
        		char name;
				cin >> name;
				aux->nombre = name;
            	cout << "Cliente modificado: "<<aux->valor<<":"<<aux->nombre<< endl;
            }//else
        }//else
    }//else

}
