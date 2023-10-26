#include "nodoLDCompra.h"

nodoLDCompra::nodoLDCompra() {
    cod = -1;
    nomProd = "";
    kcal = -1;
    precio = -1;
    cantidad = -1;
    siguiente = NULL;
    anterior = NULL;
}

nodoLDCompra::nodoLDCompra(int codigo, string nombre, int cal, int price, int cant) {
    cod = codigo;
    nomProd = nombre;
    kcal = cal;
    precio = price;
    cantidad = cant;
    siguiente = NULL;
    anterior = NULL;
}

nodoLDCompra::nodoLDCompra(int codigo, string nombre, int kcal, int price, int cant, nodoLDCompra* signodo) {
    cod = codigo;
    nomProd = nombre;
    kcal = kcal;
    precio = price;
    cantidad = cant;
    siguiente = signodo;
}

// Implement any other member functions if needed

