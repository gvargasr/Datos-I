#ifndef AAMENU_H
#define AAMENU_H

#include <iostream>
#include <fstream>
#include "AVLProducto.h"

class NodoM {
public:
    int codMenu;
    int nivel;
    int contador;
    NodoM *Hizq;
    NodoM *Hder;
    std::string nombreMenu;
    AVLProducto listaProducto;

    friend class ArbolA;
};

typedef NodoM* NodoMPtr;

class AAMenu {
public:
    NodoMPtr Raiz;
    NodoMPtr TNULL;

    AAMenu();

    void BuscarNodoMenu(int numbusqueda);
    NodoMPtr BuscarNodoMenu1(int numbusqueda);
    NodoMPtr BuscarNodoMenu2(int numbusqueda);
    void insertar(int codMenunuevo, std::string nombrenuevo);
    void insertarBus(int codMenunuevo, std::string nombrenuevo);
    void generateReport(NodoMPtr NodoMenu, std::string nomRest);
    NodoMPtr findMaxContador(NodoMPtr root);
    NodoMPtr BusquedaM(int numbuscado);

//private:
    void IniciarNodoNULL(NodoMPtr NodoMenu);
    NodoMPtr Busqueda(NodoMPtr NodoMenu, int numbuscado);
    void Giro(NodoMPtr NodoMenu, NodoMPtr x, NodoMPtr z);
    void Reparto(NodoMPtr NodoMenu, NodoMPtr Der, NodoMPtr Izq);
    void preOrden(NodoMPtr NodoMenu, std::ofstream& file);
};

#endif // AAMENU_H
