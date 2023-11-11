#ifndef LISTADVERTICE_H
#define LISTADVERTICE_H

#include <string>
using namespace std;

class nodoVertice {
public:
    nodoVertice(int costo, string destino);
    nodoVertice(int costo, string destino, nodoVertice* signodoVertice);

    string destino = "";
    int costo = 0;
    bool visitado = false;
    nodoVertice* siguiente;

    friend class listaDVertice;
};

typedef nodoVertice* pnodoVertice;

class listaDVertice {
public:
    listaDVertice();
    ~listaDVertice();
    void Mostrar();
    void MostrarSinCosto();
    void InsertarFinal(int costo, string destino);
    void InsertarInicio(int costo, string destino);
    bool ListaVacia();
    int largoLista();
    pnodoVertice GetPrimero();
    bool BuscadorBool(int costo);
    pnodoVertice Buscador(int costo);
    void BorrarInicio();
    bool BorrarNodo(int costo);
	bool Buscar(int costo);
	pnodoVertice BuscadorN(string destino);
	bool todosVisitados();
	


//private:
    pnodoVertice primero;
};

#endif /* LISTADVERTICE_H */

