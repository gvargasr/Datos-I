#include "listaDGrafo.cpp"
#include "listaSimple.cpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <limits>

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
	void agregarNodo1(string origen, string destino, int costo);
	void agregarNodo2(string source, string destination);
	void MostrarListaAdj();
	void MostrarListaAdj2();
	void Prim();
	void algPrim(listaDGrafo* grafo, listaDGrafo* AEM1, string partida);
	void marcarVisitados(listaDGrafo* grafo, string nodo);
	void mostrarVisitados(listaDGrafo* grafo);
	void Profundidad(string inicio);
	void Anchura(string inicio);
	bool existeNodo(string nodo);
	bool existeNodo1(string inicio, string salida);
	void Dijkstra(string inicio, string destino);
	pair<string,int> Menor(string nodo);
	void SubMenu4();
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
	lista* costos;
	listaDGrafo*& grafo1 = grafo;
	listaDGrafo*& AEM = AEM1;
	int costo = 0;
	grafo1->Buscador(partida)->visitado = true;
	cout<<"LArgo: "<<grafo1->largoLista()<<" primero: "<<grafo1->primero->valor<<endl<<endl;
    while (AEM->largoLista() < grafo1->largoLista()) {
    //	mostrarVisitados(grafo1);
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
            cout << nombreOrigen << menor->destino << " Costo: " << menor->costo << endl << endl;
            costo = costo + menor->costo;
			menor->visitado = true;
            grafo1->Buscador(menor->destino)->vertices->BuscadorN(nombreOrigen)->visitado = true;
			grafo1->Buscador(nombreOrigen)->vertices->BuscadorN(menor->destino)->visitado = true;
            pnodoGrafo insert = grafo1->Buscador(menor->destino);
            AEM->InsertarFinal(insert->valor, insert->nombre);
            AEM->Buscador(nombreOrigen)->vertices->InsertarFinal(menor->costo,menor->destino);
            AEM->Buscador(menor->destino)->vertices->InsertarFinal(menor->costo,nombreOrigen);
        }else{
        	//mostrarVisitados(grafo1);
        	cout<<"Visitados todos"<<endl;
        	break;
		}
    }
    AEM->Mostrar();
    AEM->MostrarFile(costo);
    grafo1->~listaDGrafo();
    AEM->~listaDGrafo();
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

void Grafos::Profundidad(string inicio) {
	cout<<endl;
	lista* cola = new lista();
    unordered_set<string> visitado;
	cola->InsertarInicio(inicio);
    visitado.insert(inicio);

    while (!cola->ListaVacia()) {
        string nodoActual = cola->primero->valor;
        cola->MostrarPila();
        cola->BorrarInicio();
	
        cout << nodoActual << " - ";

        for (auto neighbor : listaAdj2[nodoActual]) {
            if (visitado.find(neighbor) == visitado.end()) {
                cola->InsertarInicio(neighbor);
                visitado.insert(neighbor);
            }
        }
    }
    cout <<endl;
}
    
void Grafos::Anchura(string inicio) {
	cout<<endl;
	lista* cola = new lista();
    unordered_set<string> visited;
	cola->InsertarFinal(inicio);
    visited.insert(inicio);

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

bool Grafos::existeNodo1(string inicio, string salida) {
    if((listaAdj.find(inicio) == listaAdj.end()) || (listaAdj.find(salida) == listaAdj.end())){
    	return false;
	}else{
		return true;
	}
}

pair<string,int> Grafos::Menor(string nodo){
	pair<string,int> menor = make_pair("", numeric_limits<int>::max());
		
	if(listaAdj.find(nodo) != listaAdj.end()){
		for(auto m = listaAdj[nodo].begin(); m != listaAdj[nodo].end(); m++ ){
			if((*m).second < menor.second){
				menor = *m;
			}
		}
	}
	return menor;
	cout<<"Menor: "<<menor.first<<"-"<<menor.second;
}

void Grafos::Dijkstra(string inicio, string destino) {
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> cola; 
    unordered_map<string, int> distancias;
    unordered_map<string, string> anterior;
    unordered_set<string> visitados;

	unordered_map<string, vector<pair<string, int>>>::iterator it = listaAdj.begin();
	while (it != listaAdj.end()) {
	    distancias[it->first] = numeric_limits<int>::max();
	    ++it;
	}

    cola.push(make_pair(0, inicio));
    distancias[inicio] = 0;

	while (!cola.empty()) {
	    string u = cola.top().second;
	    int distU = cola.top().first;
	    cola.pop();
	
	    if (visitados.find(u) == visitados.end()) {
	        visitados.insert(u);
	
        	for (vector<pair<string, int>>::iterator it = listaAdj[u].begin(); it != listaAdj[u].end(); ++it) {
        		string v = it->first;
            	int weight = it->second;

            	if (distU + weight < distancias[v]) {
                	distancias[v] = distU + weight;
                	cola.push(make_pair(distancias[v], v));
                	anterior[v] = u;
            	}
        	}
    	}
    }	
    
	unordered_map<string, int>::const_iterator con = distancias.begin();
	while (con != distancias.end()) {
	    cout << "Conexion " << inicio << con->first << ": ";
	    lista* pila = new lista();
	    string current = con->first;
	
	    while (current != inicio) {
	        pila->InsertarInicio(current);
	        current = anterior[current];
	    }
	
	    cout << inicio << "(0)";
	    int totalCost = con->second;
	    int prev = 0;
	    while (!pila->ListaVacia()) {
	        string node = pila->primero->valor;
	        int costoMin = distancias[node] - prev;
	        cout << " -> " << node << " (" << costoMin << ")";
	        totalCost = totalCost - distancias[node];
	        prev = prev + costoMin;
	        pila->BorrarInicio();
	    }
	
	    cout << ". Costo Total: " << con->second << endl;
	
	    ++con;
	}


    cout << "Ruta mas corta de "<<inicio <<" a " << destino << ": ";
    lista* pila = new lista();
    string current = destino;

    while (current != inicio) {
        pila->InsertarInicio(current);
        current = anterior[current];
    }

    cout << inicio;
    while (!pila->ListaVacia()) {
        cout << " -> " << pila->primero->valor;
		pila->BorrarInicio();
	}

    cout << ". Costo Total: " << distancias[destino] << endl;

	ofstream outFile2("dijkstra.txt");
	con = distancias.begin();
	outFile2 <<" Conexiones"<<"\tNodos: "<<"\t "<<endl<<endl;
	while (con != distancias.end()) {
	    outFile2 << "Conexion " << inicio << con->first << ": ";
	    lista* pila = new lista();
	    string current = con->first;
	
	    while (current != inicio) {
	        pila->InsertarInicio(current);
	        current = anterior[current];
	    }
		string a= inicio;
		string b = "";
	    int totalCost = con->second;
	    int prev = 0;
	    while (!pila->ListaVacia()) {
	    	
	        string node = pila->primero->valor;
	        int costoMin = distancias[node] - prev;
	        outFile2 << "-> "<<a<<node << " (" << costoMin << ") ";
	        totalCost = totalCost - distancias[node];
	        prev = prev + costoMin;
	        a = node;
	        pila->BorrarInicio();
	    }
	
	    outFile2 << ". \nCosto Total: " << con->second << endl;
	
	    ++con;
	}

    outFile2 << "Ruta mas corta de " << inicio << " a " << destino << ": ";
    lista* pila2 = new lista();
    string current2 = destino;
	outFile2 << inicio;
    while (current2 != inicio) {
        pila2->InsertarInicio(current2);
        current2 = anterior[current2];
    }

    while (!pila2->ListaVacia()) {
        outFile2 << " -> " << pila2->primero->valor;
        pila2->BorrarInicio();
    }

    outFile2 << ". Costo Total: " << distancias[destino] << endl <<endl;

    outFile2.close();
}


void Grafos::SubMenu4(){
	cout<<"Ingrese Punto de Partida: "<<endl;
	string pp;
	cin >> pp;
	cout<<"Ingrese Punto Final: "<<endl;
	string ps;
	cin >> ps;
	if(existeNodo1(pp, ps)){
		Dijkstra(pp,ps);
    }else{
    	cout<<"Punto de Partida y punto final incorrectos."<<endl<<endl;
    	SubMenu4();
	}
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
    		Prim();
    		Menu();
    		break;
    	case '3':
    		cout<<"NO IMPLEMENTADO"<<endl;
    	//	SubMenu3();
    		Menu();
			break;
    	case '4':
    		SubMenu4();
    		Menu();
    		break;
    	case '5':
    		cout<<"NO IMPLEMENTADO"<<endl;
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
