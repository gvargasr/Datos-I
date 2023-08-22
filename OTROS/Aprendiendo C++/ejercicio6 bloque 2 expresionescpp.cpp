/* Bloque 2. Expresiones Ejercicio 6

Promedio de 4 notas
*/


#include<iostream>

using namespace std;

int main(){
	float a,b,c,d,promedio;
	
	cout<<"Ingrese nota de Estudiante 1: "; 
	cin>>a;
	cout<<"Ingrese nota de Estudiante 2: "; 
	cin>>b;
	cout<<"Ingrese nota de Estudiante 3: "; 
	cin>>c;
	cout<<"Ingrese nota de Estudiante 4: "; 
	cin>>d;
	
	cout.precision(3);
	promedio = (a+b+c+d)/4;


	cout<<"\nEl promedio de notas es: "<<promedio<<endl;
	
	
	return 0;
}
