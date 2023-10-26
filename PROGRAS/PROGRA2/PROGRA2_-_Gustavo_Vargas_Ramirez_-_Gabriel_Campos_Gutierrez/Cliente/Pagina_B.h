#include <iostream>
#include <string>

using namespace std;

class Pagina_Cliente {
	private:
		int cedula [4];
		string nombre [4];
		Pagina_Cliente* rama1; 
		Pagina_Cliente* rama2; 
		Pagina_Cliente* rama3; 
		Pagina_Cliente* rama4; 
		Pagina_Cliente* rama5;
		
	public:
		Pagina_Cliente ();
		Pagina_Cliente (int pCedula, string pNombre );
		
		
};

typedef Pagina_Cliente* puntero_Cliente;
