#include <iostream>
#include "AVLCiudad.h"

#include <string>

#include <fstream>


using namespace std;


NodoBinarioCiudad* AVLCiudad::BuscarCiudad(NodoBinarioCiudad* nodoB, int num) {
    if (nodoB == NULL) {
//        cout << "La ciudad: " << num << " no se encuentra" << endl;
        return NULL; // Ciudad no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return BuscarCiudad(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return BuscarCiudad(nodoB->Hder, num);
    } else {
        // Ciudad se encuentra en el nodo actual
//        cout << "La ciudad: " << num << " fue encontrada." << endl;
        return nodoB;
    }
}

bool AVLCiudad::BuscarCiudadBool(NodoBinarioCiudad* nodoB, int num) {
    if (nodoB == NULL) {
        cout << "La ciudad: " << num << " no se encuentra" << endl;
        return false; // La ciudad no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return BuscarCiudadBool(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return BuscarCiudadBool(nodoB->Hder, num);
    } else {
        // La ciudad se encuentra en el nodo actual
        cout << "La ciudad: " << num << " fue encontrada." << endl;
        return true;
    }
}


void NodoBinarioCiudad::InsertaBinarioCiudad(int num, string nombre)
{
	if(num == valor){
		cout<<"Codigo repetido "<<num<<" no se agrego a la lista."<<endl;
		return;
	}
    if(num < valor){
        if(Hizq == NULL){
            Hizq = new NodoBinarioCiudad(num, nombre);
            cout<<"Ciudad "<<num<<":"<<nombre<<" fue agregada a la lista."<<endl;
        }else{
            Hizq->InsertaBinarioCiudad(num, nombre);
        }
    }else{
        if(Hder == NULL){
            Hder = new NodoBinarioCiudad(num, nombre);
            cout<<"Ciudad "<<num<<":"<<nombre<<" fue agregada a la lista."<<endl;
        }else{
            Hder->InsertaBinarioCiudad(num, nombre);
        }
    }
}

void AVLCiudad::InsertaNodoCiudad(int num, string nombre)
{
    if(raiz == NULL){
        raiz = new NodoBinarioCiudad(num, nombre);
        cout<<"Ciudad "<<num<<":"<<nombre<<" fue agregada a la lista."<<endl;
    }else{
        raiz->InsertaBinarioCiudad(num, nombre);
    }
}

void AVLCiudad::PreordenI(){
    NodoBinarioCiudad *Act = raiz;
    PilaCiudad p;
    while(!p.Vacia() || (Act != NULL)){
        if(Act != NULL){
            cout << Act->valor<<":"<<Act->ciudad << " - ";
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act = p.Pop();
            Act = Act->Hder;
        }
    }
}


void AVLCiudad::reporteCiudad(string nombre)
{
    NodoBinarioCiudad *Act = raiz;
    PilaCiudad p;
    ofstream archivo_salida("Reporte_Ciudades_"+nombre+".txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
    archivo_salida << "\t.:REPORTE LISTA CIUDADES:."<<endl<<endl<<endl;
    while(!p.Vacia() || (Act != NULL)){
        if(Act != NULL){
            archivo_salida << Act->valor<<":"<<Act->ciudad << "\n";
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act = p.Pop();
            Act = Act->Hder;
        }
    }
    cout << endl;
    archivo_salida.close();
    cout << "Reporte generado";
}

void AVLCiudad::InordenI(){
    NodoBinarioCiudad *Act = raiz;
    PilaCiudad p;
    bool band = true;
    while(band){

        while(Act != NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }
        if(!p.Vacia()){
            Act = p.Pop();
            cout << Act->valor<<":"<<Act->ciudad << " - ";
            Act = Act->Hder;
        }
        if(p.Vacia() && Act == NULL){
            break;
        }
    }
}

void AVLCiudad::PostordenI(){
    NodoBinarioCiudad *Act = raiz;
    PilaCiudad p;
    PilaCiudad p2;
    while(!p.Vacia() || Act != NULL){
        if(Act != NULL){
            p2.Push(new NodoBinarioCiudad(Act->valor, Act->ciudad));
            p.Push(Act);
            Act = Act->Hder;
        }else{
            Act = p.Pop();
            Act = Act->Hizq;
        }
    }
    while(!p2.Vacia()){
        NodoBinarioCiudad *salida = p2.Pop();
        cout << salida->valor<<":"<<salida->ciudad << " - ";
    }
}

void NodoBinarioCiudad::PreordenR(NodoBinarioCiudad *R){

    if(R == NULL){
        return;
    }else{
        cout << R->valor << " - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}

void NodoBinarioCiudad::InordenR(NodoBinarioCiudad *R){

    if(R == NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout << R->valor << " - ";
        InordenR(R->Hder);
    }
}

void NodoBinarioCiudad::PostordenR(NodoBinarioCiudad *R){

    if(R == NULL){
        return;
    }else{
        PostordenR(R->Hizq);
        PostordenR(R->Hder);
        cout << R->valor << " - ";
    }
}

void AVLCiudad::Borrar(NodoBinarioCiudad* &D, bool Hh)
{
    NodoBinarioCiudad *q;
    if(D->Hder != NULL){
        Borrar(D->Hder, Hh);
        if(Hh){
            Equilibrar2(D, Hh);
        }else{
            q->valor = D->valor;
            q = D;
            D = D->Hizq;
            Hh = true;
        }
    }
}



void AVLCiudad::BorrarBalanceadoCiudad(NodoBinarioCiudad* &raiz, bool &Hh, int x)
{
    NodoBinarioCiudad *q;
    if(raiz != NULL){
        if(x < raiz->valor){
            BorrarBalanceadoCiudad(raiz->Hizq, Hh, x);
            if(Hh){
                Equilibrar1(raiz, Hh);
            }
        }else if(x > raiz->valor){
            BorrarBalanceadoCiudad(raiz->Hder, Hh, x);
            if(Hh){
                Equilibrar2(raiz, Hh);
            }
        }else{
            q = raiz;

            if(q->Hder == NULL){
                raiz = q->Hizq;
                Hh = true;
            }else if(q->Hizq == NULL){
                raiz = q->Hder;
                Hh = true;
            }else{
                // Encuentra el sucesor inmediato (mínimo valor del subárbol derecho)
                NodoBinarioCiudad* sucesor = MinValorNodo(q->Hder);

                // Copia los datos del sucesor a q
                q->valor = sucesor->valor;
                q->ciudad = sucesor->ciudad;

                // Elimina el sucesor
                BorrarBalanceadoCiudad(q->Hder, Hh, sucesor->valor);

                if(Hh){
                    Equilibrar1(raiz, Hh);
                }
            }
            cout << "Ciudad " << x << " ha sido eliminada" << endl;
        }
    }
    else{
        // Mostrar mensaje si la ciudad no se encuentra
        cout << "Ciudad con valor " << x << " no se encuentra" << endl;
    }
}

NodoBinarioCiudad* AVLCiudad::MinValorNodo(NodoBinarioCiudad* nodo) {
    NodoBinarioCiudad* actual = nodo;
    
    while (actual->Hizq != NULL) {
        actual = actual->Hizq;
    }
    
    return actual;
}

void AVLCiudad::Equilibrar1(NodoBinarioCiudad* &n, bool &Hh){
    NodoBinarioCiudad *n1;
    switch (n->FB){
        case -1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case 1: n1 = n->Hder;
        if(n1->FB >= 0){
            if(n1->FB == 0){
                Hh = false;
                RotacionSimpleDerecha(n, n1);
            }else{
                RotacionDobleDerecha(n, n1);
            }
        }
    }
}

void AVLCiudad::Equilibrar2(NodoBinarioCiudad* &n, bool &Hh){
    NodoBinarioCiudad *n1;
    switch (n->FB){
        case 1: n->FB = 0;
        break;
        case 0: n->FB = 1;
        Hh = false;
        break;
        case -1: n1 = n->Hizq;
        if(n1->FB <= 0){
            if(n1->FB == 0){
                Hh = false;
                RotacionSimpleIzquierda(n, n1);
            }else{
                RotacionDobleIzquierda(n, n1);
            }
        }
    }
}

void AVLCiudad::InsertarBalanceadoCiudad(NodoBinarioCiudad* &ra, bool &Hh, int x, string nombre){
    pNodoBinarioCiudad n1;

    if(ra == NULL){
        ra = new NodoBinarioCiudad(x, nombre);
        cout<<"Ciudad "<<x<<":"<<nombre<<" fue agregada a la lista."<<endl;
    //    cout << ra->valor << "q as" << endl;
        Hh = true;
    }else{
    //    cout << "q as2" << endl;
        if(x == ra->valor){
        	cout<<"Codigo repetido "<<x<<" no se agrego a la lista."<<endl;
			return;
		}
        if(x < ra->valor){
            InsertarBalanceadoCiudad(ra->Hizq, Hh, x, nombre);

            if(Hh){
                switch(ra->FB){
                    case 1: ra->FB = 0;
                    Hh = false;
                    break;
                    case 0: ra->FB = -1;
                    break;
                    case -1: n1 = ra->Hizq;
                    if(n1->FB == -1){
                        RotacionSimpleIzquierda(ra, n1);
                    }else{
                        RotacionDobleIzquierda(ra, n1);
                    }
                    Hh = false;
                    break;
                }
            }
        }else{
            if(x > ra->valor){
           //     cout << "Hh:" << Hh << endl;
                InsertarBalanceadoCiudad(ra->Hder, Hh, x, nombre);

                if(Hh){
                    switch(ra->FB){
                        case -1: ra->FB = 0;
                        Hh = false;
                    //    cout << "sw-1" << endl;
                        break;
                        case 0: ra->FB = 1;
                    //    cout << "sw0" << endl;
                        break;
                        case 1: n1 = ra->Hder;
                    //    cout << "sw1" << endl;
                        if(n1->FB == 1){
                            RotacionSimpleDerecha(ra, n1);
                        }else{
                            RotacionDobleDerecha(ra, n1);
                        }
                        Hh = false;
                        break;
                    }
                }
            }
        }
    }
}

void AVLCiudad::RotacionDobleIzquierda(NodoBinarioCiudad* &n, NodoBinarioCiudad* &n1){
    NodoBinarioCiudad *n2;
    n2 = n1->Hder;
    n->Hizq = n2->Hder;
    n2->Hder = n;
    n1->Hder = n2->Hizq;
    n2->Hizq = n1;

    if(n2->FB == 1){
        n1->FB = -1;
    }else{
        n1->FB = 0;
    }
    if(n2->FB == -1){
        n->FB = 1;
    }else{
        n->FB = 0;
    }
    n2->FB = 0;
    n = n2;
}

void AVLCiudad::RotacionDobleDerecha(NodoBinarioCiudad* &n, NodoBinarioCiudad* &n1){
    NodoBinarioCiudad *n2;
    n2 = n1->Hizq;
    n->Hder = n2->Hizq;
    n2->Hizq = n;
    n1->Hizq = n2->Hder;
    n2->Hder = n1;

    if(n2->FB == 1){
        n->FB = -1;
    }else{
        n->FB = 0;
    }
    if(n2->FB == -1){
        n1->FB = 1;
    }else{
        n1->FB = 0;
    }
    n2->FB = 0;
    n = n2;
}

void AVLCiudad::RotacionSimpleDerecha(NodoBinarioCiudad* &n, NodoBinarioCiudad* &n1){
    n->Hder = n1->Hizq;
    n1->Hizq = n;

    if(n1->FB == 1){
        n->FB = 0;
        n1->FB = 0;
    }else{
        n->FB = 1;
        n1->FB = -1;
    }
    n = n1;
}

void AVLCiudad::RotacionSimpleIzquierda(NodoBinarioCiudad* &n, NodoBinarioCiudad* &n1){
    n->Hizq = n1->Hder;
    n1->Hder = n;

    if(n1->FB == -1){
        n->FB = 0;
        n1->FB = 0;
    }else{
        n->FB = -1;
        n1->FB = -1;
    }
    n = n1;
}

