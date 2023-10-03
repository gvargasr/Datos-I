#include <iostream>
#include <string>

using namespace std;

class Pagina_Cliente {
	public:
		int claves [4];
		string nombre [4];
		Pagina_Cliente* Ramas[5];
		Pagina_Cliente* rama1; 
		Pagina_Cliente* rama2; 
		Pagina_Cliente* rama3; 
		Pagina_Cliente* rama4; 
		Pagina_Cliente* rama5;
		int cuenta;
		
	
    Pagina_Cliente() : cuenta(0) {
        for (int i = 0; i < 4; ++i) {
            claves[i] = 0; // Inicializar cédulas con 0 (considerando 0 como valor inválido)
            nombre[i] = "";
        }
        rama1 = rama2 = rama3 = rama4 = rama5 = nullptr;
        Ramas[0] = rama1;
        Ramas[1] = rama2;
        Ramas[2] = rama3;
        Ramas[3] = rama4;
        Ramas[4] = rama5;
    }

    // Constructor con parámetros
    Pagina_Cliente(int pCedula, string pNombre) : Pagina_Cliente() {
        claves[0] = pCedula;
        nombre[0] = pNombre;
        cuenta = 1;
    }
    
    // Método para obtener la cuenta de la página
    int obtenerCuenta() const {
        return cuenta;
    }

    // Destructor
    ~Pagina_Cliente() {
        // Puedes implementar lógica de liberación de memoria si es necesario
    }
		
		
};

typedef Pagina_Cliente* puntero_Cliente;

class ArbolB{
	public :
	Pagina_Cliente* raiz;
	
	ArbolB() {
        raiz = new Pagina_Cliente();
    }
	
	void Empujar(int C1, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& Xr);
    void InsertarClave(int clave, Pagina_Cliente*& raiz);
    bool BuscarNodo(int clave, Pagina_Cliente* P, bool& Encontrado, int& K);
    void ImprimirArbol(Pagina_Cliente* raiz);
    void MeterHoja(int X, Pagina_Cliente* Xder, Pagina_Cliente*& P, int K);
    void DividirNodo(int X, Pagina_Cliente* Xder, Pagina_Cliente*& P, int K, int& Mda, Pagina_Cliente*& Mder);
    
    friend Pagina_Cliente;
};

bool ArbolB::BuscarNodo(int clave, Pagina_Cliente* P, bool& Encontrado, int& K) {
    if (clave < P->claves[1]) {
        Encontrado = false;
        K = 0; // Rama por donde descender
    } else {
        K = P->cuenta;
        while (clave < P->claves[K] && K > 1) {
            K = K - 1;
        }
        Encontrado = (clave == P->claves[K]);
    }

    return Encontrado;
}

void ArbolB::InsertarClave(int clave, Pagina_Cliente*& raiz) {
    bool empujarArriba = false;
    int X;
    Pagina_Cliente* Xr = NULL;
    Empujar(clave, raiz, empujarArriba, X, Xr);
    if (empujarArriba) {
        Pagina_Cliente* P = new Pagina_Cliente();
        P->cuenta = 1;
        P->claves[1] = X;
        P->Ramas[0] = raiz;
        P->Ramas[1] = Xr;
        raiz = P;
    }
}

void ArbolB::ImprimirArbol(Pagina_Cliente* raiz) {
    if (raiz) {
        for (int i = 0; i <= raiz->cuenta; ++i) {
            ImprimirArbol(raiz->Ramas[i]);

            if (i < raiz->cuenta) {
                cout << raiz->claves[i + 1] << " ";
            }
        }
    }
}

	void ArbolB::Empujar(int C1, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& Xr) {
        if (R == nullptr) {
            // Árbol vacío, termina la recursión
            EmpujaArriba = true;
            Mdna = C1;
            Xr = nullptr;
        } else {
            bool Esta; 
            int K;
			BuscarNodo(C1, R, Esta, K);
            if (Esta == false) {
                cout << "Elemento repetido" << endl;
                EmpujaArriba = false;
                return;
            }

            Empujar(C1, R->Ramas[K], EmpujaArriba, Mdna, Xr);

            if (EmpujaArriba) {
                if (R->cuenta < 4) {
                    EmpujaArriba = false;
                    MeterHoja(Mdna, Xr, R, K + 1);
                } else {
                    EmpujaArriba = true;
                    DividirNodo(Mdna, Xr, R, K, Mdna, Xr);
                }
            }
        }
    }

void ArbolB::MeterHoja(int X, Pagina_Cliente* Xder, Pagina_Cliente*& P, int K) {
    Pagina_Cliente* Mder = new Pagina_Cliente();
    Mder->cuenta = 0;

    for (int I = P->cuenta; I >= K + 1; --I) {
        P->claves[I + 1] = P->claves[I];
        P->Ramas[I + 1] = P->Ramas[I];
    }

    P->claves[K + 1] = X;
    P->Ramas[K + 1] = Xder;
    P->cuenta = P->cuenta + 1;
}

void ArbolB::DividirNodo(int X, Pagina_Cliente* Xder, Pagina_Cliente*& P, int K, int& Mda, Pagina_Cliente*& Mder) {
    int Min = 2;

    int Posmda;
    if (K <= Min) {
        Posmda = Min;
    } else {
        Posmda = Min + 1;
    }

    Mder = new Pagina_Cliente();
    Mder->cuenta = 0;

    for (int I = Posmda + 1; I <= 4; ++I) {
        Mder->claves[I - Posmda] = P->claves[I];
        Mder->Ramas[I - Posmda] = P->Ramas[I];
        Mder->cuenta++;
    }

    P->cuenta = Posmda - 1;

    if (K <= Min) {
        MeterHoja(X, Xder, P, K);
    } else {
        MeterHoja(X, Xder, Mder, K - Posmda);
        Mda = P->claves[P->cuenta];
        Mder->Ramas[0] = P->Ramas[P->cuenta];
        P->cuenta--;
    }
}

int main() {
    ArbolB* clientes = new ArbolB();

    clientes->InsertarClave(3, clientes->raiz);
    
//    clientes->BuscarNodo(3, clientes->raiz);
  /*  clientes->InsertarClave(5, clientes->raiz);
    clientes->InsertarClave(8, clientes->raiz);
    clientes->InsertarClave(14, clientes->raiz);
    clientes->InsertarClave(15, clientes->raiz);
*/
    cout << "Árbol B: ";
    clientes->ImprimirArbol(clientes->raiz);
    cout << endl;

    delete clientes;
    return 0;
}
