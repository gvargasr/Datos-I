#include "listaDVertice.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


nodoVertice::nodoVertice(int costo, string destino) {
    this->costo = costo;
    this->destino = destino;
    siguiente = NULL;
}

nodoVertice::nodoVertice(int costo, string origen, string destino) {
    this->costo = costo;
    this->origen = origen;
    this->destino = destino;
    siguiente = NULL;
}

nodoVertice::nodoVertice(int costo, string destino, nodoVertice* signodoVertice) {
    this->costo = costo;
    this->destino = destino;
    siguiente = signodoVertice;
}

listaDVertice::listaDVertice() {
    primero = NULL;
}

listaDVertice::~listaDVertice() {
    pnodoVertice aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

void listaDVertice::Mostrar(){
	pnodoVertice aux = primero;
	while(aux){
		cout<<aux->origen<<aux->destino<<"-"<<aux->costo<<endl;
		aux = aux->siguiente;
	}
}

void listaDVertice::mostrarVisitadosVertices(){
		pnodoVertice temp2 = primero;
		while(temp2 != NULL){
			if(temp2->visitado == true ){
				cout<<temp2->destino<<":"<<temp2->costo<<endl;
			}
		temp2 = temp2->siguiente;
		}
		cout<<endl;		
}

void listaDVertice::MostrarFile() {
    // Open the file for writing (this will create a new file or overwrite an existing one)
    std::ofstream outFile("PRIM.txt",ios::app);

    if (outFile.is_open()) {
        pnodoVertice aux = primero;

        while (aux) {
            // Write the vertex information to the file
            outFile << aux->destino << "-" << aux->costo << std::endl;
            aux = aux->siguiente;
        }

        // Close the file
        outFile.close();
    } else {
        // Handle the case where the file couldn't be opened
        std::cerr << "Error: Unable to open the file for writing." << std::endl;
    }
}


void listaDVertice::MostrarSinCosto(){
	pnodoVertice aux = primero;
	while(aux){
		cout<<aux->destino<<endl;
		aux = aux->siguiente;
	}
}

bool listaDVertice::Buscar(int costo){
    pnodoVertice aux = primero;
    while (aux != NULL) {
        if (aux->costo == costo) {
        	cout<< "SI" << endl;
            return true;
        }
        aux = aux->siguiente;
    }
	cout<< "NO" << endl;
    return aux;
}

void listaDVertice::InsertarFinal(int costo, string destino) {
    pnodoVertice nuevo = new nodoVertice(costo, destino);

    if (ListaVacia()) {
        primero = nuevo;
    } else {
        pnodoVertice temp = primero;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void listaDVertice::InsertarOrdenadoVertice(int costo, string origen, string destino) {
    pnodoVertice nuevo = new nodoVertice(costo, origen, destino);

    if (ListaVacia() || costo <= primero->costo) {
        // If the list is empty or the new vertex has a lower or equal cost than the first one
        nuevo->siguiente = primero;
        primero = nuevo;
    } else {
        pnodoVertice temp = primero;

        while (temp->siguiente != NULL && temp->siguiente->costo < costo) {
            temp = temp->siguiente;
        }

        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
    }
}


void listaDVertice::InsertarInicio(int costo, string destino) {
    if (ListaVacia()) {
        primero = new nodoVertice(costo, destino);
    } else {
        pnodoVertice nuevo = new nodoVertice(costo, destino);
        nuevo->siguiente = primero;
        primero = nuevo;
    }
}

bool listaDVertice::ListaVacia() {
    return primero == NULL;
}

int listaDVertice::largoLista() {
    int cont = 0;
    pnodoVertice aux = primero;

    while (aux != NULL) {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}

pnodoVertice listaDVertice::GetPrimero() {
    return primero;
}

bool listaDVertice::todosVisitados(){
	pnodoVertice temp = primero;
	while(temp != NULL){
		if(temp->visitado == false){
			return false;
		}else{
			temp = temp->siguiente;
		}
	}
	return true;
}


pnodoVertice listaDVertice::BuscadorN(string destino) {
    pnodoVertice aux = primero;
    while (aux != NULL) {
        if (aux->destino == destino) {
            return aux;
        }
        aux = aux->siguiente;
    }

    return aux;
}

pnodoVertice listaDVertice::BuscadorNO(string origen) {
    pnodoVertice aux = primero;
    while (aux != NULL) {
        if (aux->origen == origen) {
            return aux;
        }
        aux = aux->siguiente;
    }

    return aux;
}

pnodoVertice listaDVertice::Buscador(int costo) {
    pnodoVertice aux = primero;
    while (aux != NULL) {
        if (aux->costo == costo) {
            return aux;
        }
        aux = aux->siguiente;
    }

    return aux;
}

bool listaDVertice::BuscadorBool(int costo) {
    pnodoVertice aux = primero;
    while (aux != NULL) {
        if (aux->costo == costo) {
            return true;
        }
        aux = aux->siguiente;
    }

    return false;
}

void listaDVertice::BorrarInicio() {
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;
    } else {
        if (primero->siguiente == NULL) {
            pnodoVertice temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pnodoVertice aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}

bool listaDVertice::BorrarNodo(int costo) {
    pnodoVertice temp = primero;
    pnodoVertice anterior = NULL;

    if (temp != NULL && temp->costo == costo) {
        primero = temp->siguiente;
        delete temp;
        return true;
    }

    while (temp != NULL && temp->costo != costo) {
        anterior = temp;
        temp = temp->siguiente;
    }

    // If the node with the desired value is found, delete it
    if (temp == NULL) {
        cout << "Nodo con costo " << costo << " no se encuentra en la lista." << endl;
        return false;
    }

    anterior->siguiente = temp->siguiente;
    delete temp;
    cout << "Nodo con costo " << costo << " eliminado de la lista." << endl;
    return true;
}


