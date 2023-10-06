#include <iostream>
#include <string>

using namespace std;

class Pagina_Cliente {
	public:
		int claves [5];
		string nombre [5];
		Pagina_Cliente* Ramas[5];
		Pagina_Cliente* rama1; 
		Pagina_Cliente* rama2; 
		Pagina_Cliente* rama3; 
		Pagina_Cliente* rama4; 
		Pagina_Cliente* rama5;
		int Cuenta;
		
	
    Pagina_Cliente() : Cuenta(0) {
        for (int i = 0; i < 5; i++) {
            claves[i] = 0; 
            nombre[i] = "";
        }
        rama1 = rama2 = rama3 = rama4 = rama5 = NULL;
        Ramas[0] = rama1;
        Ramas[1] = rama2;
        Ramas[2] = rama3;
        Ramas[3] = rama4;
        Ramas[4] = rama5;
    }

    // Constructor con parámetros
    Pagina_Cliente(int pCedula, string pNombre) : Pagina_Cliente() {
        claves[1] = pCedula;
        nombre[1] = pNombre;
        Cuenta = 1;
    }
    
    int obtenerCuenta() const {
        return Cuenta;
    }

    ~Pagina_Cliente() {
    	        for (int i = 0; i < 5; i++) {
            claves[i] = 0; 
            nombre[i] = "";
        }
        rama1 = rama2 = rama3 = rama4 = rama5 = nullptr;
        Ramas[0] = rama1;
        Ramas[1] = rama2;
        Ramas[2] = rama3;
        Ramas[3] = rama4;
        Ramas[4] = rama5;
    }
		
		
};

typedef Pagina_Cliente* puntero_Cliente;

class ArbolB{
	public :
	Pagina_Cliente* raiz;
	
	ArbolB() {
        raiz = new Pagina_Cliente();
    }
	
	void Empujar(int C1, string nombre, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& X);
    void InsertarClave(int C1, string nombre, Pagina_Cliente*& raiz);
    void BuscarNodo(int Clave, Pagina_Cliente*& P, bool& Encontrado, int K);
    void ImprimirArbol(Pagina_Cliente*& raiz);
    void MeterHoja(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K);
    void DividirNodo(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K, int& Mda, Pagina_Cliente*& Mder);
    void search(int clave, Pagina_Cliente* raiz);

    
    friend Pagina_Cliente;
};


void ArbolB::search(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<"NO SE ENCONTRO"<<endl;
        return;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
        cout<<"si  SE ENCONTRO"<<endl;
    } else {
        return search(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}




void ArbolB::BuscarNodo(int Clave, Pagina_Cliente*& P, bool& Encontrado, int K) {
	if(Clave < P->claves[1]){
		Encontrado = false;
	}else{
		K = P->Cuenta;
		while(Clave < P->claves[K] && K > 1){
			K=K-1;
		}
	}
	Encontrado = Clave==P->claves[K];
}





void ArbolB::InsertarClave(int C1, string nombre, Pagina_Cliente*& raiz) {
	bool EmpujaArriba = false;
    int X = 0;
    Pagina_Cliente* Xr = NULL;
    Pagina_Cliente* P = NULL;
    Empujar(C1, nombre, raiz, EmpujaArriba, X, Xr);
    if (EmpujaArriba) {
        Pagina_Cliente* P = new Pagina_Cliente();
        P->Cuenta = 1;
        P->claves[1] = X;
        P->nombre[1] = nombre;
        P->Ramas[0] = raiz;
        P->Ramas[1] = Xr;
        raiz = P;
    }
}

void ArbolB::Empujar(int C1, string nombre, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& X) {
    if (R == NULL) {
        EmpujaArriba = true;
        Mdna = C1;
        X = NULL;
    } else {
    	bool Esta = false; 
    	int K = 0;
		BuscarNodo(C1, R, Esta, K);
        if (Esta){
            cout<<"Cliente "<<C1<<":"<<nombre<<" no fue agregado."<<endl;
            return;
		}
        Empujar(C1, nombre, R->Ramas[K], EmpujaArriba, Mdna, X);
            if (EmpujaArriba) {
               	if (R->Cuenta < 4) {
               		EmpujaArriba = false;
               		MeterHoja(Mdna, nombre, X, R, K);
               		cout<<"Cliente "<<C1<<":"<<nombre<<" ha sido agregado."<<endl;
              	}else{
               		EmpujaArriba = true;
               		DividirNodo(Mdna, nombre, X, R, K, Mdna, X);
               //		cout<<"Cliente "<<C1<<":"<<nombre<<" ha sido agregado."<<endl;
               	}
          	}
		}        
}
    
void ArbolB::ImprimirArbol(Pagina_Cliente*& raiz) {
    if (raiz) {
        for (int i = 1; i <= raiz->Cuenta; i++) {
            ImprimirArbol(raiz->Ramas[i-1]);
            cout << raiz->claves[i] << " ";
            }
        ImprimirArbol(raiz->Ramas[raiz->Cuenta]); 
    }
}




void ArbolB::MeterHoja(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K) {
    Pagina_Cliente* Mder = new Pagina_Cliente();
    Mder->Cuenta = 0;

    for (int I = P->Cuenta; I >= K + 1; I--) {
        P->claves[I + 1] = P->claves[I];
        P->Ramas[I + 1] = P->Ramas[I];
    }

    P->claves[K + 1] = X;
    P->Ramas[K + 1] = Xder;
    P->Cuenta = P->Cuenta + 1;
}

void ArbolB::DividirNodo(int X, string nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K, int& Mda, Pagina_Cliente*& Mder) {
    int Min = 2;
    int Posmda;
    if (K <= Min) {
        Posmda = Min;
    } else {
        Posmda = Min + 1;
    }

    Mder = new Pagina_Cliente();
   // Mder->cuenta = 0;

    for (int I = Posmda + 1; I <= 4; ++I) {
        Mder->claves[I - Posmda] = P->claves[I];
        Mder->Ramas[I - Posmda] = P->Ramas[I];
    }
	Mder->Cuenta = 4-Posmda;
    P->Cuenta = Posmda;

    if (K <= Min) {
        MeterHoja(X, nombre, Xder, P, K);
    } else 
        MeterHoja(X, nombre, Xder, Mder, K - Posmda);
    Mda = P->claves[P->Cuenta];
    Mder->Ramas[0] = P->Ramas[P->Cuenta];
    P->Cuenta = P->Cuenta-1;
}
/*
int main() {
    ArbolB* clientes = new ArbolB();
    clientes->InsertarClave(16, "hola", clientes->raiz);
	clientes->InsertarClave(1, "hola", clientes->raiz);
    clientes->InsertarClave(2, "hola", clientes->raiz);
    clientes->InsertarClave(3, "hola", clientes->raiz);
    clientes->InsertarClave(3, "hola", clientes->raiz);
    clientes->InsertarClave(4, "hola", clientes->raiz);
    clientes->InsertarClave(5, "hola", clientes->raiz);
    clientes->InsertarClave(5, "hola", clientes->raiz);
    clientes->InsertarClave(6, "hola", clientes->raiz);
    clientes->InsertarClave(6, "hola", clientes->raiz);
    clientes->InsertarClave(7, "hola", clientes->raiz);
    clientes->InsertarClave(8, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(10, "hola", clientes->raiz);
        clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
  /*  clientes->InsertarClave(4, "hola", clientes->raiz);
    clientes->InsertarClave(7, "hola", clientes->raiz);
    clientes->InsertarClave(8, "hola", clientes->raiz);
    clientes->InsertarClave(9, "hola", clientes->raiz);
   clientes->InsertarClave(88, "hola", clientes->raiz);
   clientes->InsertarClave(88, "hola", clientes->raiz);
   clientes->InsertarClave(10, "hola", clientes->raiz);*/
  /*  clientes->InsertarClave(5, clientes->raiz);
    clientes->InsertarClave(8, clientes->raiz);
    clientes->InsertarClave(14, clientes->raiz);
    clientes->InsertarClave(15, clientes->raiz);

    cout << "Árbol B: ";
    clientes->ImprimirArbol(clientes->raiz);
    cout << endl;

    delete clientes;
    return 0;
}*/
