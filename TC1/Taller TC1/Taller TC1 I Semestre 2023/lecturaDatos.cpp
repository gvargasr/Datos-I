#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	string linea;
	
	// Ejemplo 1: Usando eof
	
	ifstream archivo("archivo.txt");
	
	while (!archivo.eof()) {
		getline(archivo, linea);
		cout << linea << endl;
	}
	
	archivo.close();
	
	cout << endl << endl;
	
	// Ejemplo 2: Usando getline
	
	ifstream archivo2("archivo.txt");
	
	int cont = 0;
	
	while (getline(archivo2, linea)) {
		cout << linea << endl;
	}
	
	archivo2.close();


	return 0;
}
