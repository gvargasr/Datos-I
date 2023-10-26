#include <cstddef>
#include "NodoBinarioPais.h"
#include "PilaPais.h"
#include "BinarioPais.h"
#include <fstream>
#include <iostream>
#include "BinarioPais.h"

using namespace std;


NodoBinarioPais* BinarioPais::MinValorNodo(NodoBinarioPais* nodoB) {
    NodoBinarioPais* actual = nodoB;
    while (actual->Hizq != nullptr) {
        actual = actual->Hizq;
    }

    return actual;
}


NodoBinarioPais* BinarioPais::BuscarPais(NodoBinarioPais* nodoB, int num) {
    if (nodoB == NULL) {
//        cout << "El pais: " << num << " no se encuentra" << endl;
        return NULL; // El país no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return BuscarPais(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return BuscarPais(nodoB->Hder, num);
    } else {
        // El país se encuentra en el nodo actual
//        cout << "El pais: " << num << " fue encontrado." << endl;
        return nodoB;
    }
}


void NodoBinarioPais::InsertaBinarioPais(int num, string pais)
{
	if(num == valor){
		cout<<"Codigo repetido "<<num<<" no se agrego a la lista."<<endl;
		return;
	}
    if(num < valor){
        if(Hizq == NULL){
            Hizq = new NodoBinarioPais(num, pais);
            cout<<"Pais "<<num<<":"<<pais<<" fue agregado a la lista."<<endl;
        }else{
            Hizq->InsertaBinarioPais(num, pais);
        }
    }else{
        if(Hder == NULL){
            Hder = new NodoBinarioPais(num, pais);
            cout<<"Pais "<<num<<":"<<pais<<" fue agregado a la lista."<<endl;
        }else{
            Hder->InsertaBinarioPais(num, pais);
        }
    }
}
