#include <iostream>
#include <fstream>
using namespace std;

class NodoBinario {
public:
    string valor;
    string valor2;
    NodoBinario* izq;
    NodoBinario* der;

    NodoBinario(string v, string v2) {
    	valor = v;
        valor2 = v2;
        izq = NULL;
        der = NULL;
    }
};

class Binario {

public:
	NodoBinario* raiz;
    Binario() {
        raiz = NULL;
    }
    
    
    void BuscaNodo(NodoBinario* &ra, string v) {
        if (ra == NULL) {
            cout<<"El cliente "<<v<<" no se encuentra en el arbol."<<endl<<endl;
        }
        else if (stoi(v) < stoi(ra->valor)) {
            BuscaNodo(ra->izq, v);
        }
        else if (stoi(v) > stoi(ra->valor)) {
            BuscaNodo(ra->der, v);
        }
        else {
            cout << "Cliente encontrado: "<<"\nCedula: "<<ra->valor<<"\nNombre: "<<ra->valor2 << endl;
        }
    }    

    void InsertaNodo(NodoBinario* &ra, string v, string v2) {
        if (ra == NULL) {
            ra = new NodoBinario(v,v2);
        }
        else if (stoi(v) < stoi(ra->valor)) {
            InsertaNodo(ra->izq, v,v2);
        }
        else if (stoi(v) > stoi(ra->valor)) {
            InsertaNodo(ra->der, v,v2);
        }
        else {
            cout << "El cliente con cedula "<<v<<" ya existe en el arbol." << endl;
        }
    }

    void PreordenR(NodoBinario* R) {
        if (R != NULL) {
            cout << R->valor<<":"<<R->valor2<< " - ";
            PreordenR(R->izq);
            PreordenR(R->der);
        }
    }

    void InordenR(NodoBinario* R) {
        if (R != NULL) {
            InordenR(R->izq);
            cout << R->valor<<":"<<R->valor2<< " - ";
            InordenR(R->der);
        }
    }

    void PostordenR(NodoBinario* R) {
        if (R != NULL) {
            PostordenR(R->izq);
            PostordenR(R->der);
            cout << R->valor<<":"<<R->valor2<< " - ";
        }
    }

    void Insertar(string v, string v2) {
        InsertaNodo(raiz, v, v2);
    }
    
    void cargaInicial(){
	ifstream archivo;

	try{
	ifstream archivo("Clientes.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
  //      return 1;
    }

    ofstream archivoNuevo("Clientes_temp.txt");
    if (!archivoNuevo.is_open()) {
        cout << "Error al crear el archivo temporal." << endl;
 //       return 1;
    }

    string codigo;
    string pais;
    while (getline(archivo, codigo, ';')) {
        getline(archivo, pais);
        if (!codigo.empty() && pais.find(";1") != pais.length() - 2) {
        	this->Insertar(codigo,pais);
        //	arbol2->Insertar(codigo,pais);
            archivoNuevo << codigo << ";" << pais << endl;
        }
    }

    archivo.close();
    archivoNuevo.close();

    if (remove("Clientes.txt") != 0) {
        cout << "Error al eliminar el archivo original." << endl;
 //       return 1;
    }
    if (rename("Clientes_temp.txt", "Clientes.txt") != 0) {
        cout << "Error al renombrar el archivo temporal." << endl;
 //       return 1;
    }

    cout << endl << "*********************************************************************************" << endl << endl;
    
		} catch(const std::exception &e) {
	        std::cerr << "Error: " << e.what() << std::endl;
	        return ; // Salir del programa con código de error
	    }
	    
	//    arbol2->InordenR(arbol2->raiz);
	}
	
	void Menu(){
	while(true){
	    cout << endl << "----------------------------" << endl;
        cout << endl << "      Menu Principal  " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Buscar Cliente"<<endl;
		cout << "2. Insertar Cliente"<<endl;
		cout << "3. Eliminar Cliente"<<endl;
		cout << "4. Purgar Archivo Clientes"<<endl;
		cout << "5. Reindexar Clientes"<<endl;
		cout << "6. Imprimir Arbol Clientes"<<endl;
		cout << "7. Imprimir Cache"<<endl;
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
    //		SubMenu2();
    		Menu();
    		break;
    	case '3':
    //		SubMenu3();
    		Menu();
			break;
    	case '4':
    //		SubMenu4();
    		Menu();
    		break;
    	case '5':
    //		SubMenu5();
    		Menu();
			break;
		case '6':
    //		SubMenu6();
    		Menu();
			break;
		case '7':
    		cout<<"Ingresando a Submenu 7..."<<endl;
    		Menu();
			break;
		case '8':
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
	
	void SubMenu1(){
		cout<<"Digite la cedula que desea buscar: "<<endl;
		string cedula;
		cin >> cedula;
		this->BuscaNodo(raiz, cedula);
	}
	
};

int main() {
    Binario arbol;
    arbol.cargaInicial();
    arbol.Menu();
    
    
    
  /* 
    
    cout<<endl<<endl<<endl;
    arbol.Insertar("5","A");
    arbol.Insertar("3","B");
    arbol.Insertar("7","C");
    arbol.Insertar("1","D");
    arbol.Insertar("4","E");
    arbol.Insertar("6","F");
    arbol.Insertar("8","G");

    cout << "Preorden: ";
    arbol.PreordenR(arbol.raiz);
    cout << endl;

    cout << "Inorden: ";
    arbol.InordenR(arbol.raiz);
    cout << endl;

    cout << "Postorden: ";
    arbol.PostordenR(arbol.raiz);
    cout << endl;
*/
    return 0;
}
