#ifndef CARGARARCHIVO_H
#define CARGARARCHIVO_H


#include "BinarioPais.h"
#include "ArbolB.h"
#include "listaDFila.h"



class cargarArchivo {
public:
    cargarArchivo();
    ~cargarArchivo();
    void Menu();
    void cargaInicial();
    void buscarMenuMasBuscado();
    void MostrarTodo();
 	void SubMenu1();
	void SubMenu2();
	void SubMenu21();
	void SubMenu22();
	void SubMenu23();
	void SubMenu24();
	void SubMenu25();
	void SubMenu26();
	void SubMenu3();
	void SubMenu31();
	void SubMenu32();
	void SubMenu33();
	void SubMenu34();
	void SubMenu35();
	void SubMenu36();
	void SubMenu4();
	void SubMenu41();
    void SubMenu42();
    void SubMenu43();
    void SubMenu44();
    void SubMenu45();
    void SubMenu46();
	void SubMenu5();
	void SubMenu51();
    void SubMenu52();
    void SubMenu53();
    void SubMenu54();
    void SubMenu55();
    void SubMenu56();
	void SubMenu57();
	void SubMenu571(pnodoComp Prod);
	void SubMenu6();
	void SubMenu61();
    void SubMenu62();
    void SubMenu63();
    void SubMenu64();
    void SubMenu65();
    void SubMenu66();
    void SubMenu67();
    void SubMenu68();
	void SubMenu7();
	void SubMenu71();
	void SubMenu72();
	void SubMenu73();
	void SubMenu74();
	void SubMenu75();
	void SubMenu76();
	void SubMenu77();
	void SubMenu8();
	void SubMenu81(int cedula);
	void SubMenu82(int cedula);
	
//	private:
    BinarioPais *listaPais;
    ArbolB* listaCliente;
	ArbolB* listaAdmin;
    listaDFila *listaFila;
    RNRest *RestMasBuscados;
    AAMenu *MenuMasBuscados;
    pnodoFila FacturaGrande;
    pnodoFila FacturaPequena;
	ArbolB* listaPaisEliminado;
	ArbolB* listaCiudadEliminada;
	ArbolB* listaRestauranteEliminado;
	ArbolB* listaMenuEliminado;
	ArbolB* listaProductoEliminado;
};



#endif // CARGARARCHIVO_H

