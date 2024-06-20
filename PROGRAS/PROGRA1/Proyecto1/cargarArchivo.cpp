#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include "listaDPais.cpp"
#include "listaClientes.cpp"
#include "listaDFila.cpp"
//#include "listaDMenu.cpp"


using namespace std;

class cargarArchivo { 
   public:
    cargarArchivo() {
	 listaPais = new listaDPais();
	 listaCliente = new listaClientes(); 
	 listaFila = new listaDFila();
	 }
    ~cargarArchivo();
    void Menu();
    void cargaInicial();
    void EliminarPais(int codigo);
    void buscarMenuMasBuscado();

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
	void SubMenu57();
	void SubMenu571(pnodoComp Prod);
	void SubMenu6();
	void SubMenu61();
    void SubMenu62();
    void SubMenu63();
    void SubMenu64();
    void SubMenu65();
    void SubMenu66();
    void SubMenu67();
    void SubMenu68();
	void SubMenu8();
	void SubMenu81(int cedula);
	
	
//	private:
    listaDPais *listaPais;
    listaClientes *listaCliente;
    listaDFila *listaFila;

    friend MainMenu();
  
};

cargarArchivo::~cargarArchivo()
{
listaPais = NULL;
}


void cargarArchivo::cargaInicial(){
	pnodoPais aux = listaPais->primero;
	ifstream archivo;

try{

	archivo.open("Archivos/Paises.txt");
	while(!archivo.eof()){
		string codigo;
		string pais;
		getline(archivo,codigo, ';');
		getline(archivo, pais);
		if(!codigo.empty()){
			listaPais->InsertarFinal(stoi(codigo),pais);
		}	

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

} catch(const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return ; // Salir del programa con código de error
    }
}

void cargarArchivo::buscarMenuMasBuscado() {
	int contTop = 0;
    string codPaisTop = "";
    string codCiudadTop = "";
    string codRestTop = "";
    int codMenuTop = 0;
    string MenuTop = "";

	pnodoPais aux = listaPais->primero;
		while(aux!=NULL){
				if(aux->listaCiudad->primero != NULL){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
						if(aux2->listaRestaurante != NULL){
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						cout<< aux3->rest;
						int largoRest = 5;
					/*		while(largoRest > 0){
								pnodoMenu aux4 = aux2->listaRestaurante->primero->buscarMayor();
								if(aux4->counter >= contTop){
									contTop = aux4->counter;
									codPaisTop = aux->pais;
									codCiudadTop = aux2->ciudad;
								//	codRestTop = aux3->rest;
									codMenuTop = aux4->cod;
									MenuTop = aux4->nomMenu;
								//	aux3 = aux3->siguiente;
									cout<<"1";
								}
							//	aux3 = aux3->siguiente;
								largoRest--;
								cout<<"2";						
							}*/
					aux2= aux2->siguiente;
				//	cout << aux2->ciudad;
					cout<<"3";
				}
				}
			}
		aux=aux->siguiente;
		cout<<"4";
		}
    if (contTop == 0) {
        cout << "\n***AUN NO SE HA BUSCADO NINGUN MENU***" << endl << endl;
    }
    
    else {
        cout << "\nSe esta generando el archivo Reporte_Menu_Mas_Buscado.txt\n.\n.\n.\n" << endl;
        ofstream archivoSalida("Reporte_Menu_Mas_Buscado.txt");
        if (!archivoSalida.is_open()) {
            cerr << "No se pudo abrir el archivo." << endl;
        }
        else {
            archivoSalida << "REPORTE MENU MAS BUSCADO " << endl << endl << endl;
            archivoSalida << "Pais: "<<codPaisTop << "\nCiudad: " << codCiudadTop << "\nRestaurante: " << codRestTop << "\nMenu: " << codMenuTop<<":"<<MenuTop << endl;
            archivoSalida << "Menu buscado : " << contTop <<" veces." <<endl;
            cout << endl;
            archivoSalida.close();
            cout << "Reporte generado";
        }
    }
}


void cargarArchivo::EliminarPais(int codigo){
	listaPais->BorrarPosicion(listaPais->buscarPos(codigo));
}



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
	cin.ignore();
	cout<< "\nIngrese el Nombre de pais: ";
	getline(cin,nombre);
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
	cin.ignore();
	cout<< "\nIngrese el Nombre de la ciudad: ";
	getline(cin,ciudad);
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
	cin.ignore();
	cout<< "\nIngrese el Nombre de restaurante: ";
	getline(cin,rest);
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
	cin.ignore();
	cout<< "\nIngrese el Nombre de menu: ";
	getline(cin,menu);
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
	cin.ignore();
	cout<< "\nIngrese el nombre de producto: ";
	getline(cin,producto);
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
							if(aux3->cod==stoi(codRest));
								pnodoMenu aux4 = aux3->listaMenu->primero;
								while(aux4!=NULL){
									if(aux4->cod == stoi(codMenu)){
									aux3->listaMenu->InsertarProducto(stoi(codProd), producto, stoi(kcal), stoi(precio), aux4->listaProd);
									}
								aux4= aux4->siguiente;
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
	cout<< "Ingrese el numero de cedula: \n";
	cin >> cedula;
	cin.ignore();
	cout<< "\nIngrese el nombre del cliente: ";
	getline(cin,nombre);
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
	cout<<"NO SE ELIMINO CIUDAD, CODIGOS INCORRECTOS";
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
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						aux2->listaRestaurante->BorrarPosicion(aux2->listaRestaurante->buscarPos(temp3));
						return;
					}
					aux2= aux2->siguiente;
				}
				cout<<"NO SE ELIMINO RESTAURANTE, CODIGOS INCORRECTOS";
				return;	
			}
		aux=aux->siguiente;
		}	
	cout<<"NO SE ELIMINO RESTAURANTE, CODIGOS INCORRECTOS";
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
							cout<<"NO SE ELIMINO MENU, CODIGOS INCORRECTOS";	
							return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"NO SE ELIMINO MENU, CODIGOS INCORRECTOS";
			return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"NO SE ELIMINO MENU, CODIGOS INCORRECTOS";
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
								cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
								return;
							}else{
								cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"NO SE ELIMINO PRODUCTO, CODIGOS INCORRECTOS"<<endl;
	return;
}

void cargarArchivo::SubMenu36(){
	string cedula;
	cout<< "Ingrese el numero de cedula que desea eliminar: ";
	cin >> cedula;
	
	listaCliente->borrarPosicion(listaCliente->buscarPos(stoi(cedula)));
}

//Buscar

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
	listaPais->MostrarPosicion(listaPais->buscarPos(stoi(cod)));
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
				listaPais->MostrarPosicion(listaPais->buscarPos(temp));
				aux->listaCiudad->MostrarPosicion(aux->listaCiudad->buscarPos(temp2));
				return;
			}
		aux=aux->siguiente;
		}
		cout<<"CIUDAD NO EXISTE";
	}
	cout<<"CIUDAD NO EXISTE";
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
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	int temp2 = stoi(codCiudad);
	int temp3 = stoi(codRest);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						listaPais->MostrarPosicion(listaPais->buscarPos(temp));
						aux->listaCiudad->MostrarPosicion(aux->listaCiudad->buscarPos(temp2));
						aux2->listaRestaurante->MostrarPosicion(aux2->listaRestaurante->buscarPos(temp3));
						return;
					}
					aux2= aux2->siguiente;
				}
				cout<<"RESTAURANTE NO EXISTE";
				return;	
			}
		aux=aux->siguiente;
		}	
	}
	cout<<"RESTAURANTE NO EXISTE";
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
							listaPais->MostrarPosicion(listaPais->buscarPos(temp));
							aux->listaCiudad->MostrarPosicion(aux->listaCiudad->buscarPos(temp2));
							aux2->listaRestaurante->MostrarPosicion(aux2->listaRestaurante->buscarPos(temp3));	
							aux3->listaMenu->MostrarPosicion(aux3->listaMenu->buscarPos(temp4));
							return;
							}
							cout<<"MENU NO EXISTE";	
							return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"MENU NO EXISTE";
			return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"MENU NO EXISTE";
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
										listaPais->MostrarPosicion(listaPais->buscarPos(temp));
										aux->listaCiudad->MostrarPosicion(aux->listaCiudad->buscarPos(temp2));
										aux2->listaRestaurante->MostrarPosicion(aux2->listaRestaurante->buscarPos(temp3));	
										aux3->listaMenu->MostrarPosicion(aux3->listaMenu->buscarPos(temp4));
										aux4->listaProd->MostrarPosicion(aux4->listaProd->buscarPos(temp5));
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"PRODUCTO NO EXISTE"<<endl;
								return;
							}else{
								cout<<"PRODUCTO NO EXISTE"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"PRODUCTO NO EXISTE"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"PRODUCTO NO EXISTE"<<endl;
	return;
}

void cargarArchivo::SubMenu46(){
	string cedula;
	cout<< "Ingrese el numero de cedula que desea encontrar: ";
	cin >> cedula;
	
	listaCliente->MostrarPosicion(listaCliente->buscarPos(stoi(cedula)));
}

//Modificar

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
		cout << "7. Compras"<<endl;
		cout << "8. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "5.1 Buscar Pais"<<endl;
			SubMenu51();
			break;
		}
		case '2':{
			cout<< "5.2 Buscar Ciudad"<<endl;
			SubMenu52();			
			break;
		}
		case '3':{
			cout<< "5.3 Buscar Restaurante"<<endl;
			SubMenu53();
			break;
		}
		case '4':{
			cout<< "5.4 Buscar Menu"<<endl;
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
			cout<<"5.7 Modificar Compras"<<endl;	
			SubMenu57();	
			break;
		}
		case '8':{
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
	string nom;
	cout<< "Ingrese el codigo de pais: ";
	cin >> cod;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(cod);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				cout<< "Ingrese el nombre de pais: ";
				cin >> nom;
				aux->pais = nom;
				return;
			}
		aux=aux->siguiente;
		}
}
}

void cargarArchivo::SubMenu52(){
	string codPais;
	string nom;
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
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						cout<< "Ingrese el nombre de ciudad: ";
						cin >> nom;
						aux2->ciudad = nom;
						return;
					}
					aux2= aux2->siguiente;
				}
			}
		aux=aux->siguiente;
		}
	}
	cout<<"PAIS NO EXISTE";
}

void cargarArchivo::SubMenu53(){
	string codPais;
	string nom;
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
						pnodoRest aux3 = aux2->listaRestaurante->primero;
						pnodoRest head = aux2->listaRestaurante->primero;
							while(aux3->siguiente!=head && aux3->cod!=temp3)
								aux3=aux3->siguiente;
							if(aux3->cod == temp3){
							cout<< "Ingrese el nombre de restaurante: ";
							cin >> nom;
							aux3->rest = nom;
							return;
							}
					}
					aux2= aux2->siguiente;
				}cout<<"CIUDAD NO EXISTE";
				return;	
			}
		aux=aux->siguiente;
		}	
	cout<<"PAIS NO EXISTE";
	}
}

void cargarArchivo::SubMenu54(){
	string codPais;
	string nom;
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
							pnodoMenu aux4 = aux3->listaMenu->primero;
								while(aux4!=NULL){
									if(aux4->cod == temp4){
										cout<< "Ingrese el nombre del menu: ";
										cin >> nom;
										aux4->nomMenu = nom;
										return;
									}
								aux4= aux4->siguiente;
								}
							}
							cout<<"RESTAURANTE NO EXISTE";	
							return;
					}
					aux2= aux2->siguiente;
				}
			cout<<"CIUDAD NO EXISTE";
			return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"PAIS NO EXISTE";
}

void cargarArchivo::SubMenu55(){
	string producto;
	string kcal;
	string precio;
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
										pnodoProd aux5 = aux4->listaProd->ReturnPosicion(aux4->listaProd->buscarPos(temp5));
										cout<< "\nIngrese el nombre de producto: ";
										cin >> producto;
										cout<< "\nIngrese cantidad de Kcal: ";
										cin >> kcal;
										cout<< "\nIngrese el precio de producto: ";
										cin >> precio;
										int kcalMod = stoi(kcal);
										int precioMod = stoi(precio);
										aux5->nomProd =producto;										
										aux5->kcal = kcalMod;
										aux5->precio = precioMod;
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"Menu no existe"<<endl;
								return;
							}else{
								cout<<"Restaurante no existe"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"Ciudad no existe"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Pais no existe"<<endl;
	return;
}

void cargarArchivo::SubMenu56(){
	string cedula;
	string nom;
	cout<< "Ingrese el numero de cedula que desea modificar: ";
	cin >> cedula;
	int temp = stoi(cedula);
	double temp2 = listaCliente->buscarPos(stoi(cedula));
	pnodo aux = listaCliente->GetPrimero();
	if(temp2!=-1 ){
		while(aux!=NULL){
			if(aux->valor == temp){
				cout<< "Ingrese el nombre del cliente: ";
				cin >> nom;
				aux->nombre = nom;
				return;
			}
		aux=aux->siguiente;
		}
}
}

void cargarArchivo::SubMenu57(){
	if(listaFila->ListaVacia() == true) {
		cout<< "No hay compras en progreso ";
		return;
	}
	string cedula;
	string codProducto;
	string cantidadMod;
	string codProductoMod;
	char opt;
	cout<< "Ingrese el numero de cedula del cliente: ";
	cin >> cedula;
	cout<< "Ingrese el codigo del producto: ";
	cin >> codProducto;
	int temp = stoi(cedula);
	int temp2 = stoi(codProducto);
	pnodoFila aux = listaFila->GetPrimero();
	if(listaCliente->buscarPos(stoi(cedula))!=-1){
		while(aux!=NULL){
			if(aux->valor == temp){
				pnodoComp aux2 = aux->listaComp->GetPrimero();
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						cout<<"Desea cambiar 1.codigo o 2.cantidad:"<<endl;
						cin >> opt;
						switch(opt){
						case '1':{
						SubMenu571(aux2);
						break;
						}
						case '2':{
						cout<<"Inserte nueva cantidad:"<<endl;
						cin >> cantidadMod;
						int temp3 = stoi(cantidadMod);
						aux2->cantidad = temp3;
						break;
						}
						
					return;
				}
				aux2=aux2->siguiente;
		}
	}
		aux=aux->siguiente;
		}
		cout<<"Producto no existe"<<endl;
		return;
}

}cout<<"Cedula no existe"<<endl;
return;
}

void cargarArchivo::SubMenu571(pnodoComp Prod){
	string producto;
	string kcal;
	string precio;
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
										pnodoProd aux5 = aux4->listaProd->ReturnPosicion(aux4->listaProd->buscarPos(temp5));
										Prod->cod = aux5->cod;
										Prod->kcal = aux5->kcal;
										Prod->precio = aux5->precio;
										Prod->nomProd = aux5->nomProd;
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"Menu no existe"<<endl;
								return;
							}else{
								cout<<"Restaurante no existe"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"Ciudad no existe"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Pais no existe"<<endl;
	return;
}


//Buscar

void cargarArchivo::SubMenu6(){
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      6. Reportes   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Lista de Paises"<<endl;
		cout << "2. Lista de Ciudades por Pais"<<endl;
		cout << "3. Lista de Restaurantes por Ciudad"<<endl;
		cout << "4. Lista de Clientes"<<endl;
		cout << "5. Restaurante MAS buscado"<<endl;
		cout << "6. Menu MAS buscado"<<endl;
		cout << "7. Producto MAS comprado"<<endl;
		cout << "8. Consultar Precio de Producto"<<endl;
		cout << "9. Volver"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: "<<endl;		
		char opt;
		cin >> opt;
	switch(opt){
		case '1':{
			cout<< "6.1 Lista de Paises"<<endl;
			SubMenu61();
			break;
		}
		case '2':{
			cout<< "6.2 Lista de Ciudades por Pais"<<endl;
			SubMenu62();			
			break;
		}
		case '3':{
			cout<< "6.3 Lista de Restaurantes por Ciudad"<<endl;
			SubMenu63();
			break;
		}
		case '4':{
			cout<< "6.4 Lista de Clientes"<<endl;
			SubMenu64();
			break;
		}
		case '5':{
			cout<< "6.5 Restaurante MAS buscado"<<endl;
			SubMenu65();
			break;
		}
		case '6':{
			cout<< "6.6 Menu MAS buscado"<<endl;
			SubMenu66();
			break;
		}
		case '7':{
			cout<< "6.7 Producto MAS comprado"<<endl;
			SubMenu67();
			break;
		}
		case '8':{
			cout<< "6.8 Consultar Precio de Producto"<<endl;
			SubMenu68();
			break;
		}
		case '9':{
			cout<<"Volviendo a Main Menu"<<endl;			
			break;
		}
		default :{
			cout<< "!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
			break;
		}
	}
}

//Reporte de Paises
void cargarArchivo::SubMenu61(){
	cout<< "\nSe esta generando el archivo Reporte_Paises.txt\n.\n.\n.\n";
	listaPais->reportePaises();
}

//Reporte de Ciudades por pais
void cargarArchivo::SubMenu62(){
	string codPais;
	cout<< "Ingrese el codigo de pais: ";
	cin >> codPais;
	pnodoPais aux = listaPais->GetPrimero();
	int temp = stoi(codPais);
	if(listaPais->buscarPais(temp)==true){
		while(aux!=NULL){
			if(aux->cod == temp){
				cout<< "\nSe esta generando el archivo Reporte_Ciudades_"+aux->pais+".txt\n.\n.\n.\n"<<endl;
				aux->listaCiudad->reporteCiudades(aux->pais);
				return;
			}
		aux=aux->siguiente;
		}
	}
	cout<<"El pais ingresado no existe";
}

//Reporte de Restaurantes por pais
void cargarArchivo::SubMenu63(){
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
				pnodoCiudad aux2 = aux->listaCiudad->primero;
				while(aux2!=NULL){
					if(aux2->cod == temp2){
						cout<< "\nSe esta generando el archivo Reporte_Restaurantes_"+aux2->ciudad+".txt\n.\n.\n.\n"<<endl;
						aux2->listaRestaurante->reporteRestaurante(aux2->ciudad);
						return;
					}
					aux2= aux2->siguiente;
				}
				cout<<"CIUDAD NO EXISTE";
				return;	
			}
		aux=aux->siguiente;
		}	
	cout<<"PAIS NO EXISTE";
	}
}

//Reporte de Clientes
void cargarArchivo::SubMenu64(){
	cout<< "\nSe esta generando el archivo Reporte_Clientes.txt\n.\n.\n.\n"<<endl;
	listaCliente->reporteClientes();

}

//Reporte Restaurante mas buscado 
void cargarArchivo::SubMenu65() {
	int contTop = 0;
    int codPaisTop = 0;
    int codCiudadTop = 0;
    int codRestTop = 0;
    string restTop = "";
    
	pnodoPais aux = listaPais->GetPrimero();
		while(aux!=NULL){
			pnodoCiudad aux2 = aux->listaCiudad->primero;
			while(aux2!=NULL){
				pnodoRest aux3 = aux2->listaRestaurante->buscarMayor();
				if(aux3 == NULL){
				}else{
					if(aux3->counter > contTop){
					contTop = aux3->counter;
					codPaisTop = aux->cod;
					codCiudadTop = aux2->cod;
					codRestTop = aux3->cod;
					restTop = aux3->rest;
					}
				}
			aux2= aux2->siguiente;
			}
		aux=aux->siguiente;	
		}
    if (contTop == 0) {
        cout << "\n***AUN NO SE HA BUSCADO NINGUN RESTAURANTE***" << endl << endl;
    }
    
    else {
        cout << "\nSe esta generando el archivo Reporte_Restaurante_Mas_Buscado.txt\n.\n.\n.\n" << endl;
        ofstream archivoSalida("Reporte_Restaurante_Mas_Buscado.txt");
        if (!archivoSalida.is_open()) {
            cerr << "No se pudo abrir el archivo." << endl;
        }
        else {
            archivoSalida << "REPORTE RESTAURANTE MAS BUSCADO " << endl << endl << endl;
            archivoSalida << codPaisTop << ":" << codCiudadTop << ":" << codRestTop << ":" << restTop << endl;
            archivoSalida << "Restaurante buscado : " << contTop <<" veces." <<endl;
            cout << endl;
            archivoSalida.close();
            cout << "Reporte generado";
        }
    }
}

void cargarArchivo::SubMenu66(){
}

void cargarArchivo::SubMenu67(){

}

//Consultar precio de producto
void cargarArchivo::SubMenu68(){
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
	cout<<endl<<endl;
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
										listaPais->MostrarPosicion(listaPais->buscarPos(temp));
										aux->listaCiudad->MostrarPosicion(aux->listaCiudad->buscarPos(temp2));
										aux2->listaRestaurante->MostrarPosicion(aux2->listaRestaurante->buscarPos(temp3));	
										aux3->listaMenu->MostrarPosicion(aux3->listaMenu->buscarPos(temp4));
										cout << "\nSe esta generando el archivo Reporte_Precio_Producto.txt\n.\n.\n.\n" << endl;
        								ofstream archivoSalida("Reporte_Precio_Producto.txt");
        								if (!archivoSalida.is_open()) {
            								cerr << "No se pudo abrir el archivo." << endl;
        								}
        								else {
	         								archivoSalida << "REPORTE PRECIO DE PRODUCTO " << endl << endl << endl;
	         								archivoSalida << "Pais : "<<aux->pais<<"\n"<<"Ciudad: "<<aux2->ciudad<<"\n"<<"Restaurante: "<<aux3->rest<<"\n"<<"Menu: "<<aux4->nomMenu<<"\n";
									        archivoSalida << aux4->listaProd->MostrarPrecio(aux4->listaProd->buscarPos(temp5));
									        cout << endl;
									        archivoSalida.close();
									        cout << "Reporte generado";
								        }
	         							archivoSalida << "REPORTE PRECIO DE PRODUCTO " << endl << endl << endl;
	         							archivoSalida << "Pais : "<<aux->pais<<"\n"<<"Ciudad: "<<aux2->ciudad<<"\n"<<"Restaurante: "<<aux3->rest<<"\n"<<"Menu: "<<aux4->nomMenu<<"\n";
									    archivoSalida << aux4->listaProd->MostrarPrecio(aux4->listaProd->buscarPos(temp5));
									    cout << endl;
									    archivoSalida.close();
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"Menu no existe"<<endl;
								return;
							}else{
								cout<<"Restaurante no existe"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"Ciudad no existe"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Pais no existe"<<endl;
	return;
}

//Comprar
void cargarArchivo::SubMenu8(){
		cout << "Inserte la cedula del usuario" << endl;
		string cedula;
		cin >> cedula;
		int temp = stoi(cedula);
		if(listaCliente->buscarPos(temp) != -1) {
		cout << endl << "----------------------------" << endl;
  		cout << endl << "      8. Comprar   " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Añadir"<<endl;
		cout << "2. Hacer fila"<<endl;
		cout << "3. Salir"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";
		char opt;
		cin >> opt;
		switch(opt) {
    	case '1' :
		{SubMenu81(temp);
			Menu();
			break;
		 } 
			
		case '2':
			{if(listaFila->largoLista() == 5)
			{
				cout << "La fila esta llena"<<endl;
				break;
			}else{
				pnodo aux = listaCliente->GetPrimero();
				while(aux->valor!=temp) {
						aux = aux->siguiente;
} 
listaFila->InsertarInicio(aux->valor,aux->nombre);
			}
			break;
			}
			
    	case '3':
    		{cout<<"Volviendo a Main Menu"<<endl;
    		break;
    	default: 
    cout<<"!!! Valor incorrecto, ingresar un valor dentro del rango !!!"<<endl;
	break;
			}
    		
	}
		}else{
		cout << "Cedula invalida" << endl;
		}
}

void cargarArchivo::SubMenu81(int cedula){
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
										pnodoProd aux5 = aux4->listaProd->ReturnPosicion(aux4->listaProd->buscarPos(temp5));
										cout<< "Ingrese la cantidad de productos: ";
										string cant;
										cin >> cant;
										int cantidad = stoi(cant);
										pnodo aux6 = listaCliente->GetPrimero();
										while(aux6->valor!=cedula) {
											aux6 = aux6->siguiente;
										}
											listaCliente->InsertarCompra(aux5->cod,aux5->nomProd,aux5->kcal,aux5->precio,cantidad,aux6->listaComp);
											aux5->counter =+cantidad;
										return;
									}
								aux4= aux4->siguiente;
								}
								cout<<"Menu no existe"<<endl;
								return;
							}else{
								cout<<"Restaurante no existe"<<endl;
								return;
							}
						}
				aux2= aux2->siguiente;
				}
				cout<<"Ciudad no existe"<<endl;
				return;
			}
		aux=aux->siguiente;
		}		
	}
	cout<<"Pais no existe"<<endl;
	return;
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
		cout << "8. Comprar"<<endl;
		cout << "9. Salir"<<endl;
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
    	case '3':
    		SubMenu3();
    		Menu();
			break;
    	case '4':
    		SubMenu4();
    		Menu();
    		break;
    	case '5':
    		SubMenu5();
    		Menu();
			break;
		case '6':
    		SubMenu6();
    		Menu();
			break;
		case '7':
    		cout<<"Ingresando a Submenu 7..."<<endl;
    		Menu();
			break;
		case '8':	
			SubMenu8();
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




