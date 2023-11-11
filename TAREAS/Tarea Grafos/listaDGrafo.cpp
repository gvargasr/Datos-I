#include "listaDGrafo.h"
#include <string>
#include <iostream>

nodoGrafo::nodoGrafo(string v, string n) {
    valor = v;
    nombre = n;
    siguiente = NULL;
    vertices = new listaDVertice();
}

nodoGrafo::nodoGrafo(string v, string n, nodoGrafo* signodoGrafo) {
    valor = v;
    nombre = n;
    siguiente = signodoGrafo;
    vertices = new listaDVertice();
}

listaDGrafo::listaDGrafo() {
    primero = NULL;
}

listaDGrafo::~listaDGrafo() {
    pnodoGrafo aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

bool listaDGrafo::isVisitado(pnodoGrafo nodo){
	if(nodo->visitado == true){
		return true;
	}else{
		return false;
	}
}
	
bool listaDGrafo::todosVisitados(){
	pnodoGrafo temp = primero;
	while(temp != NULL){
		if(temp->visitado == false){
			return false;
		}else{
			temp = temp->siguiente;
		}
	}
	return true;
}


void listaDGrafo::Mostrar(){
	pnodoGrafo aux = primero;
	while(aux){
		cout<<endl<<aux->valor<<"-"<<aux->nombre<<endl;
		aux->vertices->Mostrar();
		aux = aux->siguiente;
	}
}

void listaDGrafo::MostrarSinCosto(){
	pnodoGrafo aux = primero;
	while(aux){
		cout<<endl<<aux->valor<<"-"<<aux->nombre<<endl;
		aux->vertices->MostrarSinCosto();
		aux = aux->siguiente;
	}
}


bool listaDGrafo::Buscar(string v){
    pnodoGrafo aux = primero;
    while (aux != NULL) {
        if (aux->valor == v) {
        	cout<< "SI" << endl;
            return true;
        }
        aux = aux->siguiente;
    }
	cout<< "NO" << endl;
    return aux;
}

void listaDGrafo::InsertarFinal(string v, string n) {
    pnodoGrafo nuevo = new nodoGrafo(v, n);

    if (ListaVacia()) {
        primero = nuevo;
    } else {
        pnodoGrafo temp = primero;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void listaDGrafo::InsertarInicio(string v, string n) {
    if (ListaVacia()) {
        primero = new nodoGrafo(v, n);
    } else {
        pnodoGrafo nuevo = new nodoGrafo(v, n);
        nuevo->siguiente = primero;
        primero = nuevo;
    }
}

bool listaDGrafo::ListaVacia() {
    return primero == NULL;
}

int listaDGrafo::largoLista() {
    int cont = 0;
    pnodoGrafo aux = primero;

    while (aux != NULL) {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}

pnodoGrafo listaDGrafo::GetPrimero() {
    return primero;
}

pnodoGrafo listaDGrafo::Buscador(string v) {
    pnodoGrafo aux = primero;
    while (aux != NULL) {
        if (aux->valor == v) {
            return aux;
        }
        aux = aux->siguiente;
    }

    return aux;
}

bool listaDGrafo::BuscadorBool(string v) {
    return Buscador(v) != nullptr;
}

void listaDGrafo::BorrarInicio() {
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;
    } else {
        if (primero->siguiente == NULL) {
            pnodoGrafo temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pnodoGrafo aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}

bool listaDGrafo::BorrarNodo(string v) {
    pnodoGrafo temp = primero;
    pnodoGrafo anterior = NULL;

    if (temp != NULL && temp->valor == v) {
        primero = temp->siguiente;
        delete temp;
        return true;
    }

    while (temp != NULL && temp->valor != v) {
        anterior = temp;
        temp = temp->siguiente;
    }

    // If the node with the desired value is found, delete it
    if (temp == NULL) {
        cout << "El valor " << v << " no se encuentra en la lista." << endl;
        return false;
    }

    anterior->siguiente = temp->siguiente;
    delete temp;
    cout << "Nodo con valor " << v << " eliminado de la lista." << endl;
    return true;
}

///*
//int main()
//{
//   listaDGrafo Lista;
//
//   
//   Lista.InsertarInicio("X", "A");    // 2 20 10 11
///*   Lista.InsertarInicio(2);
//   Lista.InsertarFinal(10);
//   Lista.InsertarFinal(11);
//   Lista.InsertarFinal(110);
//   Lista.InsertarFinal(116);
//   Lista.InsertarPos(5, 4);*/
//   Lista.Buscar("X");
//   Lista.Buscar("M");
// /*  Lista.InsertarPos(6, 4);
//   Lista.InsertarInicio(30);
//   Lista.InsertarInicio(1);   
//   Lista.InsertarFinal(5);
//   Lista.InsertarPos(1, 3);*/
//  Lista.Mostrar();
//  /* Lista.BorrarInicio();
//   Lista.Mostrar();
//   Lista.BorrarFinal();
//   Lista.Mostrar();*/
//   /*Lista.InsertarInicio(2);
//   Lista.Mostrar();*/
// //  Lista.BorrarPosicion(5);
//   //Lista.Mostrar();
//     cout << Lista.largoLista();
//    Lista.~listaDGrafo();
//
//   
//  
//  
////   cin.get();
//   return 0;
//}*/
