#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

class nodo { // Constructores
   public:
   	nodo()
   	{
   		valor = "";
   		siguiente = NULL;
	   }
   	nodo(string v)
    {
       valor = v;
       siguiente = NULL;
    	}

	nodo(string v, nodo  *signodo)
    {
       valor = v;
       siguiente = signodo;
    	}
  
   private:
    string valor;
    nodo *siguiente;
    
        
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
    bool buscarNumero(string v);
    void InsertarInicio(string v);
    void InsertarFinal(string v);
    void InsertarPos (string v, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();// retorno un valor numerico
    bool buscarPosicion(int pos);
    //TC1
    void crearCola(pnodo Cola[]);
    void MostrarExpresion(pnodo primerl);
    void MostrarExpresionHuman(pnodo primerl);
    void crearPostfijo(pnodo primerl);
    void comparar(string valor, lista pilaOperActual);
    int prioridadDP(char ca);
    int prioridadFP(char ca);
    void Imprimir();
    

	

    
   private:
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
 

void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos"<<endl;  
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

void lista::Imprimir()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos"<<endl;  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
			cout << aux->valor<<" ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }	
}

void lista::MostrarExpresionHuman(pnodo primerl){
	pnodo aux=primerl->siguiente;
	if(aux==NULL){
		cout<<"No hay elementos";
	}
	else{
		while(aux!=NULL){
			cout<<aux->valor;
			aux=aux->siguiente;
		}
		cout<<endl;
	}
}

void lista::MostrarExpresion(pnodo primerl){
	pnodo aux=primerl->siguiente;
	if(aux==NULL){
		cout<<"No hay elementos";
	}
	else{
		while(aux!=NULL){
			cout<<aux->valor<<" -> ";
			aux=aux->siguiente;
		}
		cout<<endl;
	}
}




//Tarea 3

// 1. Buscar un numero en una lista.

bool lista::buscarNumero(string v){
	if(ListaVacia()){
		cout<<"El string "<<v<<" no se encuentra en la lista"<<endl;
		return false;
	}
	else
	{
		pnodo aux=primero;
		while(aux!=NULL)
		{
			if(aux->valor == v){
			cout<<"El string "<<v<<" si se encuentra en la lista."<<endl;
			return true;
		}
			else
			aux=aux->siguiente;
		}
		cout<<"El string "<<v<<" no se encuentra en la lista"<<endl;
		return false;
	}
}

//2. Escribir una función para buscar un número en una posición especifica

bool lista:: buscarPosicion(int pos){
    if(ListaVacia()){
              cout << "Lista vacia" <<endl;
              return false;
    }else{
		if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        return false;
        }
		else{
			pnodo aux=primero;
			while(pos > 1){
				aux=aux->siguiente;
				pos -= 1;
			}
			cout<<"El valor de la posicion solicitada es: "<<aux->valor<<endl;
			return true;
        }
     }

}

// lee los archivos y los agrega en la cola.

void lista::crearCola(pnodo Cola[]){
	string str;
	ifstream archivo;
	pnodo aux;
	archivo.open("Arch1.txt");
	while(getline(archivo, str)){	
		aux=Cola[0];
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodo(str);
	}
	archivo.close();
	str="";
	aux=NULL;

	
		archivo.open("Arch2.txt");
	while(getline(archivo, str)){	
		aux=Cola[1];
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodo(str);
	}
	archivo.close();
	str="";
	aux=NULL;
	
		archivo.open("Arch3.txt");
	while(getline(archivo, str)){	
		aux=Cola[2];
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodo(str);
	}
	archivo.close();
	str="";
	aux=NULL;
	
		archivo.open("Arch4.txt");
	while(getline(archivo, str)){	
		aux=Cola[3];
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		} 
		aux->siguiente=new nodo(str);
	}
	archivo.close();
	str="";
	aux=NULL;
	
		archivo.open("Arch5.txt");
	while(getline(archivo, str)){	
		aux=Cola[4];
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodo(str);
	}
	archivo.close();
	str="";
	aux=NULL;
}

//Asignar prioridades a cada operando/operador

int lista::prioridadDP(char ca){
	switch(ca){
    	case '+' : 
			return 1;
    	case '-':
    		return 1;
    	case '*':
    		return 2;
    	case '/':
    		return 2;
    	case '^':
    		return 3;
    	case '(':
    		return 0;
    	default: return -1;
	}
}

int lista::prioridadFP(char ca){
	switch(ca){
    	case '+' : 
			return 1;
    	case '-':
    		return 1;
    	case '*':
    		return 2;
    	case '/':
    		return 2;
    	case '^':
    		return 4;
		case '(':
    		return 5;		
    	default: return -1;
	}
}

// Crea lista postfijo, utiliza una lista temporal para guardar los operadores

void lista::crearPostfijo(pnodo primerl){  //(15-4)+3-(12-5*2)
	lista *pilaOperadores = new lista();
	pnodo aux = primerl;
	string car;
	string car2;

		while(aux!=NULL){
			switch(aux->valor[0]){
				case '(':
					car = aux->valor;
					pilaOperadores->InsertarInicio(car);
					break;
				case ')':
					car= pilaOperadores->primero->valor;
					while(car[0] != '('){
						InsertarFinal(car);
						pilaOperadores->BorrarInicio();
						car= pilaOperadores->primero->valor;
					}
					break;
				case '^':
				case '+':					
				case '-':
				case '/':
				case '*':
					if(pilaOperadores->primero!=NULL){
						car = pilaOperadores->primero->valor;
						car2 = aux->valor;
						if(prioridadFP(car2[0]) <= prioridadDP(car[0]) ){
							InsertarFinal(car);
							pilaOperadores->BorrarInicio();
							pilaOperadores->InsertarInicio(car2);
						}
						else{
							pilaOperadores->InsertarInicio(car2);
	
						}
					}else{
					pilaOperadores->InsertarInicio(car2);
					}
					
					break;

				default:
					car=aux->valor;
					InsertarFinal(car);
					break;
			}
		aux= aux->siguiente;
	}
	
//  VACIAR LA PILA OPERADORES
	while(pilaOperadores->primero !=NULL){
		if(pilaOperadores->primero->valor != "("){	
		InsertarFinal(pilaOperadores->primero->valor);
		pilaOperadores->BorrarInicio();
	}else{
		pilaOperadores->BorrarInicio();
	}
	}
	BorrarInicio();
	delete pilaOperadores;
}



int main(){
		cout<<"*************TAREA CORTA #1************************"<<endl<<endl;
		cout<<"Evaluacion en POSTFIJO"<<endl;
		cout<<"\nIntegrantes:\nGustavo Vargas\nGabriel Campos"<<endl;
	lista postFijo;
	pnodo primeroL1=new nodo();
	pnodo primeroL2=new nodo();
	pnodo primeroL3=new nodo();
	pnodo primeroL4=new nodo();
	pnodo primeroL5=new nodo();
	
	pnodo Cola[5]={primeroL1,primeroL2,primeroL3,primeroL4,primeroL5};
	postFijo.crearCola(Cola);
	int i = 0;
	while(i<5){
		cout<<endl<<"************************************************************"<<endl;
		cout<<"\n                    ***LECTURA DE ARCHIVO "<<i+1<<".***\n\nExpresion original: "<<endl<<endl;
		postFijo.MostrarExpresionHuman(Cola[i]); 
		cout<<"\nExpresion como lista: "<<endl<<endl;
		postFijo.MostrarExpresion(Cola[i]);   
		cout<<endl;
		cout<<"Expresion creada en Postfijo: "<<endl<<endl;
		postFijo.crearPostfijo(Cola[i]);
		postFijo.Imprimir();
		cout<<endl;
		cout<<"RESULTADO: "<<endl<<endl;
		//IMPRIMIR RESULTADO
		cout<<"Aqui va el resultado de la operacion";
		cout<<endl;
		i=i+1; 
		postFijo.~lista();
	} 

    cout<<endl;
	return 0;
}
 

/*
Leer Archivos---LISTO
Crear Cola (Arreglo)--- LISTO
Insertar Archivos en la Cola --- LISTO
Recorrer Arreglo de la Cola  --- LISTO
Crear Postfijo               --- LISTO
Evaluar Expresión en Postfijo
Imprimir Expresión Original, Expresión Postfijo y Evaluación
*/





