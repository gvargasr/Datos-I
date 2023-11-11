#include "listaDVertice.h"
#include <string>
#include <iostream>

nodoVertice::nodoVertice(int costo, string destino) {
    this->costo = costo;
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
		cout<<aux->destino<<"-"<<aux->costo<<endl;
		aux = aux->siguiente;
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

//
//int main()
//{
//   listaDVertice Lista;
//
//   
//   Lista.InsertarInicio(6, "A");    // 2 20 10 11
///*   Lista.InsertarInicio(2);
//   Lista.InsertarFinal(10);
//   Lista.InsertarFinal(11);
//   Lista.InsertarFinal(110);
//   Lista.InsertarFinal(116);
//   Lista.InsertarPos(5, 4);*/
//   Lista.Buscar(6);
//   Lista.Buscar(8);
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
//    Lista.~listaDVertice();
//
//   
//  
//  
////   cin.get();
//   return 0;
//}
