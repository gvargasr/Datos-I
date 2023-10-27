#include <iostream>
#include "PilaProducto.h"
#include "AVLProducto.h"
#include <string>
#include <fstream>



using namespace std;


NodoBinarioProducto* AVLProducto::BuscarProducto(NodoBinarioProducto* nodoB, int num) {
    if (nodoB == NULL) {
//        cout << "La Producto: " << num << " no se encuentra" << endl;
        return NULL; // Producto no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return AVLProducto::BuscarProducto(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return AVLProducto::BuscarProducto(nodoB->Hder, num);
    } else {
        // Producto se encuentra en el nodo actual
//        cout << "La Producto: " << num << " fue encontrada." << endl;
        return nodoB;
    }
}

bool AVLProducto::BuscarProductoBool(NodoBinarioProducto* nodoB, int num) {
    if (nodoB == NULL) {
        cout << "El Producto: " << num << " no se encuentra" << endl;
        return false; // La Producto no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return AVLProducto::BuscarProductoBool(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return AVLProducto::BuscarProductoBool(nodoB->Hder, num);
    } else {
        // La Producto se encuentra en el nodo actual
        nodoB->Contador++;
        cout<<"\n.:Producto encontrado:."<<endl;
		cout<<"- Codigo: "<<nodoB->valor<<endl;
		cout<<"- Nombre: "<<nodoB->Producto<<endl;
		cout<<"- Kcal: "<<nodoB->Kcal<<endl;
		cout<<"- Precio: "<<nodoB->Precio<<endl;
		cout<<"- Cantidad: "<<nodoB->Cantidad<<endl;
        return true;
    }
}

bool AVLProducto::BuscarProductoPrecio(NodoBinarioProducto* nodoB, int num) {
    if (nodoB == NULL) {
        cout << "El Producto: " << num << " no se encuentra" << endl;
        return false; // La Producto no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return AVLProducto::BuscarProductoBool(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return AVLProducto::BuscarProductoBool(nodoB->Hder, num);
    } else {
    	ofstream archivo_salida("Reporte_Precio_"+to_string(num)+".txt");
    	if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    	}
    	archivo_salida << "\t.:REPORTE PRECIO DE PRODUCTO:."<<endl<<endl<<endl;
    	archivo_salida<<"\n.:Producto encontrado:."<<endl;
		archivo_salida<<"- Codigo: "<<nodoB->valor<<endl;
		archivo_salida<<"- Nombre: "<<nodoB->Producto<<endl;
		archivo_salida<<"- Precio: "<<nodoB->Precio<<endl;
        cout<<"\n.:Producto encontrado:."<<endl;
		cout<<"- Codigo: "<<nodoB->valor<<endl;
		cout<<"- Nombre: "<<nodoB->Producto<<endl;
		cout<<"- Precio: "<<nodoB->Precio<<endl;
		cout << endl;
    	archivo_salida.close();
        return true;
    }
}

bool AVLProducto::BuscarProductoCantidad(NodoBinarioProducto* nodoB, int num) {
    if (nodoB == NULL) {
        cout << "El Producto: " << num << " no se encuentra" << endl;
        return false; // La Producto no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return AVLProducto::BuscarProductoBool(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return AVLProducto::BuscarProductoBool(nodoB->Hder, num);
    } else {
    	ofstream archivo_salida("Reporte_Cantidad_"+to_string(num)+".txt");
    	if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    	}
    	archivo_salida << "\t.:REPORTE CANTIDAD DE PRODUCTO:."<<endl<<endl<<endl;
    	archivo_salida<<"\n.:Producto encontrado:."<<endl;
		archivo_salida<<"- Codigo: "<<nodoB->valor<<endl;
		archivo_salida<<"- Nombre: "<<nodoB->Producto<<endl;
		archivo_salida<<"- Cantidad disponible: "<<nodoB->Cantidad<<endl;
        cout<<"\n.:Producto encontrado:."<<endl;
		cout<<"- Codigo: "<<nodoB->valor<<endl;
		cout<<"- Nombre: "<<nodoB->Producto<<endl;
		cout<<"- Cantidad disponible: "<<nodoB->Cantidad<<endl;
		cout << endl;
    	archivo_salida.close();
        return true;
    }
}


void NodoBinarioProducto::InsertaBinarioProducto(int num, string nombre, int Kcal, int Precio, int Cantidad)
{
	if(num == valor){
		cout<<"Producto "<<num<<":"<<nombre<<" no fue agregado."<<endl;
		return;
	}
    if(num < valor){
        if(Hizq == NULL){
            Hizq = new NodoBinarioProducto( num,  nombre,  Kcal,  Precio,  Cantidad);
            cout<<"Producto "<<num<<":"<<nombre<<" fue agregado a la lista."<<endl;
        }else{
            Hizq->InsertaBinarioProducto( num,  nombre,  Kcal,  Precio,  Cantidad);
        }
    }else{
        if(Hder == NULL){
            Hder = new NodoBinarioProducto( num,  nombre,  Kcal,  Precio,  Cantidad);
            cout<<"Producto "<<num<<":"<<nombre<<" fue agregado a la lista."<<endl;
        }else{
            Hder->InsertaBinarioProducto( num,  nombre,  Kcal,  Precio,  Cantidad);
        }
    }
}

void AVLProducto::InsertaNodoProducto(int num, string nombre, int Kcal, int Precio, int Cantidad)
{
    if(AVLProducto::raiz == NULL){
        AVLProducto::raiz = new NodoBinarioProducto(num, nombre, Kcal, Precio, Cantidad);
        cout<<"Producto "<<num<<":"<<nombre<<" fue agregado a la lista."<<endl;
    }else{
        AVLProducto::raiz->InsertaBinarioProducto(num, nombre, Kcal, Precio, Cantidad);
    }
}

void AVLProducto::PreordenI(){
    NodoBinarioProducto *Act = AVLProducto::raiz;
    PilaProducto p;
    while(!p.Vacia() || (Act != NULL)){
        if(Act != NULL){
            cout << Act->valor<<":"<<Act->Producto << " - ";
            p.Push(Act);
            Act = Act->Hizq;
        }else{
            Act = Act->Hder;
        }
    }
}


void AVLProducto::reporteProducto(string nombre)// se introduce el nombre del Menu
{
    NodoBinarioProducto *Act = AVLProducto::raiz;
    PilaProducto p;
    ofstream archivo_salida("Reporte_Productos_"+nombre+".txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
    archivo_salida << "\t.:REPORTE LISTA PRODUCTOS:."<<endl<<endl<<endl;
    while(!p.Vacia() || (Act != NULL)){
        if(Act != NULL){
            archivo_salida <<"Nombre: "<< Act->Producto<<"\n"<<"Codigo: "<<Act->valor <<"\n"<<"Kcal: "<<Act->Kcal<< "\n"<<"Precio: "<<Act->Precio<<"\nCantidad: "<<Act->Cantidad<<endl<<endl;
            archivo_salida <<"###############################"<<endl;
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

void AVLProducto::InordenI(){
    NodoBinarioProducto *Act = AVLProducto::raiz;
    PilaProducto p;
    bool band = true;
    while(band){

        while(Act != NULL){
            p.Push(Act);
            Act = Act->Hizq;
        }
        if(!p.Vacia()){
            Act = p.Pop();
            cout << Act->valor<<":"<<Act->Producto << " - ";
            Act = Act->Hder;
        }
        if(p.Vacia() && Act == NULL){
            break;
        }
    }
}

void AVLProducto::PostordenI(){
    NodoBinarioProducto *Act = AVLProducto::raiz;
    PilaProducto p;
    PilaProducto p2;
    while(!p.Vacia() || Act != NULL){
        if(Act != NULL){
            p2.Push(new NodoBinarioProducto(Act->valor, Act->Producto, Act->Kcal,Act->Precio,Act->Cantidad));
            p.Push(Act);
            Act = Act->Hder;
        }else{
            Act = p.Pop();
            Act = Act->Hizq;
        }
    }
    while(!p2.Vacia()){
        NodoBinarioProducto *salida = p2.Pop();
        cout << salida->valor<<":"<<salida->Producto << " - ";
    }
}

void PreordenR(NodoBinarioProducto *R){

    if(R == NULL){
        return;
    }else{
        cout << R->valor << " - ";
        PreordenR(R->Hizq);
        PreordenR(R->Hder);
    }
}
/*
void InordenR(NodoBinarioProducto *R){

    if(R == NULL){
        return;
    }else{
        InordenR(R->Hizq);
        cout << R->valor << " - ";
        InordenR(R->Hder);
    }
}*/

void AVLProducto::PostordenR(NodoBinarioProducto *R){

    if(R == NULL){
        return;
    }else{
        AVLProducto::PostordenR(R->Hizq);
        AVLProducto::PostordenR(R->Hder);
        cout << R->valor << " - ";
    }
}

void AVLProducto::Borrar(NodoBinarioProducto* &D, bool Hh)
{
    NodoBinarioProducto *q;
    if(D->Hder != NULL){
        AVLProducto::Borrar(D->Hder, Hh);
        if(Hh){
            AVLProducto::Equilibrar2(D, Hh);
        }else{
            q->valor = D->valor;
            q = D;
            D = D->Hizq;
            Hh = true;
        }
    }
}

/*void AVLProducto::BorrarBalanceadoProducto(NodoBinarioProducto* &raiz, bool &Hh, int x)
{
    NodoBinarioProducto *q;
    if(raiz != NULL){
        if(x < raiz->valor){
            BorrarBalanceadoProducto(raiz->Hizq, Hh, x);
            if(Hh){
                Equilibrar1(raiz, Hh);
            }
        }else{
            if(x > raiz->valor){
                BorrarBalanceadoProducto(raiz->Hder, Hh, x);
                if(Hh){
                    Equilibrar2(raiz, Hh);
                }
            }else{
                q = raiz;

                if(q->Hder == NULL){
                    raiz = q->Hizq;
                    Hh = true;
                }else{
                    if(
                        Hh = true;
                    }else{
                        Borrar(q->Hizq, Hh);
                    }
                    if(Hh){
                        Equilibrar1(raiz, Hh);
                    }
                }
            cout << "Producto " << x << " ha sido eliminada" << endl;
            }
        }
    }
    else{
        // Mostrar mensaje si la Producto no se encuentra
        cout << "Producto con valor " << x << " no se encuentra" << endl;
    }
}*/

void AVLProducto::BorrarBalanceadoProducto(NodoBinarioProducto* &raiz, bool &Hh, int x)
{
    NodoBinarioProducto *q;
    if(raiz != NULL){
        if(x < raiz->valor){
            AVLProducto::BorrarBalanceadoProducto(raiz->Hizq, Hh, x);
            if(Hh){
                AVLProducto::Equilibrar1(raiz, Hh);
            }
        }else if(x > raiz->valor){
            AVLProducto::BorrarBalanceadoProducto(raiz->Hder, Hh, x);
            if(Hh){
                AVLProducto::Equilibrar2(raiz, Hh);
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
                NodoBinarioProducto* sucesor = AVLProducto::MinValorNodo(q->Hder);

                // Copia los datos del sucesor a q
                q->valor = sucesor->valor;
                q->Producto = sucesor->Producto;

                // Elimina el sucesor
                AVLProducto::BorrarBalanceadoProducto(q->Hder, Hh, sucesor->valor);

                if(Hh){
                    AVLProducto::Equilibrar1(raiz, Hh);
                }
            }
            cout << "Producto " << x << " ha sido eliminada" << endl;
        }
    }
    else{
        // Mostrar mensaje si la Producto no se encuentra
        cout << "Producto con valor " << x << " no se encuentra" << endl;
    }
}

NodoBinarioProducto* AVLProducto::MinValorNodo(NodoBinarioProducto* nodo) {
    NodoBinarioProducto* actual = nodo;
    
    while (actual->Hizq != NULL) {
        actual = actual->Hizq;
    }
    
    return actual;
}

void AVLProducto::Equilibrar1(NodoBinarioProducto* &n, bool &Hh){
    NodoBinarioProducto *n1;
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
                AVLProducto::RotacionSimpleDerecha(n, n1);
            }else{
                AVLProducto::RotacionDobleDerecha(n, n1);
            }
        }
    }
}

void AVLProducto::Equilibrar2(NodoBinarioProducto* &n, bool &Hh){
    NodoBinarioProducto *n1;
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

void AVLProducto::InsertarBalanceadoProducto(NodoBinarioProducto* &ra, bool &Hh, int x, string nombre, int cal, int precio, int cant){
    pNodoBinarioProducto n1;

    if(ra == NULL){
        ra = new NodoBinarioProducto(x, nombre,  cal,  precio,  cant);
        cout<<"Producto "<<x<<":"<<nombre<<" fue agregada a la lista."<<endl;
    //    cout << ra->valor << "q as" << endl;
        Hh = true;
    }else{
    //    cout << "q as2" << endl;
        if(x == ra->valor){
        	cout<<"Codigo repetido "<<x<<" no se agrego a la lista."<<endl;
			return;
		}
        if(x < ra->valor){
            AVLProducto::InsertarBalanceadoProducto(ra->Hizq, Hh, x, nombre,  cal,  precio,  cant);

            if(Hh){
                switch(ra->FB){
                    case 1: ra->FB = 0;
                    Hh = false;
                    break;
                    case 0: ra->FB = -1;
                    break;
                    case -1: n1 = ra->Hizq;
                    if(n1->FB == -1){
                        AVLProducto::RotacionSimpleIzquierda(ra, n1);
                    }else{
                        AVLProducto::RotacionDobleIzquierda(ra, n1);
                    }
                    Hh = false;
                    break;
                }
            }
        }else{
            if(x > ra->valor){
           //     cout << "Hh:" << Hh << endl;
                AVLProducto::InsertarBalanceadoProducto(ra->Hder, Hh, x, nombre,  cal,  precio,  cant);

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
                            AVLProducto::RotacionSimpleDerecha(ra, n1);
                        }else{
                            AVLProducto::RotacionDobleDerecha(ra, n1);
                        }
                        Hh = false;
                        break;
                    }
                }
            }
        }
    }
}

void AVLProducto::RotacionDobleIzquierda(NodoBinarioProducto* &n, NodoBinarioProducto* &n1){
    NodoBinarioProducto *n2;
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

void AVLProducto::RotacionDobleDerecha(NodoBinarioProducto* &n, NodoBinarioProducto* &n1){
    NodoBinarioProducto *n2;
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

void AVLProducto::RotacionSimpleDerecha(NodoBinarioProducto* &n, NodoBinarioProducto* &n1){
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

void AVLProducto::RotacionSimpleIzquierda(NodoBinarioProducto* &n, NodoBinarioProducto* &n1){
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

NodoBinarioProducto* AVLProducto::ProductoMasBuscado(NodoBinarioProducto* nodoB) {
    if (nodoB == NULL) {
        cout << "El arbol esta vacio." << endl;
        return NULL;
    }
    NodoBinarioProducto* masBuscado = NULL;
    int maxContador = -1;

    masBuscado = InordenR(nodoB, masBuscado, maxContador);

    if (masBuscado != NULL) {
        cout << "\nEl producto mas buscado es: \n" << masBuscado->valor << ":" << masBuscado->Producto << "\nFue buscado: " << masBuscado->Contador << " veces." << endl << endl;
    }
    else {
        cout << "Ningun producto encontrado." << endl;
    }

    return masBuscado;
}

NodoBinarioProducto* AVLProducto::InordenR(NodoBinarioProducto* R, NodoBinarioProducto*& masBuscado, int& maxContador) {
    if (R == NULL) {
        return masBuscado;
    }

    InordenR(R->Hizq, masBuscado, maxContador);

    if (R->Contador > maxContador) {
        maxContador = R->Contador;
        masBuscado = R;
    }

    InordenR(R->Hder, masBuscado, maxContador);

    return masBuscado;
}

NodoBinarioProducto* AVLProducto::PrecioProducto(NodoBinarioProducto* nodoB, int num) {
    if (nodoB == NULL) {
//        cout << "La Producto: " << num << " no se encuentra" << endl;
        return NULL; // Producto no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return PrecioProducto(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return PrecioProducto(nodoB->Hder, num);
    } else {
        // Producto se encuentra en el nodo actual
        cout << "El precio de " << num <<":"<<nodoB->Producto<< " es : " <<nodoB->Precio<<endl<< endl;
        return nodoB;
    }
}

void AVLProducto::Reducir(NodoBinarioProducto* nodoB, int num){
	 if (nodoB == NULL) {
		cout<<"Error en nodo"<<endl;
    }  else {
		nodoB->Cantidad = nodoB->Cantidad - num;
		nodoB->ContadorCompras = nodoB->ContadorCompras + num;
	}
    
}

NodoBinarioProducto* AVLProducto::ProductoMasComprado(NodoBinarioProducto* nodoB) {
    NodoBinarioProducto* masBuscado = NULL;
    int maxContador = -1;

    AVLProducto::InordenR(nodoB, masBuscado, maxContador);
	cout<< "\nEl producto mas comprado es: \n"<<masBuscado->valor<<":"<<masBuscado->Producto<<"\nFue buscado: "<<masBuscado->ContadorCompras<<" veces."<<endl<<endl;
    return masBuscado;
}

void AVLProducto::InordenRCompras(NodoBinarioProducto* R, NodoBinarioProducto*& masBuscado, int& maxContador) {
    if (R == NULL) {
        return;
    }

    AVLProducto::InordenRCompras(R->Hizq, masBuscado, maxContador);

    if (R->ContadorCompras > maxContador) {
        maxContador = R->ContadorCompras;
        masBuscado = R;
    }

    AVLProducto::InordenRCompras(R->Hder, masBuscado, maxContador);
}


bool AVLProducto::BuscarProductoCantidadCompra(NodoBinarioProducto* nodoB, int num) {
    if (nodoB == NULL) {
        cout << "El Producto: " << num << " no se encuentra" << endl;
        return false; // La Producto no se encuentra en el árbol
    }
    if (num < nodoB->valor) {
        return AVLProducto::BuscarProductoCantidadCompra(nodoB->Hizq, num);
    } else if (num > nodoB->valor) {
        return AVLProducto::BuscarProductoCantidadCompra(nodoB->Hder, num);
    } else {
    	ofstream archivo_salida("Reporte_Compra_"+to_string(num)+".txt");
    	if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    	}
    	archivo_salida << "\t.:REPORTE CANTIDAD DE PRODUCTO:."<<endl<<endl<<endl;
    	archivo_salida<<"\n.:Producto encontrado:."<<endl;
		archivo_salida<<"- Codigo: "<<nodoB->valor<<endl;
		archivo_salida<<"- Nombre: "<<nodoB->Producto<<endl;
		archivo_salida<<"- Cantidad comprada: "<<nodoB->ContadorCompras<<endl;
    	archivo_salida.close();
        return true;
    }
}

/*
int main(){
	AVLProducto listaProd;
	listaProd.InsertaNodoProducto(109,"Queso",50,950,19);
	listaProd.InsertaNodoProducto(543,"PapasKids",87,590,21);
	listaProd.reporteProducto("TAVO");
	listaProd.BuscarProductoBool(listaProd.raiz, 19);
		listaProd.BuscarProductoBool(listaProd.raiz, 109);
listaProd.BuscarProductoBool(listaProd.raiz, 543);
	listaProd.BuscarProductoBool(listaProd.raiz, 19);

	listaProd.BuscarProductoBool(listaProd.raiz, 109);

	listaProd.BuscarProductoBool(listaProd.raiz, 109);

	listaProd.ProductoMasBuscado(listaProd.raiz);
	listaProd.PrecioProducto(listaProd.raiz, 109);
	listaProd.PrecioProducto(listaProd.raiz, 543);
	return 0;
}*/
