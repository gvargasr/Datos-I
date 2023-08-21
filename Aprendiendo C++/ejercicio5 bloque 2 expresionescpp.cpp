/* Bloque 2. Expresiones Ejercicio 5

escriba un fragmento de programa que intercambie los calores de dos variables

*/


#include<iostream>

using namespace std;

int main(){
	float a,b,temp;
	
	cout<<"Digite el valor de a: "; 
	cin>>a;
	cout<<"Digite el valor de b: "; 
	cin>>b;
	
	temp = a;
	a=b;
	b=temp;

	cout<<"\nLos valores son:\na= "<<a<<"\nb= "<<b<<endl;
	
	
	return 0;
}
