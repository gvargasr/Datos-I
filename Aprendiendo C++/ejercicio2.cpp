/* Ejercicio 2. Escribe un programa que lea de la entrada estandar el predio de un producto
y muestre en la salida estandar el precio del producto al aplicarle el IVA */

#include <iostream>

using namespace std;

int main(){
	float precio=0;

	cout<<"Ingrese el precio del producto: ";
	cin>>precio;
	precio=precio*1.13;
	
	cout<<"\nEl precio mas IVA es: "<<precio<<endl;
	
	
	return 0;
}
