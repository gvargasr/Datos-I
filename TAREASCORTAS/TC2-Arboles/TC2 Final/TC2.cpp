#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include "TC#1PostFijo--GustavoVargas-GabrielCampos.cpp"
#include "Pila.cpp"
using namespace std;



class TC2 { 
   public:
    TC2() {
	 inicio = new listaStr();
	 pnodoStr colita[5] = {NULL,NULL,NULL,NULL,NULL};
	 AB = new ArbolBinario();
	 }
    ~TC2();
    void crearLista();
    void crearColaArbol();
    void crearArbol(pnodoStr primerl);
    int prioridadDP(char ca);
    int prioridadFP(char ca);

    void Menu();
	
//	private:
		listaStr *inicio;
		pnodoStr colita[5];
		ArbolBinario *AB;
		Pila *pilaOperadores = new Pila();
		Pila *pilaExpresion = new Pila();
};



TC2::~TC2(){
	inicio->~listaStr();
}


//Asignar prioridades a cada operando/operador

int TC2::prioridadDP(char ca){
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

int TC2::prioridadFP(char ca){
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


// crea la cola estatica de 5 y carga los archivos en lista Simple
void TC2::crearColaArbol(){
	
	pnodoStr primeroL1=new nodoStr();
	pnodoStr primeroL2=new nodoStr();
	pnodoStr primeroL3=new nodoStr();
	pnodoStr primeroL4=new nodoStr();
	pnodoStr primeroL5=new nodoStr();

	colita[0]= primeroL1;
	colita[1]= primeroL2;
	colita[2]= primeroL3;
	colita[3]= primeroL4;
	colita[4]= primeroL5;
	
	string str;
	ifstream archivo;
	pnodoStr aux;
	archivo.open("Arch1.txt");
	primeroL1->siguiente= new nodoStr("(");
	aux=primeroL1;
	while(getline(archivo, str)){
		if(str != ""){

		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodoStr(str);
		}	
	}
	aux->siguiente->siguiente = new nodoStr(")");
	archivo.close();
	
	str="";
	aux=NULL;

	
	archivo.open("Arch2.txt");
	primeroL2->siguiente = new nodoStr("(");
	aux=primeroL2;
	while(getline(archivo, str)){
		if(str != ""){	

		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodoStr(str);
		}
	}
	aux->siguiente->siguiente = new nodoStr(")");
	archivo.close();
	str="";
	aux=NULL;
	
	archivo.open("Arch3.txt");
	primeroL3->siguiente = new nodoStr("(");
	aux=primeroL3;
	while(getline(archivo, str)){
		if(str != ""){	
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodoStr(str);
		}
	}
	aux->siguiente->siguiente = new nodoStr(")");
	archivo.close();
	str="";
	aux=NULL;
	
	archivo.open("Arch4.txt");
	primeroL4->siguiente = new nodoStr("(");
	aux=primeroL4;
	while(getline(archivo, str)){
		if(str != ""){	
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		} 
		aux->siguiente=new nodoStr(str);
		}
	}
	aux->siguiente->siguiente = new nodoStr(")");
	archivo.close();
	str="";
	aux=NULL;
	
	archivo.open("Arch5.txt");
	primeroL5->siguiente = new nodoStr("(");
	aux=primeroL5;
	while(getline(archivo, str)){
		if(str != ""){	
		while(aux->siguiente!=NULL){
			aux=aux->siguiente;
		}
		aux->siguiente=new nodoStr(str);
		}
	}
	aux->siguiente->siguiente = new nodoStr(")");
	archivo.close();
	str="";
	aux=NULL;
	
		
}

 void TC2::crearLista(){
//	listaStr aux = *inicio;
	crearColaArbol();
	for(int i =0; i<5; i++){
		cout<< "#################################################"<<endl;
		cout<< "\t .:ARCHIVO #"<<i+1<<":."<<endl;
		ofstream archivoSalida("Comparaciones.txt", ios::app);
        	if (!archivoSalida.is_open()) {
            	cerr << "No se pudo abrir el archivo." << endl;
        	}
        	else {			
            	archivoSalida << "#################################################"<<endl;
            	archivoSalida << "\t .:ARCHIVO #"<<i+1<<":."<<endl;
            	archivoSalida<<endl<<endl;
            	cout << endl;
     		}										


		pnodoStr aux = colita[i]->siguiente->siguiente;
		while(aux->siguiente){
		cout<< aux->valor<<" ";
		aux = aux->siguiente;
		}
		cout<<endl;
		crearArbol(colita[i]);
		cout<<endl;
	}

}

void TC2::crearArbol(pnodoStr primerl){  //(15-4)+3-(12-5*2)
	pnodoStr aux = primerl->siguiente;
	pnodoA auxA = NULL;
	pnodoA auxI = NULL;
	pnodoA auxD = NULL;
	string car;
	string car2;

		while(aux!=NULL){
			switch(aux->valor[0]){
				case '(':
					if(!pilaOperadores->EstaVacia()){
						car = aux->valor;
						pilaOperadores->Push(new NodoArbol(car));
						cout<<endl;
						cout<<"PrioridadFP "<<car<<": "<<prioridadFP(car[0])<<endl;
						cout<<"Insertando en PilaOperadores"<<endl;
						ofstream archivoSalida("Comparaciones.txt", ios::app);
        				if (!archivoSalida.is_open()) {
            				cerr << "No se pudo abrir el archivo." << endl;
        				}
        				else {
            				
            				archivoSalida <<"PrioridadFP "<<car<<": "<<prioridadFP(car[0])<<endl;
            				archivoSalida <<"Insertando en PilaOperadores"<<endl;
            				archivoSalida<<endl<<endl;
            				cout << endl;
            	//			archivoSalida.close();
        				}						
						
						
						break;
					}else{
						car = aux->valor;
						pilaOperadores->Push(new NodoArbol(car));
						cout<<endl;
						break;
					}
				case ')':
					car2= pilaOperadores->Top()->valor;
					while(car2[0] != '('){
						auxA = pilaOperadores->Top();
						pilaOperadores->Pop();
						auxD = pilaExpresion->Top();
						pilaExpresion->Pop();
						auxI = pilaExpresion->Top();
						pilaExpresion->Pop();
						AB->InsertarHijos(auxA->valor, auxI, auxD);
						pilaExpresion->Push(AB->raiz); 
						car2 = pilaOperadores->Top()->valor;
					}
					pilaOperadores->Pop();
					break;
				case '^':
				case '+':					
				case '-':
				case '/':
				case '*':
					if(pilaOperadores->Top()!=NULL){
						car = pilaOperadores->Top()->valor;
						car2 = aux->valor;
						ofstream archivoSalida("Comparaciones.txt", ios::app);
        				if (!archivoSalida.is_open()) {
            				cerr << "No se pudo abrir el archivo." << endl;
        				}
        				else {
            				
            				archivoSalida << "PrioridadFP "<<car2<<": "<<prioridadFP(car2[0])<<endl;
            				archivoSalida << "PrioridadDP "<<car<<": "<<prioridadDP(car[0])<<endl;
            				archivoSalida<<endl<<endl;
            				cout << endl;
            	//			archivoSalida.close();
        				}
						cout<<endl;
						cout<<"PrioridadFP "<<car2<<": "<<prioridadFP(car2[0])<<endl;
						cout<<"PrioridadDP "<<car<<": "<<prioridadDP(car[0])<<endl;
						if(prioridadFP(car2[0]) <= prioridadDP(car[0]) ){
							auxA = pilaOperadores->Top();
							pilaOperadores->Pop();
							pilaOperadores->Push(new NodoArbol(car2));
							auxD = pilaExpresion->Top();
							pilaExpresion->Pop();
							auxI = pilaExpresion->Top();
							pilaExpresion->Pop();
							AB->InsertarHijos(auxA->valor, auxI, auxD);
							pilaExpresion->Push(AB->raiz); 
							cout<< "Moviendo a Pila Expresion"<<endl;
							archivoSalida << "Moviendo a Pila Expresion"<<endl;
							archivoSalida.close();
							break;
						}
						else{
							pilaOperadores->Push(new NodoArbol(car2));
							cout<< "Insertando en PilaOperadores"<<endl;
							archivoSalida << "Insertando en PilaOperadores"<<endl;
							archivoSalida.close();
							break;
	
						}
					}else{
						auxA = new NodoArbol(aux->valor);
						pilaOperadores->Push(auxA);
						break;
					}
					
					break;

				default:
					pilaExpresion->Push(new NodoArbol(aux->valor));
					break;
			}
		aux= aux->siguiente;
	}
	ofstream archivoSalida("Comparaciones.txt", ios::app);
        				if (!archivoSalida.is_open()) {
            				cerr << "No se pudo abrir el archivo." << endl;
        				}
        				else {
            				
            				archivoSalida << "#####################################################"<<endl;
            				archivoSalida<<endl<<endl;
            				cout << endl;
            				archivoSalida.close();
        				}
	AB->raiz = pilaExpresion->Top();
	cout<<endl<<endl;
	cout<<"Recorrido In-Orden: "<<endl;
	AB->RecorridoInorden(AB->raiz);
	cout<<endl<<endl;
	cout<<"Recorrido Post-Orden: "<<endl;
	AB->RecorridoPostorden(AB->raiz);
	cout<<endl<<endl;
	cout<<"Recorrido Pre-Orden: "<<endl;
	AB->RecorridoPreorden(AB->raiz);
	cout<<endl<<endl;
	
//	AB->Evaluacion(AB->raiz);
	
/*
//  VACIAR LA PILA OPERADORES
	while(pilaOperadores->Top() !=NULL){
		if(pilaOperadores->Top()->valor != "("){	
		pilaExpresion->Push(pilaOperadores->Top());
		pilaOperadores->Pop();
	}else{
		pilaOperadores->Pop();
	}
	}
	AB = new ArbolBinario(pilaExpresion->Top());
	pilaOperadores->Pop();
	delete pilaOperadores;*/
}


void TC2::Menu(){
	while(true){
	    cout << endl << "----------------------------" << endl;
        cout << endl << "      Menu Principal  " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Leer Archivos"<<endl;
		cout << "2. Insertar"<<endl;
		cout << "3. Eliminar"<<endl;
		cout << "4. Buscar"<<endl;
		cout << "5. Modificar"<<endl;
		cout << "6. Reportes"<<endl;
		cout << "7. Info"<<endl;
		cout << "8. Comprar"<<endl;
		cout << "9. Salir"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";
		
		char opt;
		cin >> opt;
    
    switch(opt) {
    	case '1' : 
		//	SubMenu1();
			Menu();
			break;
    	case '2':
    	//	SubMenu2();
    		Menu();
    		break;
    	case '3':
    	//	SubMenu3();
    		Menu();
			break;
    	case '4':
    	//	SubMenu4();
    		Menu();
    		break;
    	case '5':
    	//	SubMenu5();
    		Menu();
			break;
		case '6':
    		cout<<"Ingresando a Submenu 6...";
    		Menu();
			break;
		case '7':
    		cout<<"Ingresando a Submenu 7..."<<endl;
    		Menu();
			break;
		case '8':	
		//	SubMenu8();
			Menu();
			break;
		case '9':
    		cout<<endl<<endl<<endl<<"##################      Good Bye!!     ####################"<<endl;
    		exit(1);
			break;		
    default: 
    cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
	Menu();
	}
	break;
	}
}



int main(){
		cout<<"*************TAREA CORTA #2************************"<<endl<<endl;
		cout<<"Evaluacion en PREFIJO, INFIJO Y POSTFIJO CON ARBOLES"<<endl;
		cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
	TC2 tc2;
	tc2.crearLista();
	cout<<endl;


	
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
 
 
 

