#include "listaDGrafo.cpp"
#include "listaSimple.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>

using namespace std;

class Grafos { 
   public:
    Grafos() {
    	//Constructor
    	Grafo1 = new listaDGrafo();
    	Grafo2 = new listaDGrafo();
    	verticesKruskal = new listaDVertice();
    	
	 }
    ~Grafos();

    void Menu();
	void cargaGrafo1();
	void cargaGrafo2();
	void agregarNodo1(string source, string destination, int cost);
	void agregarNodo2(string source, string destination);
	void MostrarListaAdj();
	void MostrarListaAdj2();
	void Profundidad(string startNode);
	void Anchura(string startNode);
	bool existeNodo(string nodo);
	void SubMenu6();
	void SubMenu7();




	
//	private:
		unordered_map<string, vector<pair<string, int>>> listaAdj;
		unordered_map<string, vector<string>> listaAdj2;
		listaDGrafo* Grafo1;
		listaDGrafo* Grafo2;
		listaDVertice* verticesKruskal;

};



Grafos::~Grafos(){

}

void Grafos::agregarNodo1(string origen, string destino, int costo) {
        listaAdj[origen].push_back(make_pair(destino, costo));
        listaAdj[destino].push_back(make_pair(origen, costo));
    }
    
void Grafos::agregarNodo2(string origen, string destino) {
        listaAdj2[origen].push_back(destino);
        listaAdj2[destino].push_back(origen);
    }

void Grafos::MostrarListaAdj() {
        for (auto it = listaAdj.begin(); it != listaAdj.end(); ++it) {
            cout << it->first << ": ";
            for (auto edge = it->second.begin(); edge != it->second.end(); ++edge) {
                cout << "(" << edge->first << ", " << edge->second << ") ";
            }
            cout << endl;
        }
    }
    
void Grafos::MostrarListaAdj2() {
        for (auto it = listaAdj2.begin(); it != listaAdj2.end(); ++it) {
            cout << it->first << ": ";
        	for (auto edge = it->second.begin(); edge != it->second.end(); ++edge) {
            cout << "(" << *edge << ") ";
        	}
            cout << endl;
        }
    }


void Grafos::cargaGrafo1() {
    try {
        ifstream archivoCiudades1("Archivos/Ciudades1.txt");
        ifstream archivoDistancias1("Archivos/Distancias1.txt");

        if (!archivoCiudades1.is_open() || !archivoDistancias1.is_open())
            cout << "Error al abrir el archivo." << endl;

        string nodo;
        string nombre;
        string origen;
        string destino;
        string costo;
        
        while (getline(archivoCiudades1, nodo, ';')) {
            if (getline(archivoCiudades1, nombre)) {
                Grafo1->InsertarFinal(nodo, nombre);
            } else {
                // Handle empty line or other issues
                //cout << "Error: Empty line or incomplete data in Ciudades1.txt." << endl;
            }
        }

        while (getline(archivoDistancias1, origen, ';')) {
            if (getline(archivoDistancias1, destino, ';') && getline(archivoDistancias1, costo)) {
            	agregarNodo1(origen, destino, stoi(costo));
                pnodoGrafo temp = Grafo1->Buscador(origen);
                pnodoGrafo temp2 = Grafo1->Buscador(destino);

                if (temp != NULL && temp2 != NULL) {
                    temp->vertices->InsertarFinal(stoi(costo), destino);
                    temp2->vertices->InsertarFinal(stoi(costo), origen);
                    verticesKruskal->InsertarOrdenadoVertice(stoi(costo), origen, destino);
                }
            } else {
                // Handle empty line or other issues
                //cout << "Error: Empty line or incomplete data in Distancias1.txt." << endl;
            }
        }

        archivoCiudades1.close();
        archivoDistancias1.close();

        cout << endl << "*********************************************************************************" << endl << endl;

    } catch (const std::exception &e) {
        cerr << "Error: " << e.what() << endl;
        return;
    }
    cout << "\t .:GRAFO #1:." << endl << endl;
    Grafo1->Mostrar();
    cout<<"\n\n\t .:MATRIZ DE ADYACENCIA:. "<<endl<<endl;
    MostrarListaAdj();
}



void Grafos::cargaGrafo2() {
    try {
        ifstream archivoCiudades2("Archivos/Ciudades2.txt");
        ifstream archivoDistancias2("Archivos/Distancias2.txt");

        if (!archivoCiudades2.is_open() || !archivoDistancias2.is_open())
            cout << "Error al abrir el archivo." << endl;

        string nodo;
        string nombre;
        string origen;
        string destino;

        while (getline(archivoCiudades2, nodo, ';')) {
            if (getline(archivoCiudades2, nombre)) {
                Grafo2->InsertarFinal(nodo, nombre);
            } else {

            }
        }

        while (getline(archivoDistancias2, origen, ';')) {
            if (getline(archivoDistancias2, destino)) {
            	agregarNodo2(origen, destino);
                pnodoGrafo temp3 = Grafo2->Buscador(origen);
                pnodoGrafo temp4 = Grafo2->Buscador(destino);

                if (temp3 != NULL && temp4 != NULL) {
                    temp3->vertices->InsertarFinal(0, destino);
                    temp4->vertices->InsertarFinal(0, origen);
                }
            } else {

            }
        }

        archivoCiudades2.close();
        archivoDistancias2.close();

        cout << endl << "*********************************************************************************" << endl << endl;

    } catch (const std::exception &e) {
        cerr << "Error: " << e.what() << endl;
        return;
    }
    cout << "\t .:GRAFO #2:." << endl << endl;
    Grafo2->MostrarSinCosto();
    cout<<"\n\n\t .:MATRIZ DE ADYACENCIA:. "<<endl<<endl;
    MostrarListaAdj2();
}


void Grafos::Profundidad(string startNode) {
	cout<<endl;
	lista* cola = new lista();
    unordered_set<string> visited;
	cola->InsertarInicio(startNode);
    visited.insert(startNode);

    while (!cola->ListaVacia()) {
        string currentNode = cola->primero->valor;
        cola->MostrarPila();
        cola->BorrarInicio();
	
        cout << currentNode << " - ";

        for (auto neighbor : listaAdj2[currentNode]) {
            if (visited.find(neighbor) == visited.end()) {
                cola->InsertarInicio(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    cout <<endl;
}
    
void Grafos::Anchura(string startNode) {
	cout<<endl;
	lista* cola = new lista();
    unordered_set<string> visited;
	cola->InsertarFinal(startNode);
    visited.insert(startNode);

    while (!cola->ListaVacia()) {
        string currentNode = cola->primero->valor;
        cola->MostrarCola();
        cola->BorrarInicio();

        cout << currentNode << " - ";

        for (auto neighbor : listaAdj2[currentNode]) {
            if (visited.find(neighbor) == visited.end()) {
                cola->InsertarFinal(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    cout <<endl;
}

bool Grafos::existeNodo(string nodo) {
    return listaAdj2.find(nodo) != listaAdj2.end();
}

void Grafos::SubMenu6(){
	cout<<"Ingrese Punto de Partida: "<<endl;
	string pp;
	cin >> pp;
	if(existeNodo(pp)){
    	Anchura(pp);
    }else{
    	cout<<"Punto de Partida NO existe."<<endl<<endl;
    	SubMenu6();
	}
}

void Grafos::SubMenu7(){
	cout<<"Ingrese Punto de Partida: "<<endl;
	string pp;
	cin >> pp;
	if(existeNodo(pp)){
    	Profundidad(pp);
    }else{
    	cout<<"Punto de Partida NO existe."<<endl<<endl;
    	SubMenu7();
	}
}


void Grafos::Menu(){
	while(true){
	    cout << endl << "----------------------------" << endl;
        cout << endl << "      Menu Principal  " << endl;
        cout << endl << "----------------------------" << endl;
		cout << endl;
		cout << "1. Leer Archivos"<<endl;
		cout << "2. Prim"<<endl;
		cout << "3. Kruskal"<<endl;
		cout << "4. Dijkstra"<<endl;
		cout << "5. Puntos de articulacion"<<endl;
		cout << "6. Anchura"<<endl;
		cout << "7. Profundidad"<<endl;
		cout << "8. Salir"<<endl;
		cout <<endl<<endl;
		cout <<"Seleccione una opcion: ";
		
		char opt;
		cin >> opt;
    
    switch(opt) {
    	case '1' : 
    		listaAdj.clear();
    		listaAdj2.clear();
    		Grafo1 = new listaDGrafo();
    		Grafo2 = new listaDGrafo();    		
			cargaGrafo1();
			cargaGrafo2();
			cout<<"\n\nGrafo 1 y Grafo 2 han sido cargados!"<<endl<<endl;
			Menu();
			break;
    	case '2':
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
		case '6':{
			SubMenu6();
    		Menu();
			break;
		}
		case '7':{
			SubMenu7();
    		Menu();
			break;
		}
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



int main(){
		cout<<"*************TAREA GRAFOS************************"<<endl<<endl;
		cout<<"Evaluacion en DIJKSTRA, KRUSKAL, PRIM Y MAS"<<endl;
		cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
	Grafos g;
	g.Menu();
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
