#ifndef NODOLDCOMPRA_H
#define NODOLDCOMPRA_H

#include <string>
using namespace std;

class nodoLDCompra {
public:
    nodoLDCompra();
    nodoLDCompra(int codigo, string nombre, int cal, int price, int cant);
    nodoLDCompra(int codigo, string nombre, int kcal, int precio, int cant, nodoLDCompra* signodo);

    int cod, kcal, precio, cantidad;
    string nomProd;
    nodoLDCompra* siguiente;
    nodoLDCompra* anterior;

    friend class listaDProducto;
};

typedef nodoLDCompra* pnodoComp;

#endif /* NODOLDCOMPRA_H */

