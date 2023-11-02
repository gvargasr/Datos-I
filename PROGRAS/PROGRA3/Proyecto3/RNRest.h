#ifndef RNREST_H
#define RNREST_H

#include <iostream>
#include <string>
#include <fstream>
#include "AAMenu.h"

class Nodo {
public:
    int codRest;
    Nodo* padre;
    Nodo* Hizq;
    Nodo* Hder;
    int color;
    int contador;
    std::string nombreRest;
    AAMenu listaMenu;

    friend class ArbolRN;
};

typedef Nodo* NodoPtr;

class RNRest {
public:
    RNRest();
    void initializeNULLNode(NodoPtr nodo, NodoPtr padre);
    void insertarBalanceado(NodoPtr NodoEva);
    NodoPtr Busqueda(NodoPtr nodo, int numbuscado);
    bool BusquedaBool(NodoPtr nodo, int numbuscado);
    void rbModificar(NodoPtr uRaiz, NodoPtr vValor);
    void MostrarRN1(NodoPtr raiz, std::string indent, bool ultimo);
    void MostrarRN();
    Nodo* FindNodeWithHighestContador(NodoPtr root);
    void PreOrderTraversal(NodoPtr raiz, std::ofstream& archivo_salida);
    void MostrarRN3(string nombre);
    void MostrarRN2(NodoPtr raiz, std::string indent, bool ultimo, std::string nombre);
    void RotacionIzquierda(NodoPtr nodo);
    void RotacionDerecha(NodoPtr nodo);
    void insertar(int codRestnuevo, std::string nombrenuevo);
    void insertarBus(int codRestnuevo, std::string nombrenuevo);
    NodoPtr getRaiz();
    NodoPtr BusquedaMRest(int numbuscado);
    bool BusquedaB(int numbuscado);
    void ModificarNodo(int numbusqueda, std::string nuevonom);
    Nodo* BuscarNodo(int numbusqueda);
    Nodo* BuscarNodoBus(int numbusqueda);
    void ArregloBorrar(NodoPtr Nodo);
    void AsistenteBorrarNodo(NodoPtr Nodo, int key);
    void borrarNodo(int codBorrar);
	NodoPtr minimo(NodoPtr nodo);

//private:
    NodoPtr Raiz;
    NodoPtr TNULL;
};

#endif // RNREST_H

