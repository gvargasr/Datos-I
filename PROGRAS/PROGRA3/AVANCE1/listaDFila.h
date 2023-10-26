#ifndef LISTADFILA_H
#define LISTADFILA_H

#include <string>
#include "listaDCompra.h"
using namespace std;

class nodoFila {
public:
    nodoFila(int v, string n);
    nodoFila(int v, string n, nodoFila* signodoFila);

    string nombre = "";
    int valor = 0;
    nodoFila* siguiente;
    listaDCompra* listaComp = NULL;

    friend class listaDFila;
};

typedef nodoFila* pnodoFila;

class listaDFila {
public:
    listaDFila();
    ~listaDFila();
    
    void InsertarFinal(int v, string n);
    void InsertarInicio(int v, string n);
    bool ListaVacia();
    int largoLista();
    pnodoFila GetPrimero();
    bool BuscadorBool(int ced);
    pnodoFila Buscador(int ced);
    void Comprar(int ced, string nom, int codigo, string nombre, int kcal, int precio, int cantidad);
    void BorrarInicio();
    int ReturnCedula(int ced);

private:
    pnodoFila primero;
};

#endif /* LISTADFILA_H */

