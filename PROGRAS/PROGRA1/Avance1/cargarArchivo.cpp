#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include "listaDPais.cpp"
#include "listaClientes.cpp"

using namespace std;

class cargarArchivo { 
   public:
    cargarArchivo() {
	 listaPais = new listaDPais();
	 listaCliente = new listaClientes(); 
	 }
    ~cargarArchivo();
    void Menu();
    void cargaInicial();
    void EliminarPais(int codigo);
    void MostrarTodo();

    void SubMenu1();
	void SubMenu2();
	void SubMenu21();
	void SubMenu22();
	void SubMenu23();
	void SubMenu24();
	void SubMenu25();
	void SubMenu26();
	void SubMenu3();
	void SubMenu31();
	void SubMenu32();
	void SubMenu33();
	void SubMenu34();
	void SubMenu35();
	void SubMenu36();
	void SubMenu4();
	void SubMenu41();
	void SubMenu42();
	void SubMenu43();
	void SubMenu44();
	void SubMenu45();
	void SubMenu46();
	void SubMenu5();
	void SubMenu51();
	void SubMenu52();
	void SubMenu53();
	void SubMenu54();
	void SubMenu55();
	void SubMenu56();

    

	
//	private:
    listaDPais *listaPais;
    listaClientes *listaCliente;
    
    friend MainMenu();
  
};

cargarArchivo::~cargarArchivo()
{
listaPais = NULL;
}


void cargarArchivo::cargaInicial(){
	pnodoPais aux = listaPais->primero;
	ifstream archivo;

	archivo.open("Archivos/Paises.txt");
	while(!archivo.eof()){
		string codigo;
		string pais;
		getline(archivo,codigo, ';');
		getline(archivo, pais);
			
		listaPais->InsertarFinal(stoi(codigo),pais);
	}
	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;


	archivo.open("Archivos/Ciudades.txt");
	while(!archivo.eof()){
		string codpais;
		string codigo;
		string ciudad ;
		getline(archivo, codpais, ';');
		getline(archivo, codigo, ';');
		getline(archivo, ciudad);
		pnodoPais aux = listaPais->primero;
		int temp = stoi(codpais);
		int temp2 = stoi(codigo);
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					listaPais->InsertarCiudad(temp2,ciudad,aux->listaCiudad);
				}
			aux=aux->siguiente;
			}
		}
	}
	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;			


 	archivo.open("Archivos/Restaurantes.txt");
	while(!archivo.eof()){
		string codpais;
		string codCiudad;
		string numRest;
		string nombre;
		getline(archivo, codpais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, numRest, ';');
		getline(archivo, nombre);
		pnodoPais aux = listaPais->GetPrimero();
		int temp = stoi(codpais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(numRest);
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->getCodigo() == temp){
					pnodoCiudad aux2 = aux->listaCiudad->GetPrimero();
					while(aux2!=NULL){
						if(aux2->cod == temp2){
							aux->listaCiudad->InsertarRestaurante(temp3,nombre, aux2->listaRestaurante);
						}
						aux2= aux2->siguiente;
					}
				}
			aux=aux->siguiente;
			}
			
		}
	}
	archivo.close();	
	cout<<endl<<"*********************************************************************************"<<endl<<endl;


 	archivo.open("Archivos/Menu.txt");
 		while(!archivo.eof()){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string nombre;
		
		getline(archivo, codPais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, codRest, ';');
		getline(archivo, codMenu, ';');
		getline(archivo, nombre);
		pnodoPais aux = listaPais->primero;
		int temp = stoi(codPais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(codRest);
		int temp4 = stoi(codMenu);
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					pnodoCiudad aux2 = aux->listaCiudad->primero;
					while(aux2!=NULL){
						if(aux2->cod == temp2){
							pnodoRest aux3 = aux2->listaRestaurante->primero;
							pnodoRest head = aux2->listaRestaurante->primero;
								while(aux3->siguiente!=head && aux3->cod!=temp3)
									aux3=aux3->siguiente;
								if(aux3->siguiente==head);
								aux2->listaRestaurante->InsertarMenu(temp4,nombre,aux3->listaMenu);
						}
						aux2= aux2->siguiente;
					}
				}
			aux=aux->siguiente;
			}		
		}
	}
 	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;

 	archivo.open("Archivos/Productos.txt");
 		while(!archivo.eof()){
		string codPais;
		string codCiudad;
		string codRest;
		string codMenu;
		string codProd;
		string nombre;
		string kcal;
		string precio;
		 
		getline(archivo, codPais, ';');
		getline(archivo, codCiudad, ';');
		getline(archivo, codRest, ';');
		getline(archivo, codMenu, ';');
		getline(archivo, codProd, ';');
		getline(archivo, nombre, ';');
		getline(archivo, kcal, ';');
		getline(archivo, precio);
		
		pnodoPais aux = listaPais->primero;
		int temp = stoi(codPais);
		int temp2 = stoi(codCiudad);
		int temp3 = stoi(codRest);
		int temp4 = stoi(codMenu);
		int temp5 = stoi(codProd);
		int temp6 = stoi(kcal);
		int temp7 = stoi(precio);
		
		if(listaPais->buscarPais(temp)==true){
			while(aux!=NULL){
				if(aux->cod == temp){
					pnodoCiudad aux2 = aux->listaCiudad->primero;
					while(aux2!=NULL){
						if(aux2->cod == temp2){
							pnodoRest aux3 = aux2->listaRestaurante->primero;
							pnodoRest head = aux2->listaRestaurante->primero;
								while(aux3->siguiente!=head && aux3->cod!=temp3)
									aux3=aux3->siguiente;
								if(aux3->cod==temp3){
									pnodoMenu aux4 = aux3->listaMenu->primero;
									while(aux4!=NULL){
										if(aux4->cod == temp4){
										aux3->listaMenu->InsertarProducto(temp5, nombre, temp6, temp7, aux4->listaProd);
										}
									aux4= aux4->siguiente;
									}
							}
						}
					aux2= aux2->siguiente;
					}
				}
			aux=aux->siguiente;
			}		
		}
	}
 	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;
	
	archivo.open("Archivos/Clientes.txt");
	while(!archivo.eof()){
		string cedula;
		string nombre;
		getline(archivo, cedula, ';');
		getline(archivo, nombre);
		int temp = stoi(cedula);
		listaCliente->InsertarFinal(temp,nombre);
	}
	archivo.close();
	cout<<endl<<"*********************************************************************************"<<endl<<endl;	
}


void cargarArchivo::EliminarPais(int codigo){
	listaPais->BorrarPosicion(listaPais->buscarPos(codigo));
}
/*
// Mostrar Todo:
	
void cargarArchivo::MostrarTodo(){
	pnodoPais aux = listaPais->primero;
	while(aux!=NULL){
		cout<<"Pais "<<endl;
		cout<<aux->getCodigo()<<":"<<aux->pais<<endl;
		pnodoCiudad aux2 = aux->listaCiudad->primero;	
			while(aux2!=NULL){
				cout<<"Ciudad"<<endl;
				cout<<aux2->cod<<":"<<aux2->ciudad<<endl;
				pnodoRest aux3 = aux2->listaRestaurante->primero;
				pnodoRest temp = aux2->listaRestaurante->primero;
				while(aux3!=temp){
					
				}
				aux2 = aux2->siguiente;
			}
		aux = aux->siguiente;	
		}
	
	}
*/


/*
int main(){

	cargarArchivo Inicio;
	Inicio.cargaInicial();
	Inicio.listaPais->Mostrar();
	cout<<Inicio.listaPais->largoLista();
	cout<<Inicio.listaPais->buscarPos(12);
	Inicio.listaPais->BorrarPosicion(Inicio.listaPais->buscarPos(12));
	Inicio.listaPais->Mostrar();
	Inicio.listaPais->BorrarPosicion(Inicio.listaPais->buscarPos(1));
	Inicio.listaPais->Mostrar();
	cout<<"Lista Ciudades de panama"<<endl;
	Inicio.listaPais->GetPrimero()->listaCiudad->Mostrar();
	Inicio.listaPais->GetPrimero()->listaCiudad->BorrarPosicion(Inicio.listaPais->GetPrimero()->listaCiudad->buscarPos(69));
	Inicio.listaPais->GetPrimero()->listaCiudad->Mostrar();*/
	
	
	
/*	cout<<"Lista Ciudades de Estados Unidos"<<endl;
	Inicio.listaPais->GetPrimero()->siguiente->listaCiudad->Mostrar();
	cout<<"Lista Ciudades de Mexico"<<endl;
	Inicio.listaPais->GetPrimero()->siguiente->siguiente->listaCiudad->Mostrar();
	cout<<"Lista Restaurantes Panama "<<endl;
	Inicio.listaPais->GetPrimero()->listaCiudad->GetPrimero()->listaRestaurante->Mostrar();
	cout<<"Lista Restaurantes EEUU "<<endl;
	Inicio.listaPais->GetPrimero()->siguiente->listaCiudad->GetPrimero()->siguiente->listaRestaurante->Mostrar();
	cout<<endl;
	cout<<"Lista Menu Panama "<<endl;
	Inicio.listaPais->GetPrimero()->listaCiudad->GetPrimero()->listaRestaurante->GetPrimero()->listaMenu->Mostrar();
	cout<<endl;
	cout<<"Lista McPanama, menu HC"<<endl;
	Inicio.listaPais->GetPrimero()->listaCiudad->GetPrimero()->listaRestaurante->GetPrimero()->listaMenu->GetPrimero()->listaProd->Mostrar();
	cout<<endl<<endl;
	cout<<"Lista de Clientes"<<endl;
	Inicio.listaCliente->Mostrar();
}
*/


void cargarArchivo::SubMenu1(){
		cout << endl << "----------------------------" << endl;
        cout << endl << "      1. Leer Archivos   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Cargar Archivos"<<endl;
		cout << "2. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";		
		char opt;
		cin >> opt;
		
	switch(opt) {
		case '1':{
			cout<<"Cargando archivos... "<<endl<<endl;
			cargaInicial();
			cout<<"."<<endl;
			cout<<"."<<endl;
			cout<<"."<<endl;
			cout<<"Se cargo archivos y lista de clientes"<<endl;
//			listaPais->Mostrar();
//			listaCliente->Mostrar();
			break;
		}
		case '2':{
			cout<<"Volviendo a Main Menu"<<endl;
			break;	
		}
	default:
		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
		SubMenu1();
	}
}


// Insertar 
void cargarArchivo::SubMenu2(){
		cout << endl << "----------------------------" << endl;
        cout << endl << "      2. Insertar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";		
		char opt;
		cin >> opt;
		
	switch(opt) {
		case '1':
			cout<<"2.1 Insertar Pais"<<endl;
			SubMenu21();
			break;
		case '2':
			cout<<"2.2 Insertar Ciudad"<<endl;
			SubMenu22();
			break;
		case '3':
			cout<<"2.3 Insertar Restaurante"<<endl;
			SubMenu23();
			break;
			break;	
		case '4':
			cout<<"2.4 Insertar Menu"<<endl;
			SubMenu24();
			break;
		case '5':
			cout<<"2.5 Insertar Producto"<<endl;
			SubMenu25();
			break;	
		case '6':
			cout<<"2.6 Insertar Cliente"<<endl;
			SubMenu26();
			break;
		case '7':
			cout<<"Volviendo a Main Menu"<<endl;
			break;	
	default:
		cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
		SubMenu2();
	}
}

void cargarArchivo::SubMenu21(){
	string cod;
	string nombre;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	cout<< "\nIngrese el Nombre de pais: ";
	cin >> nombre;
	listaPais->InsertarFinal(stoi(cod), nombre);
	
}

void cargarArchivo::SubMenu22(){
	string codPais;
	string codCiudad;
	string ciudad;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cout<< "\nIngrese el Nombre de la ciudad: ";
	cin >> ciudad;
	pnodoPais aux = listaPais->primero;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				listaPais->InsertarCiudad(temp2,ciudad,aux->listaCiudad);
			}
		aux=aux->siguiente;
		}
	}			
}


void cargarArchivo::SubMenu23(){
	string codPais;
	string codCiudad;
	string codRest;
	string rest;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cout<< "\nIngrese el codigo de restaurante: ";
	cin >> codRest;
	cout<< "\nIngrese el Nombre de restaurante: ";
	cin >> rest;
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(stoi(codPais))==true){
		while(aux!=NULL){
			if(aux->cod == stoi(codPais)){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == stoi(codCiudad)){
						aux2->listaRestaurante->InsertarFinal(stoi(codRest), rest);
						return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"CIUDAD NO EXISTE"<<endl;	
			return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"PAIS NO EXISTE"<<endl;	
}

void cargarArchivo::SubMenu24(){
	string codPais;
	string codCiudad;
	string codRest;
	string codMenu;
	string menu;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cout<< "\nIngrese el codigo de restaurante: ";
	cin >> codRest;
	cout<< "\nIngrese el codigo de menu: ";
	cin >> codMenu;
	cout<< "\nIngrese el Nombre de menu: ";
	cin >> menu;
	pnodoPais aux = listaPais->primero;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->siguiente==head);
							aux3->listaMenu->InsertarFinal(temp4,menu);
					}
					aux2= aux2->siguiente;
				}
			}
		aux=aux->siguiente;
		}		
	}
}				


void cargarArchivo::SubMenu25(){
	string codPais;
	string codCiudad;
	string codRest;
	string codMenu;
	string codProd;
	string producto;
	string kcal;
	string precio;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	cout<< "\nIngrese el codigo de ciudad: ";
	cin >> codCiudad;
	cout<< "\nIngrese el codigo de restaurante: ";
	cin >> codRest;
	cout<< "\nIngrese el codigo de menu: ";
	cin >> codMenu;
	cout<< "\nIngrese el codigo de producto: ";
	cin >> codProd;
	cout<< "\nIngrese el nombre de producto: ";
	cin >> producto;
	cout<< "\nIngrese cantidad de Kcal: ";
	cin >> kcal;
	cout<< "\nIngrese el precio de producto: ";
	cin >> precio;
	
	pnodoPais aux = listaPais->GetPrimero();
	if(listaPais->buscarPais(stoi(codPais))==true){
		while(aux!=NULL){
			if(aux->cod == stoi(codPais)){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == stoi(codCiudad)){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=stoi(codRest))
								aux3=aux3->siguiente;
							if(aux3->cod==stoi(codRest)){
								pnodoMenu aux4 = aux3->listaMenu->primero;
								while(aux4!=NULL){
									if(aux4->cod == stoi(codMenu)){
									aux3->listaMenu->InsertarProducto(stoi(codProd), producto, stoi(kcal), stoi(precio), aux4->listaProd);
									}
								aux4= aux4->siguiente;
								}
							}
					}
				aux2= aux2->siguiente;
				}
			}
		aux=aux->siguiente;
		}		
	}
}


void cargarArchivo::SubMenu26(){
	string cedula;
	string nombre;
	cout<< "Ingrese el numero de cedula: ";
	cin >> cedula;
	cout<< "\nIngrese el nombre del cliente: ";
	cin >> nombre;
	listaCliente->InsertarFinal(stoi(cedula),nombre);
}



// Eliminar

void cargarArchivo::SubMenu3(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      3. Eliminar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "3.1 Eliminar Pais"<<endl;
			SubMenu31();
			break;
		}
		case '2':{
			cout<< "3.2 Eliminar Ciudad"<<endl;
			SubMenu32();			
			break;
		}
		case '3':{
			cout<< "3.3 Eliminar Restaurante"<<endl;
			SubMenu33();
			break;
		}
		case '4':{
			cout<< "3.4 Eliminar Menu"<<endl;
			SubMenu34();
			break;
		}
		case '5':{
			cout<< "3.5 Eliminar Producto"<<endl;
			SubMenu35();
			break;
		}
		case '6':{
			cout<< "3.6 Eliminar Cliente"<<endl;
			SubMenu36();
			break;
		}
		case '7':{
			cout<<"Volviendo a Main Menu"<<endl;			
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			break;
		}
	}
}

void cargarArchivo::SubMenu31(){
	string cod;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	listaPais->BorrarPosicion(listaPais->buscarPos(stoi(cod)));
}

void cargarArchivo::SubMenu32(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				aux->listaCiudad->BorrarPosicion(aux->listaCiudad->buscarPos(temp2));
				return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"PAIS NO EXISTE";
}

void cargarArchivo::SubMenu33(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->getCodigo() == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						aux2->listaRestaurante->BorrarPosicion(aux2->listaRestaurante->buscarPos(temp3));
						return;
					}
					aux2= aux2->siguiente;
				}	
			}else{
				cout<<"CIUDAD NO EXISTE";
				return;
			}
		aux=aux->siguiente;
		}	
	cout<<"PAIS NO EXISTE";
	}
}


void cargarArchivo::SubMenu34(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo menu: ";
	cin >> codMenu;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod == temp3){
							aux3->listaMenu->BorrarPosicion(aux3->listaMenu->buscarPos(temp4));
							return;
							}
							cout<<"RESTAURANTE NO EXISTE/eliminar menu";	
							return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"CIUDAD NO EXISTE/eliminar menu";
			return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"PAIS NO EXISTE/eliminar menu";
}

void cargarArchivo::SubMenu35(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	cout<< "Ingrese el codigo de producto: ";
	cin >> codProd;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod==temp3){
								pnodoMenu aux4 = aux3->listaMenu->primero;
								while(aux4!=NULL){
									if(aux4->cod == temp4){
										aux4->listaProd->BorrarPosicion(aux4->listaProd->buscarPos(temp5));
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"Menu no existe/eliminar prod"<<endl;
								return;
							}else{
								cout<<"Restaurante no existe/eliminar prod"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"Ciudad no existe/eliminar prod"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Ciudad no existe/eliminar prod"<<endl;
	return;
}

void cargarArchivo::SubMenu36(){
	string cedula;
	cout<< "Ingrese el numero de cedula que desea eliminar: ";
	cin >> cedula;
	
	listaCliente->borrarPosicion(listaCliente->buscarPos(stoi(cedula)));
}


//Busqueda

void cargarArchivo::SubMenu4(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      4. Buscar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "4.1 Buscar Pais"<<endl;
			SubMenu41();
			break;
		}
		case '2':{
			cout<< "4.2 Buscar Ciudad"<<endl;
			SubMenu42();			
			break;
		}
		case '3':{
			cout<< "4.3 Buscar Restaurante"<<endl;
			SubMenu43();
			break;
		}
		case '4':{
			cout<< "4.4 Buscar Menu"<<endl;
			SubMenu44();
			break;
		}
		case '5':{
			cout<< "4.5 Buscar Producto"<<endl;
			SubMenu45();
			break;
		}
		case '6':{
			cout<< "4.6 Buscar Cliente"<<endl;
			SubMenu46();
			break;
		}
		case '7':{
			cout<<"Volviendo a Main Menu"<<endl;			
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			break;
		}
	}
}

void cargarArchivo::SubMenu41(){
	string cod;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	listaPais->busqueda(stoi(cod));
}

void cargarArchivo::SubMenu42(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				aux->listaCiudad->busqueda(stoi(codPais),stoi(codCiudad));
				return;
			}
		aux=aux->siguiente;
		}
		cout<<"Ciudad no existe en pais "<<temp<<endl;
	}
	cout<<"Pais no existe en base de datos";
}

void cargarArchivo::SubMenu43(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	pnodoPais aux = listaPais->primero;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->getCodigo() == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						aux2->listaRestaurante->busqueda(temp,temp2,temp3);
						return;
					}
					aux2= aux2->siguiente;
				}	
			}else{
				cout<<"Ciudad no existe en pais "<<temp<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Pais no existe en base de datos";
}


void cargarArchivo::SubMenu44(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo menu: ";
	cin >> codMenu;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod == temp3){
							aux3->listaMenu->busqueda(temp,temp2,temp3,temp4);
							return;
							}
							cout<<"Restaurante no existe en ciudad "<<temp2<<endl;	
							return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"Ciudad no existe en pais "<<temp<<endl;
			return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"Pais no existe en base de datos";
}

void cargarArchivo::SubMenu45(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	cout<< "Ingrese el codigo de producto: ";
	cin >> codProd;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod==temp3){
								pnodoMenu aux4 = aux3->listaMenu->primero;
								while(aux4!=NULL){
									if(aux4->cod == temp4){
										aux4->listaProd->busqueda(temp, temp2, temp3, temp4, temp5);
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"Menu no existe en restaurante "<<temp3<<endl;
								return;
							}else{
								cout<<"Restaurante no existe en ciudad "<<temp2<<endl;	
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"Ciudad no existe en pais "<<temp<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Pais no existe en base de datos";
	return;
}

void cargarArchivo::SubMenu46(){
	string cedula;
	cout<< "Ingrese el numero de cedula que desea buscar: ";
	cin >> cedula;
	
	listaCliente->busqueda(stoi(cedula));
}



// Modificar

void cargarArchivo::SubMenu5(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      5. Modificar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Pais"<<endl;
		cout << "2. Ciudad"<<endl;
		cout << "3. Restaurante"<<endl;
		cout << "4. Menu"<<endl;
		cout << "5. Producto"<<endl;
		cout << "6. Cliente"<<endl;
		cout << "7. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "5.1 Modificar Pais"<<endl;
			SubMenu51();
			break;
		}
		case '2':{
			cout<< "5.2 Modificar Ciudad"<<endl;
			SubMenu52();			
			break;
		}
		case '3':{
			cout<< "5.3 Modificar Restaurante"<<endl;
			SubMenu53();
			break;
		}
		case '4':{
			cout<< "5.4 Modificar Menu"<<endl;
			SubMenu54();
			break;
		}
		case '5':{
			cout<< "5.5 Modificar Producto"<<endl;
			SubMenu55();
			break;
		}
		case '6':{
			cout<< "5.6 Modificar Cliente"<<endl;
			SubMenu56();
			break;
		}
		case '7':{
			cout<<"Volviendo a Main Menu"<<endl;			
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			break;
		}
	}
}

void cargarArchivo::SubMenu51(){
	string cod;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	listaPais->BorrarPosicion(listaPais->buscarPos(stoi(cod)));
}

void cargarArchivo::SubMenu52(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				aux->listaCiudad->BorrarPosicion(aux->listaCiudad->buscarPos(temp2));
				return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"PAIS NO EXISTE";
}

void cargarArchivo::SubMenu53(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->getCodigo() == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						aux2->listaRestaurante->BorrarPosicion(aux2->listaRestaurante->buscarPos(temp3));
						return;
					}
					aux2= aux2->siguiente;
				}	
			}else{
				cout<<"CIUDAD NO EXISTE";
				return;
			}
		aux=aux->siguiente;
		}	
	cout<<"PAIS NO EXISTE";
	}
}


void cargarArchivo::SubMenu54(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo menu: ";
	cin >> codMenu;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod == temp3){
							aux3->listaMenu->BorrarPosicion(aux3->listaMenu->buscarPos(temp4));
							return;
							}
							cout<<"RESTAURANTE NO EXISTE/eliminar menu";	
							return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"CIUDAD NO EXISTE/eliminar menu";
			return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"PAIS NO EXISTE/eliminar menu";
}

void cargarArchivo::SubMenu55(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	string codCiudad;
	cout<< "Ingrese el codigo de ciudad: ";
	cin >> codCiudad;
	string codRest;
	cout<< "Ingrese el codigo de restaurante: ";
	cin >> codRest;
	string codMenu;
	cout<< "Ingrese el codigo de menu: ";
	cin >> codMenu;
	string codProd;
	cout<< "Ingrese el codigo de producto: ";
	cin >> codProd;
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	int temp4 = stoi(codMenu);
	int temp5 = stoi(codProd);
	pnodoPais aux = listaPais->primero;
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod==temp3){
								pnodoMenu aux4 = aux3->listaMenu->primero;
								while(aux4!=NULL){
									if(aux4->cod == temp4){
										aux4->listaProd->BorrarPosicion(aux4->listaProd->buscarPos(temp5));
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"Menu no existe/eliminar prod"<<endl;
								return;
							}else{
								cout<<"Restaurante no existe/eliminar prod"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"Ciudad no existe/eliminar prod"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Ciudad no existe/eliminar prod"<<endl;
	return;
}

void cargarArchivo::SubMenu56(){
	string cedula;
	cout<< "Ingrese el numero de cedula que desea eliminar: ";
	cin >> cedula;
	
	listaCliente->borrarPosicion(listaCliente->buscarPos(stoi(cedula)));
}

void cargarArchivo::Menu(){
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
		cout << "8. Salir"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";
		
		char opt;
		cin >> opt;
    
    switch(opt) {
    	case '1' : 
			SubMenu1();
			Menu();
			break;
    	case '2':
    		SubMenu2();
    		Menu();
    		break;
    	case '3':{
    		SubMenu3();
    		Menu();
			break;
		}
    	case '4':
    		SubMenu4();
    		Menu();
    		break;
    	case '5':
    		SubMenu5();
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
    		cout<<endl<<endl<<endl<<"##################      Good Bye!!     ####################"<<endl;
    		break;
			exit(1);		
    default: 
    cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
	Menu();
	}
	break;
	}
}


int main(){
	cout<<"*************PROGRA #1************************"<<endl;
	cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
	cout<<endl<<"*********************************************************************************"<<endl<<endl;	
	cargarArchivo Inicio;
	Inicio.cargaInicial();
	Inicio.Menu();

 
    cout<<"###########################################################"<<endl;
	cout<<"################## PROGRAMA FINALIZADO ####################"<<endl;
	cout<<"###########################################################"<<endl;

	return 0;
}






/* TODO (#1#): prevenir lineas en blanco al leer archivos */


