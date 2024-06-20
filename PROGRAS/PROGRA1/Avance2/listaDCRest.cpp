
#include <iostream>
#include <fstream>
#include "listaDMenu.cpp"

using namespace std;

class nodoLDCRest {
   public: 
    nodoLDCRest(int codigo, string nombre)
    {
       cod = codigo;
       rest = nombre;
       counter = 0;
       siguiente = NULL;
       anterior =NULL;
       listaMenu = new listaDMenu();

    }

   nodoLDCRest(int codigo, string nombre, nodoLDCRest * signodo)
    {
       cod = codigo;
       rest = nombre;
       counter = 0;
       siguiente = signodo;
       listaMenu = new listaDMenu();
       

    }

    int cod, counter;
    string rest;
    listaDMenu *listaMenu = NULL;
    nodoLDCRest *siguiente;
    nodoLDCRest *anterior;
    
        
   friend class listaDCRest;
};
typedef nodoLDCRest *pnodoRest;

class listaDCRest {
   public:
    listaDCRest() { primero = NULL; }
    ~listaDCRest();
    
    void InsertarInicio(int codigo, string nombre);
    void InsertarFinal(int codigo, string nombre);
    void InsertarPos (int codigo, string nombre, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    void InsertarMenu(int codigo, string nombre, listaDMenu *listaM);
    void MostrarListaMenu();
	pnodoMenu GetListaMenu();
	pnodoRest EntregarListaRest();
	pnodoRest GetPrimero();
	int buscarPos(int codigo);
	void MostrarPosicion(int pos);
	void reporteRestaurante(string ciudad);
	int codigoTop();
	pnodoRest buscarMayor();




    
//   private:
    pnodoRest primero;
   
};

pnodoRest listaDCRest::GetPrimero(){
	return primero;
}




// Insertar menu desde ListaRest
void listaDCRest::InsertarMenu(int codigo, string nombre, listaDMenu *listaM){
	listaM->InsertarFinal(codigo, nombre);
}

//Mostrar Lista de Menu
void listaDCRest::MostrarListaMenu(){
	pnodoRest aux = primero;
	aux->listaMenu->Mostrar();	
}

//Pedir Lista de Menu
pnodoMenu listaDCRest::GetListaMenu(){
	pnodoRest aux = primero;
	return aux->listaMenu->EntregarListaMenu();
}

//EntregaListaRest
pnodoRest listaDCRest::EntregarListaRest(){
	return primero;
}
                
listaDCRest::~listaDCRest()
{
   pnodoRest aux;
   pnodoRest temp;
   
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
int listaDCRest::largoLista() //3-4-5    cont=0 1 2 3
{
    int cont=0;

    pnodoRest aux = primero->siguiente;
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


void listaDCRest::reporteRestaurante(string ciudad)
{
   pnodoRest aux=primero;
   
    ofstream archivo_salida("Reporte_Restaurantes_"+ciudad+".txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
    archivo_salida << "REPORTE LISTA RESTAURANTES DE "<<ciudad<<endl<<endl<<endl;
    while(aux->siguiente!=primero) {
   		archivo_salida << aux->cod << ":"<<aux->rest<< "\n";
        aux = aux->siguiente;
    }
    archivo_salida << aux->cod << ":"<<aux->rest<< "\n";
    cout << endl;
    archivo_salida.close();
    cout << "Reporte generado";
}


void listaDCRest::InsertarInicio(int codigo, string nombre)
{
  
   if (ListaVacia())
   {
     primero = new nodoLDCRest(codigo, nombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodoRest nuevo=new nodoLDCRest (codigo, nombre);//1
     nuevo->siguiente=primero;//2
     nuevo->anterior= primero->anterior;//3
     primero->anterior->siguiente=nuevo;//4
     nuevo->siguiente->anterior=nuevo;//5   se puede cambiar primero->anterior=nuevo;
     primero= nuevo;//6
   }
}
 
void listaDCRest::InsertarFinal(int codigo, string nombre)
{
   if (ListaVacia()){
    primero = new nodoLDCRest(codigo, nombre);
    primero->anterior=primero;
    primero->siguiente=primero;
   	cout<<"Restaurante agregado: "<<codigo<<":"<<nombre<<endl;
   }  
   else{
     pnodoRest aux = primero;
     	while ( aux->siguiente != primero && aux->cod!=codigo){
     		if(aux->cod==codigo){
     		cout<<"Codigo de restaurante ya se encuentra, no fue agregado"<<endl;	
     		}
     	aux=aux->siguiente;
		}
		if(aux->cod==codigo){
		    cout<<"Codigo de restaurante ya se encuentra, no fue agregado"<<endl;	
		}
		else{
			aux=aux->siguiente;
			pnodoRest nuevo = new nodoLDCRest(codigo, nombre);
   			nuevo->anterior = primero->anterior;
			nuevo->siguiente=primero;
  			primero->anterior->siguiente=nuevo;
 			primero->anterior=nuevo;
		   	cout<<"Restaurante agregado: "<<codigo<<":"<<nombre<<endl;
		}
	}
}    





void listaDCRest::InsertarPos(int codigo, string nombre, int pos)
{
   if (ListaVacia())
   {
     primero = new nodoLDCRest(codigo, nombre);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio(codigo, nombre);    
       else
       {
        if (pos==largoLista())
          InsertarFinal(codigo, nombre);
        else
        {     
             pnodoRest aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodoRest nuevo= new nodoLDCRest(codigo, nombre);//1
             nuevo->siguiente=aux->siguiente;//2
             aux->siguiente=nuevo;//3
             aux->siguiente->anterior=aux;//4 o puede nuevo->anterio=aux
             nuevo->siguiente->anterior=nuevo;  //5                        
        }
       }
   }
}   

void listaDCRest::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodoRest temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodoRest aux = primero; //1
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodoRest temp = aux->siguiente;//2
         aux->siguiente= primero;//3
         primero->anterior=aux;//4
         delete temp;//5
      }
    }
}

void listaDCRest::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodoRest temp= primero;
        primero= NULL;
        cout << "Restaurante borrado: "<<temp->cod<<":"<<temp->rest<< endl;
        delete temp;
     }
     else
     {
        pnodoRest aux = primero->anterior;//1
        pnodoRest temp= primero;//2
        aux->siguiente=primero->siguiente;//3
        primero=primero->siguiente; //4
        primero->anterior=aux;//5
        cout << "Restaurante borrado: "<<temp->cod<<":"<<temp->rest<< endl;
        delete temp;//6
      }
    }
}

pnodoRest listaDCRest::buscarMayor(){
	if(primero == NULL){
		return primero;
	}
   pnodoRest aux=primero;
   pnodoRest top = primero;
   		while(aux->siguiente!=primero){                        
      		if(aux->counter > top->counter){
      			top = aux;
			}  
      		aux = aux->siguiente;
     	}	
     	if(aux->counter > top->counter){
     		top = aux;
		 }
	return top;
    cout<<endl;
}



int listaDCRest::buscarPos(int codigo){
	if(ListaVacia()){
		return -1;
	}
	else
	{
		pnodoRest aux=primero;
		int cont = 1;
		while(aux->siguiente!=primero)
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
		if(aux->cod == codigo){
			return cont;
		}
		else{
		return -1;
		}
		//cout<<"El string "<<codigo<<" no se encuentra en la lista"<<endl;

	}
}

void listaDCRest:: BorrarPosicion(int pos)
{
  if(ListaVacia())
    cout << "Aun no hay restaurantes registrados." <<endl;
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
       cout << "Restaurante no se encuentra." << endl;
	}
        
    else
    {
       int cont=2;
       pnodoRest aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
        pnodoRest temp = aux->siguiente;
       	aux->siguiente=aux->siguiente->siguiente;
       	aux->siguiente->anterior=aux;
        cout << "Restaurante borrado: "<<temp->cod<<":"<<temp->rest<< endl;
       delete temp;
     }
    }
  }
}

// Codigo de restaurante mas buscado 
/*int listaDCRest::codigoTop()
{
	int count = 0;
	int codTop = 0;
   pnodoRest aux=primero;
   while(aux->siguiente!=primero)
     {
      if(aux->counter > count){
      	count = aux->counter;
      	codTop = aux->cod;
      	aux = aux->siguiente;
	  }
	  else{
	  	aux = aux->siguiente;
	  }                          

     }
     if(aux->counter > count){
     	count = aux->counter;
      	codTop = aux->cod;
	 }
	return codTop;
}   */

void listaDCRest::Mostrar()
{
   pnodoRest aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->cod<<":"<<aux->rest << "\n";
      aux = aux->siguiente;
     }
     cout<<aux->cod<<":"<<aux->rest << "\n";
     
     cout<<endl;

}   

void listaDCRest:: MostrarPosicion(int pos)
{
  	if(ListaVacia())
    	cout << "Aun no hay restaurantes registrados." <<endl;
  	else{
   if((pos==1))
   {
   	pnodoRest aux=  primero;
   	cout << "Restaurante encontrado: "<<aux->cod<<":"<<aux->rest<< endl;
   	aux->counter++;
   }else{
    if(pos>largoLista()||(pos<=0))
    {
       cout << "Restaurante no se encuentra." << endl;
	}else{
       int cont=2;
       pnodoRest aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
        aux=aux->siguiente;
        aux->counter++;
        cout << "Restaurante encontrado: "<<aux->cod<<":"<<aux->rest<< endl;
     }
    }
  }
}

/*
int main()
{
   listaDCRest Lista;
   
    
   
   Lista.InsertarFinal(34, "McPanama");    // 2 20 10 11
   Lista.InsertarFinal(456, "Disney Springs");
   Lista.InsertarFinal(876,"Mac");
   Lista.InsertarFinal(234,"McBocas");
   Lista.InsertarFinal(2341,"X");
   Lista.InsertarMenu(1,"Combo1");
   Lista.MostrarListaMenu();
   Lista.Mostrar();
     cout << Lista.largoLista();
    Lista.~listaDCRest();
	
   
  
  
 //  cin.get();
   return 0;
}
*/
