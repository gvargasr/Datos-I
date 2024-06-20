 
#include <iostream>
using namespace std;

class nodo { // Constructores
   public:
   	
   	
nodo(int v, string n)//3
    {
       valor = v;
       nombre = n;
       siguiente = NULL;
    }

nodo(int v, string n, nodo  *signodo)
    {
       valor = v;
       nombre = n;
       siguiente = signodo;
    }


   private:
   	string nombre="";
    int valor=0;
    nodo *siguiente;// Clase Autoreferencia
    
        
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
    void busqueda(int codigo);

    
   private:
    pnodo primero;
   
};


void listaClientes::busqueda(int codigo){
	if(ListaVacia()){
		cout<<"No hay clientes ingresados"<<endl<<endl;
	}
	else{
		pnodo aux=primero;
		while(aux!=NULL)
		{
			if(aux->valor == codigo){
			cout<<"Cliente encontrado: "<<aux->valor<<":"<<aux->nombre<<endl<<endl;
			return;
		}
			else
			aux=aux->siguiente;
		}
		cout<<"El cliente con cedula: "<<codigo<<" no se encuentra"<<endl<<endl;
	}
}

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


