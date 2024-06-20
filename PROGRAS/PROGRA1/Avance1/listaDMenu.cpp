 
#include <iostream>
#include <string>
#include "listaDProducto.cpp"

using namespace std;

class nodoLDMenu {
   public:
    nodoLDMenu(int codigo, string nombre)
    {
       cod = codigo;
       nomMenu = nombre;
       siguiente = NULL;
       anterior =NULL;
       listaProd = new listaDProducto();
    }

nodoLDMenu(int codigo, string nombre, nodoLDMenu * signodo)
    {
       cod = codigo;
       nomMenu = nombre;
       siguiente = signodo;
       listaProd = new listaDProducto();
       
    }
	
//   private:
    int cod;
    string nomMenu;
    listaDProducto *listaProd = NULL;
    nodoLDMenu *siguiente;
    nodoLDMenu *anterior;
    
        
   friend class listaDMenu;
};

typedef nodoLDMenu *pnodoMenu;

class listaDMenu {
   public:
    listaDMenu() { primero =  NULL; }
    ~listaDMenu();
    
    void InsertarInicio(int codigo, string nombre);
    void InsertarFinal(int codigo, string nombre);
    void InsertarPos (int codigo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    void Mostrar();
    int largoLista();
    void InsertarProducto(int codigo, string nombre, int kcal, int precio, listaDProducto *listaP);
    void MostrarListaProd();
	pnodoProd GetListaProd();
	pnodoMenu EntregarListaMenu();
	pnodoMenu GetPrimero();
	int buscarPos(int codigo);
	void busqueda(int pais, int ciudad, int rest, int codigo);
	
    
//   private:
    pnodoMenu primero;
  
};

pnodoMenu listaDMenu::GetPrimero(){
	return primero;
}


void listaDMenu::busqueda(int pais, int ciudad, int rest, int codigo){
	if(ListaVacia()){
		cout<<"No hay menus ingresados"<<endl<<endl;
	}
	else{
		pnodoMenu aux=primero;
		while(aux!=NULL)
		{
			if(aux->cod == codigo){
			cout<<"Menu encontrado: \nPais: "<<pais<<"\nCiudad: "<<ciudad<<"\nRestaurante: "<<rest<<"\nMenu: "<<aux->cod<<":"<<aux->nomMenu<<endl<<endl;
			return;
		}
			else
			aux=aux->siguiente;
		}
		cout<<"El menu con codigo: "<<codigo<<" no se encuentra en:\nPais: "<<pais<<"\nCiudad: "<<ciudad<<"\nRestaurante: "<<rest<<endl<<endl;
	}
}


// Insertar producto desde ListaMenu
void listaDMenu::InsertarProducto(int codigo, string nombre, int kcal, int precio, listaDProducto *listaP){
	listaP->InsertarFinal(codigo,nombre,kcal,precio);
	
}

//Mostrar Lista de Productos
void listaDMenu::MostrarListaProd(){
	pnodoMenu aux = primero;
	aux->listaProd->Mostrar();	
}

//Pedir Lista de productos
pnodoProd listaDMenu::GetListaProd(){
	pnodoMenu aux = primero;
	return aux->listaProd->GetPrimero();
}
//EntregaListaMenu
pnodoMenu listaDMenu::EntregarListaMenu(){
	return primero;
}

listaDMenu::~listaDMenu()
{
   pnodoMenu aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero=NULL;
}

int listaDMenu::largoLista(){
    int cont=0;

    pnodoMenu aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont=cont + 1;
    }
    return cont;
    }
    
}

void listaDMenu::InsertarInicio(int codigo, string nombre)
{
   if (ListaVacia())
   {
   
     primero = new nodoLDMenu( codigo, nombre);
     primero->anterior=NULL;     
   }
   else
   {
     primero=new nodoLDMenu (codigo, nombre, primero);
     primero->siguiente->anterior=primero;
   }
}

void listaDMenu::InsertarFinal(int codigo, string nombre){
   if (ListaVacia()){
   		primero = new nodoLDMenu(codigo, nombre);
		cout<<"Menu agregado: "<<codigo<<":"<<nombre<<endl;    
   }
   else{ 
		pnodoMenu aux = primero;	  
        while ( aux->siguiente != NULL && aux->cod!=codigo)
        	aux= aux->siguiente;
      	    if(aux->cod!=codigo){
        	aux->siguiente=new nodoLDMenu(codigo, nombre);
        	aux->siguiente->anterior=aux;
		   	cout<<"Menu agregado: "<<codigo<<":"<<nombre<<endl;

		}
		else{
		cout<<"Codigo de menu ya se encuentra, no fue agregado"<<endl;	
		}
	}
}

void listaDMenu::InsertarPos(int codigo, string nombre,int pos)
{
   if (ListaVacia())
    {
   
     primero = new nodoLDMenu(codigo, nombre);
     primero->anterior=NULL;     
   }
   else{
        if(pos <=1)
          InsertarInicio(codigo, nombre);    
        else
        {
             pnodoMenu aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoMenu nuevo= new nodoLDMenu(codigo, nombre);
             nuevo->siguiente=aux->siguiente;
			 nuevo->anterior=aux;
			   nuevo->siguiente->anterior=nuevo;
			   aux->siguiente=nuevo;                      
        }
        }
}
      
void listaDMenu::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL)//solo un nodo
		 {
        	pnodoMenu temp=primero;
            primero= NULL;
            cout << "Menu borrado: "<<temp->cod<<":"<<temp->nomMenu<< endl;
            delete temp;
            } 
			else 
			{

                pnodoMenu aux = primero;
                while (aux->siguiente->siguiente != NULL) 
                {
                    aux = aux->siguiente;
                }
                
              	pnodoMenu temp = aux->siguiente;
              	aux->siguiente= NULL;
             	cout << "Menu borrado: "<<temp->cod<<":"<<temp->nomMenu<< endl;
                delete temp;
            }
        }
}

void listaDMenu::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
            pnodoMenu temp=primero;
            primero= NULL;
            cout << "Menu borrado: "<<temp->cod<<":"<<temp->nomMenu<< endl;
            delete temp;
            } 
			else
			{

                pnodoMenu aux = primero;
                primero=primero->siguiente;   
				primero->anterior=NULL;
	            cout << "Menu borrado: "<<aux->cod<<":"<<aux->nomMenu<< endl;            
                delete aux;
            }
        }
}

int listaDMenu::buscarPos(int codigo){
	if(ListaVacia()){
		return -1;
	}
	else
	{
		pnodoMenu aux=primero;
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

void listaDMenu:: BorrarPosicion(int pos)
{
     if(ListaVacia())
     {
              cout << "Aun no hay menus registrados." <<endl;
     }
     else
     {
        if((pos>largoLista())||(pos<0))//no validas
        {
        cout << "Menu no se encuentra." << endl;
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
            pnodoMenu aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
            pnodoMenu temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            aux->siguiente->anterior=aux;
            cout << "Menu borrado: "<<temp->cod<<":"<<temp->nomMenu<< endl;
            delete temp;
          }//else
        }//else
      }//else
    }//else
}
 

void listaDMenu::Mostrar()
{
   nodoLDMenu *aux;
   //int codigo, string nombre, int kcal, int precio
   aux = primero;
   while(aux) {
      cout << aux->cod << ":"<<aux->nomMenu<< "\n";
      aux = aux->siguiente;
   }
   cout << endl;
}

/*
int main()
{
   listaDMenu Lista;
    
    Lista.InsertarFinal(1, "HC");
    Lista.InsertarFinal(2, "Acompañamientos");
    Lista.InsertarFinal(3, "PolloyNuggets");
    Lista.InsertarFinal(230, "Acompañamientos");
    Lista.InsertarFinal(12, "HP");
    Lista.InsertarProducto(109,"BigMac",480,2300);
    Lista.Mostrar();
    Lista.MostrarListaProd();
	cout << Lista.largoLista();
    Lista.~listaDMenu(); 
 //  cin.get();
   return 0;
}
*/
