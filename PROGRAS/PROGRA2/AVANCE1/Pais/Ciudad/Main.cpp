#include <stdlib.h>
#include "AVLCiudad.cpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
 /*   AVLCiudad B;
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

    cout<<endl<<"Pre"<<endl;
    B.PreordenI();
    cout<<endl<<"In"<<endl;
    B.InordenI();
*/
  /*  cout<<endl<<"Post"<<endl;
    B.PostordenI();*/

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
    */
    AVLCiudad B3;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 50, "a");
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 17, "b");
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 76, "c");
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 12, "d");
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 23, "e");
        B3.PreordenI();
		cout<<endl;
   B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 92, "f");
    	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 14, "g");
    	B3.PreordenI();
		cout<<endl;
   B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 30, "h");
        B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 40, "i");
        	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 55, "j");
        	B3.PreordenI();
		cout<<endl;
    B3.InsertarBalanceadoCiudad(B3.raiz, B3.Hh, 60, "k");
    	B3.PreordenI();
		cout<<endl;
	//	B3.InordenI();
	//	cout<<endl;
	//	B3.PostordenR(B3.raiz);
 //   cin.get();

    return (EXIT_SUCCESS);
}

