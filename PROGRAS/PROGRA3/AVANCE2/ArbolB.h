// ArbolB.h
//#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Pagina_Cliente {
	public:
		int claves [5];
		string nombre [5];
		int compras[5]; 
		Pagina_Cliente* Ramas[5];
		Pagina_Cliente* rama1; 
		Pagina_Cliente* rama2; 
		Pagina_Cliente* rama3; 
		Pagina_Cliente* rama4; 
		Pagina_Cliente* rama5;
		int Cuenta;
		
	
    Pagina_Cliente() : Cuenta(0) {
        for (int i = 0; i < 5; i++) {
            claves[i] = 0;
			compras[i] = 0; 
            nombre[i] = "";
        }
        rama1 = rama2 = rama3 = rama4 = rama5 = NULL;
        Ramas[0] = rama1;
        Ramas[1] = rama2;
        Ramas[2] = rama3;
        Ramas[3] = rama4;
        Ramas[4] = rama5;
    }

    // Constructor con parámetros
    Pagina_Cliente(int pCedula, string pNombre) : Pagina_Cliente() {
        claves[1] = pCedula;
        nombre[1] = pNombre;
        compras[1] = 0; 
        Cuenta = 1;
    }
    
    int obtenerCuenta() const {
        return Cuenta;
    }

    ~Pagina_Cliente() {
    	        for (int i = 0; i < 5; i++) {
            claves[i] = 0; 
            nombre[i] = "";
            compras[i] = 0; 
        }
        rama1 = rama2 = rama3 = rama4 = rama5 = NULL;
        Ramas[0] = rama1;
        Ramas[1] = rama2;
        Ramas[2] = rama3;
        Ramas[3] = rama4;
        Ramas[4] = rama5; 
    }
		
		
};

typedef Pagina_Cliente* puntero_Cliente;

class ArbolB {
public:
    Pagina_Cliente* raiz;
    ArbolB();
	void Empujar(int C1, string& nombre, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& Xr);
    void InsertarClave(int C1, string nombre, Pagina_Cliente*& raiz);
    bool BuscarNodo(int Clave, Pagina_Cliente* P, bool& Encontrado, int& K);
    void ImprimirArbol(Pagina_Cliente* raiz);
    void MeterHoja(int X, string& nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K);
    void DividirNodo(int X, string& nombre, Pagina_Cliente* Xder, Pagina_Cliente*& P, int& K, int& Mda, Pagina_Cliente*& Mder);
    bool Search(int clave, Pagina_Cliente* raiz);
	void Modificar(int clave, string nombre, Pagina_Cliente*& raiz);
	void inOrderTraversal(Pagina_Cliente* raiz, ofstream& outFile);
	void saveToFile(const string& filename);
	string SearchNodo(int clave, Pagina_Cliente* raiz);
	string SearchContador(int clave, Pagina_Cliente* raiz);
    bool CompraDeCliente(int clave, Pagina_Cliente* raiz);
    bool SearchC(int clave, Pagina_Cliente* raiz);
    
    void Eliminar(int C1,Pagina_Cliente*& raiz);
    void EliminarRegistro(int C1, Pagina_Cliente*& raiz, bool Encontrado);
    void Quitar(Pagina_Cliente*& P,int K);
    void Sucesor(Pagina_Cliente* P,int K);
	void Restablecer (Pagina_Cliente*& P,int K);
	void MoverDerecha(Pagina_Cliente*& P,int K);
	void MoverIzquierda(Pagina_Cliente*& P,int K);
	void Combina(Pagina_Cliente*& P,int K);



    

    
    friend Pagina_Cliente;
};

