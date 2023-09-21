#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

class nodoStr { // Constructores
   public:
   	nodoStr()
   	{
   		valor = "";
   		
   		siguiente = NULL;
	   }
   	nodoStr(string v)
    { 
       valor = v;
       siguiente = NULL;  
    	} 

	nodoStr(string v, nodoStr  *signodo)
    {
       valor = v;
       siguiente = signodo;
    	}


   private:
    string valor;
    nodoStr *siguiente;
    
        
   friend class listaStr;
};

typedef nodoStr *pnodoStr; //Alias

//void no retorna nada
//bool retorna False o True
//int retorna entero

class listaStr {
   public:
    listaStr() { primero =  NULL; }//constructor
    ~listaStr();//destructor
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
    void crearCola(pnodoStr Cola[]);
    void MostrarExpresion(pnodoStr primerl);
    void MostrarExpresionHuman(pnodoStr primerl);
    void crearPostfijo(pnodoStr primerl);
    int prioridadDP(char ca);
    int prioridadFP(char ca);
    double retornarNumeroLista();
    void lectorListaPostfija();
    void Imprimir();
    
   private:
    pnodoStr primero;
   
};

listaStr::~listaStr()
{
   pnodoStr aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero= NULL;
}

int listaStr::largoLista(){
    int cont=0;

    pnodoStr aux= primero;
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

void listaStr::InsertarInicio(string v)//3 10 265
{
   if (ListaVacia())
   {
   
     primero = new nodoStr(v);//6
     
   }
   else
   {
    pnodoStr nuevo=new nodoStr(v);
    nuevo->siguiente=primero;
    primero=nuevo;
     
    
    
     
   }
}
 
void listaStr::InsertarFinal(string v)//76
{
   if (ListaVacia())
     primero = new nodoStr(v);
   else
      { 
       pnodoStr aux = primero;
        while ( aux->siguiente != NULL)
         aux= aux->siguiente;
        pnodoStr nuevo=new nodoStr(v);
        aux->siguiente=nuevo;
      }    
}


void listaStr::InsertarPos(string v,int pos)
{
   if (ListaVacia())
     primero = new nodoStr(v);
   else{
        if(pos <=1)
		{
          pnodoStr nuevo = new nodoStr(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else{
             nodoStr *aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodoStr nuevo= new nodoStr(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void listaStr::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        
        if (primero->siguiente == NULL) 
		{   pnodoStr temp=primero;
		    primero= NULL;
		    delete temp;;
            }
			 else {

                pnodoStr aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodoStr temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void listaStr::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) 
		{   pnodoStr temp=primero;
		    primero= NULL;
		    delete temp;
        } 
		else 
		{

                pnodoStr aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
        }
}



void listaStr:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1)
		{
        	pnodoStr temp=primero;
        	primero=primero->siguiente;
        	delete temp; //BorrarInicio();
        }
		else{
          int cont=2;
            pnodoStr aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            pnodoStr temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            delete temp;
            }
        }
     }

}
 

void listaStr::Mostrar()
{
   nodoStr *aux;
   if (primero== NULL)
       cout << "No hay elementos"<<endl;  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << " ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }	
}

void listaStr::Imprimir()
{
   nodoStr *aux;
   if (primero== NULL)
       cout << "No hay elementos"<<endl;  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
			cout << aux->valor<<" -> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }	
}

void listaStr::MostrarExpresionHuman(pnodoStr primerl){
	pnodoStr aux=primerl->siguiente;
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

void listaStr::MostrarExpresion(pnodoStr primerl){
	pnodoStr aux=primerl->siguiente;
	if(aux==NULL){
		cout<<"No hay elementos";
	}
	else{
		while(aux!=NULL){	
			cout<<aux->valor<<" -> ";
			aux=aux->siguiente;
			}
		}
		cout<<endl;
}




//Tarea 3

// 1. Buscar un numero en una lista.

bool listaStr::buscarNumero(string v){
	if(ListaVacia()){
		cout<<"El string "<<v<<" no se encuentra en la lista"<<endl;
		return false;
	}
	else
	{
		pnodoStr aux=primero;
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

bool listaStr:: buscarPosicion(int pos){
    if(ListaVacia()){
              cout << "Lista vacia" <<endl;
              return false;
    }else{
		if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        return false;
        }
		else{
			pnodoStr aux=primero;
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

void listaStr::crearCola(pnodoStr Cola[]){
	string str;
	ifstream archivo;
	pnodoStr aux;
	archivo.open("Arch1.txt");
	while(getline(archivo, str)){	
		aux=Cola[0];
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodoStr(str);
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
		aux->siguiente=new nodoStr(str);
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
		aux->siguiente=new nodoStr(str);
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
		aux->siguiente=new nodoStr(str);
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
		aux->siguiente=new nodoStr(str);
	}
	archivo.close();
	str="";
	aux=NULL;
}

//Asignar prioridades a cada operando/operador

int listaStr::prioridadDP(char ca){
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

int listaStr::prioridadFP(char ca){
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

void listaStr::crearPostfijo(pnodoStr primerl){  //(15-4)+3-(12-5*2)
	listaStr *pilaOperadores = new listaStr();
	pnodoStr aux = primerl;
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

//Lector de la lista postfija para hacer la operacion
void listaStr::lectorListaPostfija() {
		pnodoStr aux = primero;
		listaStr *pilaCalc = new listaStr();	
		double Num1;
		double Num2;
		double Resultado;
		while (aux != NULL) {
			string simbolo; 
			simbolo = aux->valor;
			switch (aux->valor[0]) {
				case '+': // PFP 1 PDP 1
					Num2 = pilaCalc->retornarNumeroLista();
					Num1 = pilaCalc->retornarNumeroLista();
					Resultado = Num1+Num2;
					pilaCalc->InsertarInicio(to_string(Resultado));
					break;
				case '-': // PFP 1 PDP 1
					Num2 = pilaCalc->retornarNumeroLista();
					Num1 = pilaCalc->retornarNumeroLista();
					Resultado = Num1-Num2;
					pilaCalc->InsertarInicio(to_string(Resultado));
					break;
				case '*': // PFP 2 PDP 2
					Num2 = pilaCalc->retornarNumeroLista();
					Num1 = pilaCalc->retornarNumeroLista();
					Resultado = Num1*Num2;
					pilaCalc->InsertarInicio(to_string(Resultado));
					break;
				case '/': // PFP 2 PDP 2
					Num2 = pilaCalc->retornarNumeroLista();
					Num1 = pilaCalc->retornarNumeroLista();
					if(Num2 !=0){
					Resultado = Num1/Num2;
					pilaCalc->InsertarInicio(to_string(Resultado));
					break;
					}else{
						cout<< "Division entre 0 no esta definida.";
						return;
					}
				case '^': // PFP 4 PDP 3
					Num2 = pilaCalc->retornarNumeroLista();
					Num1 = pilaCalc->retornarNumeroLista();
					Resultado = pow(Num1, Num2);
					pilaCalc->InsertarInicio(to_string(Resultado));
					break;
				default: //Numero
					pilaCalc->InsertarInicio(simbolo);
					break;
			}
			aux = aux->siguiente;	
		}
		cout<<pilaCalc->retornarNumeroLista();
	}

//Transforma numeros y los saca de la pila
		double listaStr::retornarNumeroLista() {
		pnodoStr aux = primero;
		double Num1;
		Num1= stod(aux->valor);
		BorrarInicio();
		return Num1;
	}

int main(){
		cout<<"*************TAREA CORTA #1************************"<<endl<<endl;
		cout<<"Evaluacion en POSTFIJO"<<endl;
		cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
	listaStr postFijo;
	pnodoStr primeroL1=new nodoStr();
	pnodoStr primeroL2=new nodoStr();
	pnodoStr primeroL3=new nodoStr();
	pnodoStr primeroL4=new nodoStr();
	pnodoStr primeroL5=new nodoStr();
	
	pnodoStr Cola[5]={primeroL1,primeroL2,primeroL3,primeroL4,primeroL5};
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
		cout<<"Expresion postfijo 'Human readable': "<<endl<<endl;
		postFijo.Mostrar();
		cout<<endl;
		cout<<"Resultado Final: "<<endl<<endl;
		cout<<">>> ";
		postFijo.lectorListaPostfija();
		cout<<" <<< ";
		cout<<endl;
		i=i+1;
		postFijo.~listaStr();	
	}
	
    cout<<endl<<endl<<endl;
    cout<<"###########################################################"<<endl;
    cout<<"###########################################################"<<endl;
    cout<<"###########################################################"<<endl;
	cout<<"################## PROGRAMA FINALIZADO ####################"<<endl;
	cout<<"###########################################################"<<endl;
	cout<<"###########################################################"<<endl;
	cout<<"###########################################################"<<endl;
	return 0;
}
 

/*
Leer Archivos---LISTO
Crear Cola (Arreglo)--- LISTO
Insertar Archivos en la Cola --- LISTO
Recorrer Arreglo de la Cola  --- LISTO
Crear Postfijo               --- LISTO
Evaluar Expresión en Postfijo --- LISTO
Imprimir Expresión Original, Expresión Postfijo y Evaluación  --- lISTO
*/





