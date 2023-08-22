/* Bloque 2. Expresiones Ejercicio 8

Reciba los 2 catetos de un triangulo rectangulo e imprima la hipotenusa

Recibe las 3 notas e imprime la nota final ponderada
*/


#include<iostream>
#include<cmath>
using namespace std;

int main(){
	double cateto1,cateto2,hipotenusa=0;
	
	cout<<"Cateto 1: "; 
	cin>>cateto1;
	cout<<"Cateto 2: "; 
	cin>>cateto2;

	hipotenusa= sqrt(cateto1*cateto1 + cateto2*cateto2);
	
	
	cout.precision(3);


	cout<<"\nLa hipotenusa es: "<<hipotenusa<<endl;
	
	
	return 0;
}
