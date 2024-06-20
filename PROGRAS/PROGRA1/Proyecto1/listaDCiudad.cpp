
#include <iostream>
#include <string>
#include <fstream>
#include "listaDCRest.cpp"

using namespace std;

class nodoLDCiudad {
   public: 
    nodoLDCiudad(int codigo, string nombre)
    {
       cod = codigo;
       ciudad = nombre;
       siguiente = NULL;
       anterior =NULL;
       listaRestaurante = new listaDCRest();
    }

nodoLDCiudad(int codigo, string nombre,  nodoLDCiudad * signodo)
    {
       cod = codigo;
       ciudad = nombre;
       siguiente = signodo;
       listaRestaurante = new listaDCRest();
    }


    int cod;
    string ciudad;
    listaDCRest *listaRestaurante = NULL;
    nodoLDCiudad *siguiente;
    nodoLDCiudad *anterior;
       
   friend class listaDCiudad;
};

typedef nodoLDCiudad *pnodoCiudad;

class listaDCiudad {
   public:
    listaDCiudad() { primero =  NULL; }
    ~listaDCiudad();
    
    void InsertarInicio(int codigo, string nombre);
    void InsertarFinal(int codigo, string nombre);
    void InsertarPos (int codigo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
	void InsertarRestaurante(int codigo, string nombre, listaDCRest *listaR);
	void MostrarListaRest();
	pnodoRest GetListaRest();
	pnodoCiudad EntregarListaCiudad();
	bool buscarCiudad(int codigo);
	pnodoCiudad GetPrimero();
	int GetCodigo(pnodoCiudad nodo);
	int buscarPos(int codigo);
	void MostrarPosicion(int pos);
	void reporteCiudades(string pais);


  
    pnodoCiudad primero;
  
};

int listaDCiudad::GetCodigo(pnodoCiudad nodo){
	return nodo->cod;
}

pnodoCiudad listaDCiudad::GetPrimero(){
	pnodoCiudad aux = primero;
	 return aux;
}


//Insertar Restaurante desde ListaCiudad
void listaDCiudad::InsertarRestaurante(int codigo, string nombre, listaDCRest *listaR){
	listaR->InsertarFinal(codigo,nombre);
}

//Mostrar Lista de Restaurantes
void listaDCiudad::MostrarListaRest(){
	pnodoCiudad aux = primero;
	aux->listaRestaurante->Mostrar();	
}

//Pedir Lista de Rest
pnodoRest listaDCiudad::GetListaRest(){
	pnodoCiudad aux = primero;
	return aux->listaRestaurante->EntregarListaRest();
}

//EntregaListaCiudad
pnodoCiudad listaDCiudad::EntregarListaCiudad(){
	return primero;
}

bool listaDCiudad::buscarCiudad(int codigo){
	if(ListaVacia()){
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;
		return false;
	}
	else
	{
		pnodoCiudad aux=primero;
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

listaDCiudad::~listaDCiudad()
{
   pnodoCiudad aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}



void listaDCiudad::reporteCiudades(string pais)
{
   nodoLDCiudad *aux;
   
	aux = primero;
    ofstream archivo_salida("Reporte_Ciudades_"+pais+".txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
    archivo_salida << "REPORTE LISTA CIUDADES DE "<<pais<<endl<<endl<<endl;
    while(aux) {
   		archivo_salida << aux->cod << ":"<<aux->ciudad<< "\n";
        aux = aux->siguiente;
    }
    cout << endl;
    archivo_salida.close();
    cout << "Reporte generado";
}

int listaDCiudad::largoLista(){
    int cont=0;

    pnodoCiudad aux;
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

void listaDCiudad::InsertarInicio(int codigo, string nombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoLDCiudad(codigo, nombre);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoLDCiudad (codigo, nombre, primero);
     primero->siguiente->anterior=primero;
   }
}

void listaDCiudad::InsertarFinal(int codigo, string nombre){
   if (ListaVacia())
   {
   
     primero = new nodoLDCiudad(codigo, nombre);
     cout<<"Ciudad agregada: "<<codigo<<":"<<nombre<<endl;
       
   }
   else{ 
		pnodoCiudad aux = primero;	  
        while ( aux->siguiente != NULL && aux->cod!=codigo)
          aux= aux->siguiente;
        if(aux->cod!=codigo){
      		aux->siguiente=new nodoLDCiudad(codigo, nombre);
        	aux->siguiente->anterior=aux;
        	cout<<"Ciudad agregada: "<<codigo<<":"<<nombre<<endl;
		}
		else{
		cout<<"Codigo de ciudad ya se encuentra, no fue agregada"<<endl;	
		}
	}
}


void listaDCiudad::InsertarPos(int codigo, string nombre,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoLDCiudad(codigo, nombre);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(codigo, nombre);    
        else
        {
             pnodoCiudad aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoCiudad nuevo= new nodoLDCiudad(codigo, nombre);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaDCiudad::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodo
		 {
        	pnodoCiudad temp=primero;
            primero= NULL;
        	cout<<"Ciudad eliminada: "<<temp->cod<<":"<<temp->ciudad<<endl;
            delete temp;
            } 
			else 
			{

                pnodoCiudad aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
            	pnodoCiudad temp = aux->siguiente;
            	cout<<"Ciudad eliminada: "<<temp->cod<<":"<<temp->ciudad<<endl;
            	aux->siguiente= NULL;
                delete temp;
            }
        }
}

void listaDCiudad::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoCiudad temp=primero;
            primero= NULL;
            cout<<"Ciudad eliminada: "<<temp->cod<<":"<<temp->ciudad<<endl;
            delete temp;
            } 
			else
			{

            pnodoCiudad aux = primero;
            primero=primero->siguiente;   
			primero->anterior=NULL; 
		    cout<<"Ciudad eliminada: "<<aux->cod<<":"<<aux->ciudad<<endl;           
            delete aux;
            }
        }
}

int listaDCiudad::buscarPos(int codigo){
	if(ListaVacia()){
		return -1;
	}
	else
	{
		pnodoCiudad aux=primero;
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

void listaDCiudad:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Aun no hay ciudades registrados." <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Ciudad no se encuentra." << endl;
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
            pnodoCiudad aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoCiudad temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            cout<<"Ciudad eliminada: "<<temp->cod<<":"<<temp->ciudad<<endl;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}

void listaDCiudad::Mostrar()
{
   nodoLDCiudad *aux;
   
   aux = primero;
   while(aux) {
      cout << aux->cod << ":"<<aux->ciudad<< "\n";
      aux = aux->siguiente;
   }
   cout << endl;
}

void listaDCiudad:: MostrarPosicion(int pos)
{
    if(ListaVacia())
    {
    	cout << "Aun no hay ciudades registrados." <<endl;
    }else{
        if((pos>largoLista())||(pos<0))//no validas
        {
        	cout << "Ciudad no se encuentra." << endl;
        }else{
        	if(pos==1)
        	{
        		pnodoCiudad aux=primero;
				cout<<"Ciudad encontrada: "<<aux->cod<<":"<<aux->ciudad<<endl;
			}else{
          		int cont=2;
            	pnodoCiudad aux=primero;
            	while(cont<pos)
            		{
            		aux=aux->siguiente;
            		cont++;
            		}
            		aux=aux->siguiente;
            	cout<<"Ciudad encontrada: "<<aux->cod<<":"<<aux->ciudad<<endl;
        	}//else
    	}//else
	}//else
}
/*
int main()
{
   listaDCiudad Lista;
   
    
   
   Lista.InsertarFinal(345, "David");    // 2 20 10 11
   Lista.InsertarFinal(987, "Orlando");
   Lista.InsertarFinal(234,"Guadalajara");
   Lista.InsertarFinal(34,"Bocas");
   Lista.InsertarFinal(40211,"Barva");

  Lista.Mostrar();

     cout << Lista.largoLista();
    Lista.~listaDCiudad();

   
  
  
 //  cin.get();
   return 0;
}
*/
