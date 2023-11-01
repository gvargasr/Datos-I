#include "listaDFila.h"
#include <iostream>

nodoFila::nodoFila(int v, string n) {
    valor = v;
    nombre = n;
    siguiente = NULL;
    listaComp = new listaDCompra;
}

nodoFila::nodoFila(int v, string n, nodoFila* signodoFila) {
    valor = v;
    nombre = n;
    siguiente = signodoFila;
    listaComp = new listaDCompra;
}

listaDFila::listaDFila() {
    primero = NULL;
}

listaDFila::~listaDFila() {
    pnodoFila aux;

    while (primero) {
        aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
    primero = NULL;
}

void listaDFila::InsertarFinal(int v, string n) {
    pnodoFila nuevo = new nodoFila(v, n);

    if (ListaVacia()) {
        primero = nuevo;
    } else {
        pnodoFila temp = primero;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void listaDFila::InsertarInicio(int v, string n) {
    if (ListaVacia()) {
        primero = new nodoFila(v, n);
    } else {
        pnodoFila nuevo = new nodoFila(v, n);
        nuevo->siguiente = primero;
        primero = nuevo;
    }
}

bool listaDFila::ListaVacia() {
    return primero == NULL;
}

int listaDFila::largoLista() {
    int cont = 0;
    pnodoFila aux = primero;

    while (aux != NULL) {
        aux = aux->siguiente;
        cont++;
    }

    return cont;
}

pnodoFila listaDFila::GetPrimero() {
    return primero;
}

pnodoFila listaDFila::Buscador(int ced) {
    pnodoFila aux = primero;
    while (aux != NULL) {
        if (aux->valor == ced) {
            return aux;
        }
        aux = aux->siguiente;
    }

    return aux;
}

bool listaDFila::BuscadorBool(int ced) {
    return Buscador(ced) != nullptr;
}

void listaDFila::Comprar(int ced, string nom, int codigo, string nombre, int kcal, int precio, int cantidad) {
    if (BuscadorBool(ced)) {
        pnodoFila aux = Buscador(ced);
        aux->listaComp->InsertarFinal(codigo, nombre, kcal, precio, cantidad);
    } else {
        InsertarFinal(ced, nom);
        pnodoFila aux = Buscador(ced);
        aux->listaComp->InsertarFinal(codigo, nombre, kcal, precio, cantidad);
    }
}

int listaDFila::ReturnCedula(int ced) {
    if (BuscadorBool(ced)) {
        pnodoFila aux = Buscador(ced);
        return aux->valor;
    } else {
        return -1;
    }
}

void listaDFila::BorrarInicio() {
    if (ListaVacia()) {
        cout << "No hay elementos en la lista:" << endl;
    } else {
        if (primero->siguiente == NULL) {
            pnodoFila temp = primero;
            primero = NULL;
            delete temp;
        } else {
            pnodoFila aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
}


bool listaDFila::BorrarNodo(int valor) {
    pnodoFila temp = primero;
    pnodoFila anterior = NULL;

    if (temp != NULL && temp->valor == valor) {
        primero = temp->siguiente;
        delete temp;
        return true;
    }

    while (temp != NULL && temp->valor != valor) {
        anterior = temp;
        temp = temp->siguiente;
    }

    // If the node with the desired value is found, delete it
    if (temp == NULL) {
        cout << "El valor " << valor << " no se encuentra en la lista." << endl;
        return false;
    }

    anterior->siguiente = temp->siguiente;
    delete temp;
    cout << "Nodo con valor " << valor << " eliminado de la lista." << endl;
    return true;
}

