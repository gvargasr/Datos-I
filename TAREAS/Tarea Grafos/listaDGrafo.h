#ifndef LISTADGRAFO_H
#define LISTADGRAFO_H

#include "listaDvertice.cpp"
#include <string>
using namespace std;

class nodoGrafo {
public:
    nodoGrafo(string v, string n);
    nodoGrafo(string v, string n, nodoGrafo* signodoGrafo);

    string nombre = "";
    string valor = "";
    bool visitado = false;
    nodoGrafo* siguiente;
	listaDVertice* vertices;
    friend class listaDGrafo;
};

typedef nodoGrafo* pnodoGrafo;

class listaDGrafo {
public:
    listaDGrafo();
    ~listaDGrafo();
    void Mostrar();
    void MostrarSinCosto();
    void InsertarFinal(string v, string n);
    void InsertarInicio(string v, string n);
    bool ListaVacia();
    int largoLista();
    pnodoGrafo GetPrimero();
	bool BuscadorBool(string v);
    pnodoGrafo Buscador(string v);
    void BorrarInicio();
    bool BorrarNodo(string v);
	bool Buscar(string v);
	bool isVisitado(pnodoGrafo nodo);
	bool todosVisitados();
	void MostrarFile(int costo);


//private:
    pnodoGrafo primero;
};

#endif /* LISTADGRAFO_H */

