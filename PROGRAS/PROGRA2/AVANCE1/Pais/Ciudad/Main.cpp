#include <stdlib.h>
#include "AVLCiudad.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    AVLCiudad B;
    B.InsertaNodoCiudad(6, "a");
    B.InsertaNodoCiudad(2, "b");
    B.InsertaNodoCiudad(7,"c");
    B.InsertaNodoCiudad(9, "d");
    B.InsertaNodoCiudad(8,"e");
    B.InsertaNodoCiudad(4,"f");
    B.InsertaNodoCiudad(5,"g");
    B.InsertaNodoCiudad(1,"h");
    B.InsertaNodoCiudad(3,"i");
    B.InsertaNodoCiudad(3,"m");
    B.InsertaNodoCiudad(10,"j");

    cout<<endl<<"In"<<endl;
    B.InordenI();
    cout<<endl<<"Pre"<<endl;
    B.PreordenI();
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

