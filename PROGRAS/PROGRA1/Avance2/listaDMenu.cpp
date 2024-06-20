 
#include <iostream>
#include <string>
#include <fstream>
#include "listaDProducto.cpp"

using namespace std;

class nodoLDMenu {
   public:
    nodoLDMenu(int codigo, string nombre)
    {
       cod = codigo;
       counter = 0;
       nomMenu = nombre;
       siguiente = NULL;
       anterior =NULL;
       listaProd = new listaDProducto();
    }

nodoLDMenu(int codigo, string nombre, nodoLDMenu * signodo)
    {
       cod = codigo;
       counter = 0;
       nomMenu = nombre;
       siguiente = signodo;
       listaProd = new listaDProducto();
       
    }
	
//   private:
    int cod,counter;
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
	void MostrarPosicion(int pos);
	void reporteMenu(string rest);
	pnodoMenu buscarMayorMenu();

    
//   private:
    pnodoMenu primero;
  
};

pnodoMenu listaDMenu::GetPrimero(){
	return primero;
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


 
void listaDMenu::reporteMenu(string rest)
{
   nodoLDMenu *aux;
   aux = primero;

	ofstream archivo_salida("Reporte_Menu_"+rest+".txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
    archivo_salida << "REPORTE LISTA MENU DE "<<rest<<endl<<endl<<endl;

    while(aux) {
       archivo_salida << aux->cod << ":"<<aux->nomMenu<< "\n";
       aux = aux->siguiente;
    }
    cout << endl;
    archivo_salida.close();
	cout << "Reporte generado";
}

pnodoMenu listaDMenu::buscarMayorMenu(){
	if(primero == NULL){
		return primero;
	}
   pnodoMenu aux=primero;
   pnodoMenu top = primero;
   		while(aux->siguiente!=NULL){                        
      		if(aux->counter > top->counter){
      			top = aux;
			}  
      		aux = aux->siguiente;
     	}	
	return top;
    cout<<endl;
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

void listaDMenu:: MostrarPosicion(int pos)
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
        {
        	pnodoMenu aux=  primero;
           cout << "Menu Encontrado: "<<aux->cod<<":"<<aux->nomMenu<< endl;
           aux->counter++;
		}
        else
        {
            int cont=2;
            pnodoMenu aux=  primero;
            while(cont<pos)
            {
             aux=aux->siguiente;
             cont++;
            }
    		 aux=aux->siguiente;
            cout << "Menu encontrado: "<<aux->cod<<":"<<aux->nomMenu<< endl;
            aux->counter++;
          }//else
        }//else
      }//else

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
