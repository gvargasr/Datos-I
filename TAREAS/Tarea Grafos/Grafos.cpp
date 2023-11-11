#include "listaDGrafo.cpp"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Grafos { 
   public:
    Grafos() {
    	//Constructor
    	Grafo1 = new listaDGrafo();
    	Grafo2 = new listaDGrafo();
	 }
    ~Grafos();

    void Menu();
	void cargaGrafo1();
	void cargaGrafo2();
	void Prim();
	void algPrim(listaDGrafo* grafo1, listaDGrafo* AEM);
	void marcarVisitados(listaDGrafo* grafo, string nodo);
	void marcarNoVisitados();

	
//	private:
		listaDGrafo* Grafo1;
		listaDGrafo* Grafo2;
};



Grafos::~Grafos(){

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
                pnodoGrafo temp = Grafo1->Buscador(origen);
                pnodoGrafo temp2 = Grafo1->Buscador(destino);

                if (temp != NULL && temp2 != NULL) {
                    temp->vertices->InsertarFinal(stoi(costo), destino);
                    temp2->vertices->InsertarFinal(stoi(costo), origen);
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
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
    cout << "\t .:GRAFO #1:." << endl << endl;
    Grafo1->Mostrar();
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
            algPrim(Grafo1, AEM);
            puntoPartidaValido = true;
        } else {
            cout << "###ERROR: Punto de partida invalido###" << endl << endl;
        }
    }
    }
}




void Grafos::algPrim(listaDGrafo* grafo1, listaDGrafo* AEM) {
	cout<<"primero visitado? "<<grafo1->Buscador(AEM->primero->valor)->visitado;
    while (!grafo1->todosVisitados()) {
        string nombreI;
        pnodoGrafo temp = AEM->primero;
        pnodoVertice menor = NULL;
        // Verificar si todos los nodos han sido visitados
        if (grafo1->todosVisitados()) {
            break;
        }
        while (temp != NULL ) {
            pnodoVertice temp2 = grafo1->Buscador(temp->valor)->vertices->primero;
            while (temp2 != NULL && !grafo1->Buscador(temp->valor)->vertices->todosVisitados()) {
                if ( !temp2->visitado && (menor == NULL || temp2->costo < menor->costo)) {
                    nombreI = temp->valor;
                    menor = temp2;
                    temp2->visitado = true;
                }

                temp2 = temp2->siguiente;
            }

            temp = temp->siguiente;
        }
        if (menor != NULL) {
        	marcarVisitados(grafo1, menor->destino);
            cout << nombreI << endl;
            cout << "El menor es: " << menor->destino << " valor: " << menor->costo << endl << endl;
			menor->visitado = true;
            grafo1->Buscador(menor->destino)->vertices->BuscadorN(nombreI)->visitado = true;
			grafo1->Buscador(nombreI)->vertices->BuscadorN(menor->destino)->visitado = true;
            pnodoGrafo insert = grafo1->Buscador(menor->destino);
            AEM->InsertarFinal(insert->valor, insert->nombre);
            AEM->Buscador(nombreI)->vertices->InsertarFinal(menor->costo,menor->destino);
            AEM->Buscador(menor->destino)->vertices->InsertarFinal(menor->costo,nombreI);
        }else{
        	cout<<"Visitados todos"<<endl;
        	break;
		}
    }
    AEM->Mostrar();
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
			cargaGrafo2();
			cout<<"\n\nGrafo 1 y Grafo 2 han sido cargados!"<<endl<<endl;
			Menu();
			break;
    	case '2':
			Prim();
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
