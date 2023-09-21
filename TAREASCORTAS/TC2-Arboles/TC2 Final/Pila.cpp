#include <iostream>
#include <string>
#include "ArbolBinario.cpp"

class NodoPila {
public:
    pnodoA arbol;
    NodoPila* siguiente;

    NodoPila(pnodoA a){
    	arbol = a; 
    	siguiente = NULL;
	}
};

class Pila {
public:
    Pila(){
    	cima = NULL; 
	}
    ~Pila() { VaciarPila(); }

    void Push(pnodoA arbol) {
        NodoPila* nuevoNodo = new NodoPila(arbol);
        nuevoNodo->siguiente = cima;
        cima = nuevoNodo;
    }

    void Pop() {
        if (cima != NULL) {
            NodoPila* aux = cima;
            cima = cima->siguiente;
            delete aux;
        }
    }

    pnodoA Top() {
    	if(cima !=NULL)
    	return cima->arbol;
    	else{
    		return NULL;
		}
    }

    bool EstaVacia() {
        return (cima == NULL);
    }

    void VaciarPila() {
        while (!EstaVacia()) {
            Pop();
        }
    }

private:
    NodoPila* cima;
};
/*
int main() {
    Pila pila;

    // Crear algunos nodos de árbol y apilarlos
    pnodoA arbol1 = new NodoArbol("A");
    pnodoA arbol2 = new NodoArbol("B");
    pnodoA arbol3 = new NodoArbol("C");
    pnodoA arbol4 = new NodoArbol("D");

    pila.Push(arbol1);
    pila.Push(arbol2);
    pila.Push(arbol3);
	pila.Push(arbol4);
	ArbolBinario Arbol;
	Arbol.InsertarHijos("F",arbol1,arbol2);
	Arbol.InsertarHijos("L",Arbol.raiz, arbol3);
	Arbol.RecorridoPreorden(Arbol.raiz);
	cout <<"HOLA"<<endl;
	pila.Push(Arbol.raiz);
    // Acceder a la cima de la pila
    pnodoA cimaDePila = pila.Top();
    if (cimaDePila != NULL) {
        cout << "Cima de la pila: " << cimaDePila->valor << endl;
    }

    // Desapilar un elemento
    pila.Pop();
	cimaDePila = pila.Top();
    if (cimaDePila != NULL) {
        cout << "Cima de la pila: " << cimaDePila->valor << endl;
    }
    // Comprobar si la pila está vacía
    if (pila.EstaVacia()) {
        std::cout << "La pila está vacía." << endl;
    }

    // Liberar memoria de los nodos de árbol
    delete arbol1;
    delete arbol2;
    delete arbol3;
}*/
