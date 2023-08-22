/* Bloque 2. Expresiones Ejercicio 8

Reciba los 2 catetos de un triangulo rectangulo e imprima la hipotenusa

Recibe las 3 notas e imprime la nota final ponderada
*/


#include<iostream>
#include<math.h>
using namespace std;

int main(){
	double x,y,f=0;
	
	cout<<"Valor x: "; 
	cin>>x;
	cout<<"Valor y: "; 
	cin>>y;

	f= sqrt(x)/(pow(y,2)-1);
	
	
	cout.precision(3);


	cout<<"\nResultado de f(x,y) es: "<<f<<endl;
	
	
	return 0;
}
