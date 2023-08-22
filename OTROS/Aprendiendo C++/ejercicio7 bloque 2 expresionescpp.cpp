/* Bloque 2. Expresiones Ejercicio 7

Practicas 30%
teorico 60%
participacion 10%

Recibe las 3 notas e imprime la nota final ponderada
*/


#include<iostream>

using namespace std;

int main(){
	float practica,teorica,participacion,notaFinal=0;
	
	cout<<"Digite la nota de practica: "; 
	cin>>practica;
	cout<<"Digite la nota teorica: "; 
	cin>>teorica;
	cout<<"Digite la nota de participacion: "; 
	cin>>participacion;
	
	practica *= 0.3;  //practica=practica*0.3;
	teorica *= 0.6;   //teorica=teorica*0.6;
	participacion *= 0.1; //participacion=participacion*0.1;
	
	
	cout.precision(3);
	notaFinal = practica+teorica+participacion;


	cout<<"\nLa nota final ponderada es: "<<notaFinal<<endl;
	
	
	return 0;
}
