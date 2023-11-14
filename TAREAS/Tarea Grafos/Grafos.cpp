#include "listaDGrafo.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

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
	void Prim();
	void algPrim(listaDGrafo* grafo, listaDGrafo* AEM1, string partida);
	void marcarVisitados(listaDGrafo* grafo, string nodo);
	void marcarNoVisitados();
	void mostrarVisitados(listaDGrafo* grafo);
	void Kruskal();
	void agregarNodo(string source, string destination, int cost);
	void MostrarListaAdj();



	
//	private:
		listaDGrafo* Grafo1;
		listaDGrafo* Grafo2;
		listaDVertice* verticesKruskal;
		unordered_map<string, vector<pair<string, int>>> listaAdj;

};



Grafos::~Grafos(){

}

void Grafos::agregarNodo(string origen, string destino, int costo) {
        listaAdj[origen].push_back(make_pair(destino, costo));
        listaAdj[destino].push_back(make_pair(origen, costo));
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
            	agregarNodo(origen, destino, stoi(costo));
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
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    cout << "\t .:GRAFO #2:." << endl << endl;
    Grafo2->MostrarSinCosto();
}


void Grafos::Prim() {
    int largo = Grafo1->largoLista();
    if(largo == 0){
    	cout << "El grafo tiene " << largo << " nodos. Cargue los archivos" << endl << endl;
    	Menu();
	}else{
	
    listaDGrafo* AEM = new listaDGrafo();
    
    string opt;
    bool puntoPartidaValido = false;
    
    while (!puntoPartidaValido) {
        cout << "Seleccione punto de partida: ";
        cin >> opt;

        if (Grafo1->BuscadorBool(opt)) {
            cout << "Punto de partida valido." << endl << endl;
            AEM->InsertarFinal(Grafo1->Buscador(opt)->valor, Grafo1->Buscador(opt)->nombre);
            Grafo1->Buscador(opt)->visitado = true;
            algPrim(Grafo1, AEM, opt);
            puntoPartidaValido = true;
        } else {
            cout << "###ERROR: Punto de partida invalido###" << endl << endl;
        }
    }
    }
}

void Grafos::algPrim(listaDGrafo* grafo, listaDGrafo* AEM1, string partida) {
	listaDGrafo*& grafo1 = grafo;
	listaDGrafo*& AEM = AEM1;
	int costo = 0;
	grafo1->Buscador(partida)->visitado = true;
	cout<<"LArgo: "<<grafo1->largoLista()<<" primero: "<<grafo1->primero->valor<<endl<<endl;
    while (AEM->largoLista() < grafo1->largoLista()) {
    	mostrarVisitados(grafo1);
        string nombreOrigen;
        pnodoGrafo temp = AEM->primero;
        pnodoVertice menor = NULL;
        // Verificar si todos los nodos han sido visitados
        if (grafo1->todosVisitados()) {
            break;
        }
        while (temp != NULL ) {
            pnodoVertice temp2 = grafo1->Buscador(temp->valor)->vertices->primero;
            while (temp2 != NULL ) {
                if ( !temp2->visitado && (menor == NULL || temp2->costo < menor->costo)) {
                    nombreOrigen = temp->valor;
                    menor = temp2;
                }
                temp2 = temp2->siguiente;
            }
            temp = temp->siguiente;
        }
        if (menor != NULL) {
        	marcarVisitados(grafo1, menor->destino);
            cout << nombreOrigen << endl;
            cout << "El menor es: " << menor->destino << " valor: " << menor->costo << endl << endl;
            costo = costo + menor->costo;
			menor->visitado = true;
            grafo1->Buscador(menor->destino)->vertices->BuscadorN(nombreOrigen)->visitado = true;
			grafo1->Buscador(nombreOrigen)->vertices->BuscadorN(menor->destino)->visitado = true;
            pnodoGrafo insert = grafo1->Buscador(menor->destino);
            AEM->InsertarFinal(insert->valor, insert->nombre);
            AEM->Buscador(nombreOrigen)->vertices->InsertarFinal(menor->costo,menor->destino);
            AEM->Buscador(menor->destino)->vertices->InsertarFinal(menor->costo,nombreOrigen);
        }else{
        	cout<<"Visitados todos"<<endl;
        	break;
		}
    }
    //AEM->Mostrar();
   // AEM->MostrarFile(costo);
    grafo1->~listaDGrafo();
    AEM->~listaDGrafo();
}

void Grafos::Kruskal() {

}

void Grafos::marcarVisitados(listaDGrafo* grafo, string nodo){
	pnodoGrafo temp = grafo->primero;
	while(temp != NULL){
		if(temp->nombre == nodo){
			temp->visitado = true;
		}else{
			pnodoVertice temp2 = temp->vertices->primero;
			while(temp2 != NULL){
				if(temp2->destino == nodo ){
					temp2->visitado = true;
				}
			temp2 = temp2->siguiente;
		}	
		}	
	temp = temp->siguiente;
	}
}



void Grafos::mostrarVisitados(listaDGrafo* grafo){
	pnodoGrafo temp = grafo->primero;
	while(temp != NULL){
		cout<< temp->valor<<"-"<<temp->nombre<<"-"<<endl;
		pnodoVertice temp2 = temp->vertices->primero;
		while(temp2 != NULL){
			if(temp2->visitado == true ){
				cout<<temp2->destino<<":"<<temp2->costo<<endl;
			}
		temp2 = temp2->siguiente;
		}
		cout<<endl;	
		temp = temp->siguiente;
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
			cargaGrafo1();
		//	cargaGrafo2();
			cout<<"\n\nGrafo 1 y Grafo 2 han sido cargados!"<<endl<<endl;
			listaAdj.clear();
			Menu();
			break;
    	case '2':
			Prim();
    		Menu();
    		break;
    	case '3':
    		listaAdj.clear();
    		verticesKruskal->MostrarKruskal();
    		Kruskal();
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
