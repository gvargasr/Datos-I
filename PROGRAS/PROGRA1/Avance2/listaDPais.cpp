
#include <iostream>
#include <string>
#include <fstream>
#include "listaDCiudad.cpp"

using namespace std;

class nodoLDPais { 
   public:
    nodoLDPais(int codigo, string nombre)
    {
       cod = codigo;
       pais = nombre;
       listaCiudad = new listaDCiudad();
       siguiente = NULL;
       anterior =NULL;
    }

nodoLDPais(int codigo, string nombre,  nodoLDPais * signodo)
    {
       cod = codigo;
       pais = nombre;
       listaCiudad = new listaDCiudad();
       siguiente = signodo;
    }
    
int getCodigo(){
	return cod;
}


//private:
    int cod;
    string pais;
    listaDCiudad *listaCiudad = NULL;
    nodoLDPais *siguiente;
    nodoLDPais *anterior;
    
        
   friend class listaDPais;
};

typedef nodoLDPais *pnodoPais;

class listaDPais {
   public:
    listaDPais() { primero =  NULL; }
    ~listaDPais();
    
    void InsertarInicio(int codigo, string nombre);
    void InsertarFinal(int codigo, string nombre);
    void InsertarPos (int codigo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
	void InsertarCiudad(int codigo, string nombre, listaDCiudad *listaC);
	void MostrarListaCiudad();
	listaDCiudad GetListaCiudad();
	pnodoPais EntregarListaPais();
	bool buscarPais(int codigo);
	pnodoPais GetPrimero();
	int buscarPos(int codigo);
	void MostrarPosicion(int pos);
	void reportePaises();




//	private:
    pnodoPais primero;
};

pnodoPais listaDPais::GetPrimero(){
	return primero;
}

// Insertar Ciudad desde ListaPais
void listaDPais::InsertarCiudad(int codigo, string nombre, listaDCiudad *listaC){
	listaC->InsertarFinal(codigo,nombre);
}

//Mostrar Lista de Ciudad
void listaDPais::MostrarListaCiudad(){
	pnodoPais aux;
	aux->listaCiudad->Mostrar();
	
}

//Verifica si el pais se encuentra en la lista
bool listaDPais::buscarPais(int codigo){
	if(ListaVacia()){
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;
		return false;
	}
	else
	{
		pnodoPais aux=primero;
		while(aux!=NULL)
		{
			if(aux->cod == codigo){
			//cout<<"El string "<<codigo<<" si se encuentra en la lista."<<endl;
			return true;
		}
			else
			aux=aux->siguiente;
		}
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;
		return false;
	}
}

int listaDPais::buscarPos(int codigo){
	if(ListaVacia()){
		return -1;
	}
	else
	{
		pnodoPais aux=primero;
		int cont = 1;
		while(aux!=NULL)
		{
			if(aux->cod == codigo){
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


/*Pedir Lista de Ciudad
listaDCiudad listaDPais::GetListaCiudad(){
	return primero->listaCiudad;
}*/

//EntregaListaPais
pnodoPais listaDPais::EntregarListaPais(){
	return primero;
}


listaDPais::~listaDPais()
{
   pnodoPais aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaDPais::largoLista(){
    int cont=0;

    pnodoPais aux;
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

void listaDPais::InsertarInicio(int codigo, string nombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoLDPais(codigo, nombre);
     primero->anterior=NULL;     
   }
   else
   {
        pnodoPais aux = primero;
        while ( aux->siguiente != NULL)
         aux= aux->siguiente;
        pnodoPais nuevo=new nodoLDPais(codigo,nombre);
        aux->siguiente=nuevo;
   }
}

void listaDPais::InsertarFinal(int codigo, string nombre){
   if (ListaVacia())
   {
   
     primero = new nodoLDPais(codigo, nombre);
     cout<<"Pais agregado: "<<codigo<<":"<<nombre<<endl;
       
   }
   else{ 
		pnodoPais aux = primero;	  
        while ( aux->siguiente != NULL && aux->cod!=codigo)
          aux= aux->siguiente;
        if(aux->cod!=codigo){
        	aux->siguiente=new nodoLDPais(codigo, nombre);
        	aux->siguiente->anterior=aux;
       		cout<<"Pais agregado: "<<codigo<<":"<<nombre<<endl;
		}
		else{
			cout<<"Codigo de pais ya se encuentra, no fue agregado"<<endl;	
		}
	}
}

void listaDPais::InsertarPos(int codigo, string nombre,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoLDPais(codigo, nombre);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(codigo, nombre);    
        else
        {
             pnodoPais aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoPais nuevo= new nodoLDPais(codigo, nombre);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaDPais::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodo
		 {
        	pnodoPais temp=primero;
            primero= NULL;
            cout<<"Pais eliminado: "<<temp->cod<<":"<<temp->pais<<endl;
            delete temp;
            } 
			else 
			{

                pnodoPais aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
              pnodoPais temp = aux->siguiente;
              cout<<"Pais eliminado: "<<temp->cod<<":"<<temp->pais<<endl;                
              aux->siguiente= NULL;
                      
                delete temp;
            }
        }
}

void listaDPais::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {

            pnodoPais temp=primero;
            primero= NULL;
        	cout<<"Pais eliminado: "<<temp->cod<<":"<<temp->pais<<endl;
            delete temp;
            } 
			else
			{

                pnodoPais aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;     
        		cout<<"Pais eliminado: "<<aux->cod<<":"<<aux->pais<<endl;       
                delete aux;
            }
        }
}



void listaDPais:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "No hay paises para borrar" <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Pais no se encuentra en la lista" << endl;
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
            pnodoPais aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoPais temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            cout<<"Pais eliminado: "<<temp->cod<<":"<<temp->pais<<endl;                
            delete temp;
          }//else
        }//else
      }//else
    }//else
}



void listaDPais::reportePaises()
{
   nodoLDPais *aux;
   
	aux = primero;
    ofstream archivo_salida("Reporte_Paises.txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
    archivo_salida << "REPORTE LISTA PAISES"<<endl<<endl<<endl;
    while(aux) {
   		archivo_salida << aux->cod << ":"<<aux->pais<< "\n";
        aux = aux->siguiente;
    }
    cout << endl;
    archivo_salida.close();
    cout << "Reporte generado";
}

void listaDPais::Mostrar()
{
   nodoLDPais *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->cod << ":"<<aux->pais<< "\n";
      aux = aux->siguiente;
   }
   cout << endl;
}

void listaDPais:: MostrarPosicion(int pos)
{
    if(ListaVacia())
    {
        cout << "No hay paises para borrar" <<endl;
    }else{
        if((pos>largoLista())||(pos<0))//no validas
        {
        	cout << "Pais no se encuentra en la lista" << endl;
        }else{
        	if(pos==1)
        	{
        		pnodoPais aux=  primero;
        		cout<<"Pais encontrado: "<<aux->cod<<":"<<aux->pais<<endl;      
			}else{ 
            	int cont=2;
            	pnodoPais aux=  primero;
            	while(cont<pos)
            	{
             		aux=aux->siguiente;
             		cont++;
            	}
            	aux=aux->siguiente;
            	cout<<"Pais encontrado: "<<aux->cod<<":"<<aux->pais<<endl;                
          }//else
    	}//else
    }//else
}





