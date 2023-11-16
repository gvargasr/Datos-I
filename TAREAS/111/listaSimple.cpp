#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class nodo { // Constructores
   public:
   	
   	
nodo(string v)//3
    {
       valor = v;
       siguiente = NULL;
    }

nodo(string v, nodo  *signodo)
    {
       valor = v;
       siguiente = signodo;
    }


 //  private:
    string valor="";
    nodo *siguiente;// Clase Autoreferencia
    
        
   friend class lista;
};

typedef nodo *pnodo; //Alias

//void no retorna nada
//bool retorna False o True
//int retorna entero

class lista {
   public:
    lista() { primero =  NULL; }//constructor
    ~lista();//destructor
    
    void InsertarInicio(string v);//No retornan nada
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    void BorrarNodo(string valor);
    int largoLista();// retorno un valor numerico
    void MostrarPila();
    void MostrarCola();
    bool Buscar(string v);


    
//   private:
    pnodo primero;
   
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero= NULL;
}

int lista::largoLista(){
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

void lista::InsertarInicio(string v)//3 10 265
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);//6
     
   }
   else
   {
     //primera forma
 //  primero=new nodo (v,primero);
    //segunda forma
    pnodo nuevo=new nodo(v);
    nuevo->siguiente=primero;
    primero=nuevo;
     
    
    
     
   }
}
 
void lista::InsertarFinal(string v)//76
{
   if (ListaVacia())
     primero = new nodo(v);
   else
      { 
      //primera forma
	    //pnodo aux = primero;
      //  while ( aux->siguiente != NULL)
      //   aux= aux->siguiente;
      //  aux->siguiente=new nodo(v);
       
       //segunda forma 
       pnodo aux = primero;
        while ( aux->siguiente != NULL)
         aux= aux->siguiente;
        pnodo nuevo=new nodo(v);
        aux->siguiente=nuevo;
      }    
}


void lista::InsertarPos(string v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1)
		{
        	//OPcion1
          pnodo nuevo = new nodo(v);
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
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
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

void lista::BorrarInicio()
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



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1)
		{
        	pnodo temp=primero;
        	primero=primero->siguiente;
        	delete temp; //BorrarInicio();
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
            delete temp;
            }
        }
     }

}

void lista::BorrarNodo(string valor) {
    pnodo temp = primero;
    pnodo anterior = NULL;

    if (temp != NULL && temp->valor == valor) {
        primero = temp->siguiente;
        delete temp;
        return;
    }

    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }

    // If the node with the desired value is found, delete it
    if (temp == NULL) {
        cout << "El valor " << valor << " no se encuentra en la lista." << endl;
        return;
    }

    anterior->siguiente = temp->siguiente;
    delete temp;
    cout << "Nodo con valor " << valor << " eliminado de la lista." << endl;
}

bool lista::Buscar(string valor) {
    pnodo temp = primero;
    pnodo anterior = NULL;

    if (temp != NULL && temp->valor == valor) {
        primero = temp->siguiente;
        return true;
    }

    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }

    // If the node with the desired value is found, delete it
    if (temp == NULL) {
        cout << "El valor " << valor << " no se encuentra en la lista." << endl;
        return false;
    }

    return true;
}
void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos AQUI";  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}




void lista::MostrarPila()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos AQUI";  
   else
   {
   		ofstream outFile("Profundidad.txt", ios::app);
		outFile << "\t.: PILA :." << endl << endl << endl;
       
   		aux = primero;
		while(aux) 
		{

			if (outFile.is_open()) {
				outFile << aux->valor << " "  << endl;
			}
			else {
				cout << "No se pudo abrir el archivo." << endl;
			}
		    //cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		outFile << endl << "Sale: "<<primero->valor << " "  << endl;
		outFile.close();
   }
}

void lista::MostrarCola()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos AQUI";  
   else
   {
   		ofstream outFile("Anchura.txt", ios::app);
		outFile << "\t.: COLA :." << endl << endl << endl;
       
   		aux = primero;
		while(aux) 
		{

			if (outFile.is_open()) {
				outFile << aux->valor << " "  << endl;
			}
			else {
				cout << "No se pudo abrir el archivo." << endl;
			}
		    //cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		outFile << endl << "Sale: "<<primero->valor << " "  << endl;
		outFile.close();
   }
}


//int main()
//{
//   lista L1;//instancia null
//   
//    
// 
//   cout<< "***************************************************************************************"<<endl;
//   L1.InsertarInicio("A");
// //  Lista.InsertarInicio(2);
// //  Lista.InsertarFinal(10);
//    L1.Mostrar();
//   cout<<endl;
//   cout<<endl;
//   L1.InsertarInicio("B");
//   L1.Mostrar();
//   L1.InsertarInicio("C");
//   L1.Mostrar();
//   L1.InsertarFinal("D");
//   L1.Mostrar();
//   L1.InsertarFinal("E");
//   L1.Mostrar();
//   L1.InsertarPos("F",1);
//   L1.Mostrar();
//   L1.BorrarInicio();
//   L1.Mostrar();
//   L1.BorrarFinal();
//   L1.Mostrar();
//   L1.BorrarNodo("X");
//   L1.Mostrar();
//   cout << L1.largoLista();
//   
//   return 0;
//}
