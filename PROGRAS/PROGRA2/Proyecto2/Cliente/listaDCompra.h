#ifndef LISTADCOMPRA_H
#define LISTADCOMPRA_H

#include "nodoLDCompra.h"

class listaDCompra {
public:
    listaDCompra();
    ~listaDCompra();
    void InsertarInicio(int codigo, string nombre, int kcal, int precio, int cant);
    void InsertarFinal(int codigo, string nombre, int kcal, int precio, int cant);
    void InsertarPos(int codigo, string nombre, int kcal, int precio, int cant, int pos);
    bool ListaVacia();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    string Mostrar();
    int largoLista();
    pnodoComp GetPrimero();
    int buscarPos(int codigo);
    void MostrarPosicion(int pos);
    void ModPosicion(int codigo, string nombre, int kcal, int precio, int pos, int cant);
    void InsertarModInicio(int codigo, string nombre, int kcal, int precio, int cant);
    void BorrarModPosicion(int pos);
    int CalcularPrecio();

private:
    pnodoComp primero;
};

#endif /* LISTADCOMPRA_H */

