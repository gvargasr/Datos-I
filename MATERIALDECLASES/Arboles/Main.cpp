#include <stdlib.h>
#include "Binario.h"
#include <iostream>

using namespace std;

int main(){
    Binario B;
    B.InsertaNodo(6);
    B.InsertaNodo(2);
    B.InsertaNodo(7);
    B.InsertaNodo(9);
    B.InsertaNodo(8);
    B.InsertaNodo(4);
    B.InsertaNodo(5);
    B.InsertaNodo(1);
    B.InsertaNodo(3);
    B.InsertaNodo(10);\

    cout<<endl<<"In"<<endl;
    B.InordenI();
    cout<<endl<<"Pre"<<endl;
    B.PreordenI();
    Binario B2;
    B2.InsertaNodo(6);
    B2.InsertaNodo(2);
    B2.InsertaNodo(7);
    B2.InsertaNodo(9);
    B2.InsertaNodo(8);
    B2.InsertaNodo(4);
    B2.InsertaNodo(5);
    B2.InsertaNodo(1);
    B2.InsertaNodo(3);
    B2.InsertaNodo(10);\

    cout<<endl<<"Post"<<endl;
    B2.PostordenI();

    Binario B3;
    B3.InsertarBalanceado(B.raiz, false, 5);
    B3.InsertarBalanceado(B.raiz, B.Hh, 4);
   // B.InsertarBalanceado(B.raiz, false, 6);

    
    cin.get();

    return (EXIT_SUCCESS);
}

