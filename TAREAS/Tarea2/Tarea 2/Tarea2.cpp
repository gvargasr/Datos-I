#include <iostream>
#include "listaSimple.cpp"

void contarPares(int num){
	
	if (num == 0)
		cout <<1;
	else
	{
		while(num!=0)
		{
			int temp =num%10;
			InsertarInicio(temp);
			num=num/10;
		}
		int pares=0;
		pnodo aux=primero;
		while(aux !=NULL)
		{
			if(aux->valor%2 ==0)
			{
				pares++;
				aux=aux->siguiente;
			}
			else
			aux=aux->siguiente;
		}
		cout<<pares<<endl;
	}
}

void promedio(int num){
	
	if(num==0)
		cout<<0<<endl;
	else
	{
		while(num!=0)
		{
			int temp =num%10;
			InsertarInicio(temp);
			num=num/10;
		}
		pnodo aux=primero;
		int cant = 0;
		float suma =0;
		while(aux!=NULL)
		{
			suma=suma+aux->valor;
			cant=cant+1;
			aux=aux->siguiente;
		}
		suma=suma/cant;
		cout<<suma<<endl;
	}
}
