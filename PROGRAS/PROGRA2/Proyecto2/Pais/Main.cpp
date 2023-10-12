#include <stdlib.h>
#include "BinarioPais.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    BinarioPais B;
    B.InsertaNodoPais(6, "a");
    B.InsertaNodoPais(2, "b");
    B.InsertaNodoPais(7,"c");
    B.InsertaNodoPais(9, "d");
    B.InsertaNodoPais(8,"e");
    B.InsertaNodoPais(4,"f");
    B.InsertaNodoPais(5,"g");
    B.InsertaNodoPais(1,"h");
    B.InsertaNodoPais(3,"i");
    B.InsertaNodoPais(10,"j");
    AVLCiudad arbolCiudad = B.raiz->ArbolCiudad;
    B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,241,"hola ");
        B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,445,"mi");

    B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,687,"nombre");

    B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,7,"es");
    B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,687,"Lizza");
    B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,662,"Gustavo");
    B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,32,"Vargas");
    B.raiz->ArbolCiudad.InsertarBalanceadoCiudad(B.raiz->ArbolCiudad.raiz,B.raiz->ArbolCiudad.Hh,662,"Guapa");
	B.raiz->ArbolCiudad.InordenI();
	cout<<endl;
//	B.BuscarPais(B.raiz, 66);
    //B.raiz->ArbolCiudad->InsertarBalanceadoCiudad(B.raiz->ArbolCiudad->raiz,B.raiz->ArbolCiudad->Hh,666,"hola mundo");

/*    cout<<endl<<"In"<<endl;
    B.InordenI();
    cout<<endl<<"Pre"<<endl;
    B.PreordenI();*/
//    Binario B2;
/*    B2.InsertaNodo(6);
    B2.InsertaNodo(2);
    B2.InsertaNodo(7);
    B2.InsertaNodo(9);
    B2.InsertaNodo(8);
    B2.InsertaNodo(4);
    B2.InsertaNodo(5);
    B2.InsertaNodo(1);
    B2.InsertaNodo(3);
    B2.InsertaNodo(10);

    cout<<endl<<"Post"<<endl;
    B2.PostordenI();

    cout<<endl<<"B3 IN"<<endl;
    Binario B3;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 50);
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 17);
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 76);
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 12);
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 23);
        B3.PreordenI();
		cout<<endl;
   B3.InsertarBalanceado(B3.raiz, B3.Hh, 92);
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 14);
    	B3.PreordenI();
		cout<<endl;
   B3.InsertarBalanceado(B3.raiz, B3.Hh, 30);
        B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 40);
        	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 55);
        	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceado(B3.raiz, B3.Hh, 60);
    	B3.PreordenI();
		cout<<endl;
	//	B3.InordenI();
	//	cout<<endl;
	//	B3.PostordenR(B3.raiz);*/
 //   cin.get();

    return (EXIT_SUCCESS);
}

