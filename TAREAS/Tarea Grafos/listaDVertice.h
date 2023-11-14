#ifndef LISTADVERTICE_H
#define LISTADVERTICE_H

#include <string>
using namespace std;

class nodoVertice {
public:
    nodoVertice(int costo, string destino);
    nodoVertice(int costo, string origen, string destino);
    nodoVertice(int costo, string destino, nodoVertice* signodoVertice);
	string origen = "";
    string destino = "";
    int cont = 0;
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
    void InsertarOrdenadoVertice(int costo, string origen, string destino);
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
	pnodoVertice BuscadorNO(string origen);
	bool todosVisitados();
	void MostrarFile();
	void MostrarKruskal();
	void mostrarVisitadosVertices();

	


//private:
    pnodoVertice primero;
};

#endif /* LISTADVERTICE_H */

