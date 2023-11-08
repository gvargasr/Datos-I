#include <iostream>
#include <string>
#include <fstream>
//#include "listaDCompra.h"
#include "ArbolB.h"

using namespace std;


ArbolB::ArbolB() {
    raiz = new Pagina_Cliente();
}

void ArbolB::Modificar(int clave, string nombre, Pagina_Cliente*& raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
    return;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    	raiz->nombre[K] = nombre;
        cout<<".:Cliente modificado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
    return;
    } else {
        Modificar(clave, nombre, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

int ArbolB::CompraDeCliente(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return -1;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    	if(raiz->compras[K] != 0){
        cout<<"\n.:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<"\nHa comprado: "<<raiz->compras[K]<<" veces."<<endl<<endl;
        return raiz->compras[K];
        }else{
        	cout<<"Aun no se han realizado compras."<<endl<<endl;
        	return 0;
		}
    } else {
        return CompraDeCliente(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

bool ArbolB::Search(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return false;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
        cout<<"\n.:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return true;
    } else {
        return Search(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

bool ArbolB::SearchC(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
        cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return false;
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    	    raiz->compras[K]++;
        //cout<<"\n.:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return true;
    } else {
        return SearchC(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

string ArbolB::SearchContador(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
    //    cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return "";
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
        cout<<".:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return raiz->nombre[K];
    } else {
        return SearchContador(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}

string ArbolB::SearchNodo(int clave, Pagina_Cliente* raiz) {
    if (raiz == NULL) {
    //    cout<<".:Cliente con cedula "<<clave<<" no se encuentra:."<<endl<<endl;
        return "";
    }

    bool Encontrado = false;
    int K = 0;
    BuscarNodo(clave, raiz, Encontrado, K);

    if (Encontrado) {
    //    cout<<".:Cliente encontrado:.\n"<<"Cedula: "<<raiz->claves[K]<<"\nNombre: "<<raiz->nombre[K]<<endl<<endl;
        return raiz->nombre[K];
    } else {
        return SearchNodo(clave, raiz->Ramas[K]); // Buscar en la rama adecuada
    }
}






bool ArbolB::BuscarNodo(int Clave, Pagina_Cliente* P, bool& Encontrado, int& K) {   
	if(Clave < P->claves[1]){
		Encontrado = false;
		K=0;
        return false;
	}else{
		K = P->Cuenta; 
		while(Clave < P->claves[K] && K > 1)
			K=K-1;
		Encontrado = Clave == P->claves[K];
        return Clave == P->claves[K];
//		cout<<"Encontrado: "<<Encontrado<<endl;
	}
}




void ArbolB::InsertarClave(int C1, string nombre, Pagina_Cliente*& raiz) {
	bool EmpujaArriba = false;
    int X = 0;
    Pagina_Cliente* Xr = NULL;
    Pagina_Cliente* P = NULL;
    Empujar(C1, nombre, raiz, EmpujaArriba, X, Xr);
//    cout<<"EmpujaArriba: "<<EmpujaArriba<<endl;
    if (EmpujaArriba) {
        Pagina_Cliente* P = new Pagina_Cliente();
        P->Cuenta = 1;
        P->claves[1] = X;
        P->nombre[1] = nombre;
        P->Ramas[0] = raiz;
        P->Ramas[1] = Xr;
        raiz = P;
//        cout<<"Nuevo: "<<nombre<<endl;
    }
}

void ArbolB::Empujar(int C1, string& nombre, Pagina_Cliente*& R, bool& EmpujaArriba, int& Mdna, Pagina_Cliente*& Xr) { 
    	bool Esta = false; 
    	int K = 0;
    if (R == NULL) {
        EmpujaArriba = true;
        Mdna = C1;
        Xr = NULL;
    } else {
		BuscarNodo(C1, R, Esta, K);   
        if (Esta){
            cout<<"Cliente "<<C1<<":"<<nombre<<" no fue agregado."<<endl;
            EmpujaArriba = false;
		}else{
		//	cout<<"Mdna1: "<<Mdna<<endl;
//						cout<<"EmpujaArriba1: "<<EmpujaArriba<<endl<<endl;
//				cout<<"K antes: "<<K<<endl;
//				cout<<"Mdna antes: "<<Mdna<<endl;

			Empujar(C1, nombre, R->Ramas[K], EmpujaArriba, Mdna, Xr);
//			cout<<"EmpujaArriba2: "<<EmpujaArriba<<endl<<endl;
//				cout<<"Mdna: "<<Mdna<<endl;
//				cout<<"K: "<<K<<endl;
        	if (EmpujaArriba) {
//        		cout<<"Cliente "<<C1<<":"<<nombre<<" ha sido agregado."<<endl;
//        		cout<<"Cuenta: "<<R->Cuenta<<endl;
          		if (R->Cuenta < 4) {
            	//	cout<<"K cuenta NO llena "<<K<<endl;
           		EmpujaArriba = false;
           		MeterHoja(Mdna, nombre, Xr, R, K);
            	}else{
//            		cout<<"K cuenta llena "<<K<<endl;
            	EmpujaArriba = true;
//            	cout<<"Xr "<< (Xr == NULL)<<endl;
            	DividirNodo(Mdna, nombre, Xr, R, K, Mdna, Xr);
            	}
        	}
        }
	}        
}


void ArbolB::MeterHoja(int X, string& nombre, Pagina_Cliente*& Xder, Pagina_Cliente*& P, int K) {
//	cout<<"K en METERHOJA DIVIDIRNODO"<<K<<endl;
//	cout<<"I en METERHOJA DIVIDIRNODO"<<P->Cuenta<<endl;
//	cout<<"X en METERHOJA DIVIDIRNODO"<<X<<endl;

	
    for (int I = P->Cuenta; I >= K+1; --I) {
        P->claves[I + 1] = P->claves[I];
        P->nombre[I + 1] = P->nombre[I];
        P->Ramas[I + 1] = P->Ramas[I];
    }

    P->claves[K+1] = X;
    P->nombre[K+1] = nombre;
    P->Ramas[K+1] = Xder;
    P->Cuenta = P->Cuenta+1;
 	cout<<"Cliente "<<X<<":"<<nombre<<" ha sido agregado."<<endl;

}

void ArbolB::DividirNodo(int X, string& nombre, Pagina_Cliente* Xder, Pagina_Cliente*& P, int& K, int& Mda, Pagina_Cliente*& Mder) {
//	cout<<"K dividirnodo: "<<K<<endl;
    int Posmda;
    if (K <= 2) {
        Posmda = 2;
    } else {
        Posmda = 3;
    }

    Mder = new Pagina_Cliente();

    for (int I = Posmda + 1; I <= 4; I++) {
        Mder->claves[I - Posmda] = P->claves[I];
        Mder->nombre[I - Posmda] = P->nombre[I];
        Mder->Ramas[I - Posmda] = P->Ramas[I];
    }
	Mder->Cuenta = 4-Posmda;
    P->Cuenta = Posmda;
    if (K <= 2) {
//    	cout<<"X: "<<X<<endl;
//    	cout<<"K: "<<K<<endl;
        MeterHoja(X, nombre, Xder, P, K);  //inserta a la izq

    } else {
//    		cout<<"METERHOJA LLENA: "<<endl;
//	cout<<"K: "<<K<<endl;
//	cout<<"pOSMDA: "<<Posmda<<endl;
        MeterHoja(X, nombre, Xder, Mder, K - Posmda);
    }
    	Mda = P->claves[P->Cuenta];
    	nombre = P->nombre[P->Cuenta];
//    		cout<<"Mda1: "<<Mda<<endl;
 //   		cout<<"Nombre Mda1: "<<nombre<<endl;

    	Mder->Ramas[0] = P->Ramas[P->Cuenta];
 //   	P->Cuenta--;
 //   	cout<<"Resto cuenta a Raiz: "<<P->Cuenta<<endl;
	
	P->Cuenta--;	
}

 void ArbolB::inOrderTraversal(Pagina_Cliente* raiz, ofstream& outFile) {
        if (raiz != nullptr) {
            for (int i = 0; i < raiz->Cuenta; i++) {
                inOrderTraversal(raiz->Ramas[i], outFile);
                outFile << raiz->claves[i + 1] << " " << raiz->nombre[i + 1] << endl;
            }
            inOrderTraversal(raiz->Ramas[raiz->Cuenta], outFile);
        }
    }

void ArbolB::saveToFile(const string& filename) {
    ofstream outFile(filename);
    outFile << "\t.:REPORTE LISTA CLIENTES:."<<endl<<endl<<endl;
    if (outFile.is_open()) {
        inOrderTraversal(raiz, outFile);
        outFile.close();
        cout << "Reporte generado"<< endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}



void ArbolB::ImprimirArbol(Pagina_Cliente* raiz) {
    if (raiz != NULL) {
        for (int i = 0; i < raiz->Cuenta; ++i) {
            ImprimirArbol(raiz->Ramas[i]);
            cout << raiz->claves[i + 1] << " " << raiz->nombre[i + 1] << endl;
        }
        ImprimirArbol(raiz->Ramas[raiz->Cuenta]); 
    }
}




////Parte de ELIMINAR

//Tiene como funcion devolver la nueva raiz si la raiz inicial se ha quedado sin claves
void ArbolB::Eliminar(int C1,Pagina_Cliente*& raiz){
	bool Encontrado = false;
	Pagina_Cliente *P = new Pagina_Cliente();
	
	EliminarRegistro(C1, raiz,Encontrado);
		if(!Encontrado){
			cout<< "Elemento no se encuentra en arbol"<<endl;
		}
		else if(raiz->Cuenta == 0){
			P = raiz;
			raiz = raiz->Ramas[0];
			delete P;
		}
}


void ArbolB::EliminarRegistro(int C1, Pagina_Cliente*& raiz, bool Encontrado){
    int K = 0;
    
    if(raiz == NULL){
	
    	cout<<"arbol vacio, llego a debajo de una hoja, no esta en el arbol"<<endl;
        Encontrado= false;// se ha llegado debajo de una hoja, la clave no esta en el arbol
    }else{
     	BuscarNodo(C1,raiz,Encontrado,K);
     	cout<<"Encontrado: "<<Encontrado<<endl;
     	if(Encontrado){
     		if(raiz->Ramas[K-1] == NULL){
     			cout<<"Entra a quitar"<<endl<<endl;
     			Quitar(raiz, K);
			 }else{
			 	cout<<"Entra a sucesor"<<endl<<endl;
			 	Sucesor(raiz, K);
			 	EliminarRegistro(raiz->claves[K], raiz->Ramas[K], Encontrado);
			 	if(!Encontrado){
			 		cout<< "Error en el proceso";
				 }
			 }
		}else{
			cout<<"Entra a EliminarRegistro"<<endl;
		 	EliminarRegistro(C1, raiz->Ramas[K], Encontrado);
		 	
		 	if(raiz->Ramas[K]!=NULL)
		 		if(raiz->Ramas[K]->Cuenta<2){
		 			cout<<"Entra a restablecer1"<<endl;
		 			Restablecer(raiz,K);
				}
		}
	}
}


void ArbolB::Quitar(Pagina_Cliente*& P,int K){
	cout<<"K: "<<K<<endl;
  	for(int J = K+1; J<= P->Cuenta; J++){
  		P->claves[J-1] = P->claves[J];
  		P->Ramas[J-1] = P->Ramas[J];
  		P->nombre[J-1] = P->nombre[J];
  	}
  	P->Cuenta = P->Cuenta-1;
  	cout<<"Sale de Quitar"<<endl;
}

void ArbolB::Sucesor(Pagina_Cliente* P,int K){
  Pagina_Cliente *Q = new Pagina_Cliente();
  
  Q=P->Ramas[K];
  while(Q->Ramas[0]!=NULL)
     Q=Q->Ramas[0]; 
  P->claves[K]=Q->claves[1];
  P->nombre[K]=Q->nombre[1];
}

void ArbolB::Restablecer (Pagina_Cliente*& P,int K){
    if(K>0){ //Tiene hermano izquierdo
        cout<<"K mayor que cero"<<endl;
		if (P->Ramas[K-1]->Cuenta>2){ //Tiene mas claves que el minimo y por tanto puede desplazarse una clave
            cout<<"entra a moverDereha"<<endl;
			MoverDerecha(P,K);
        }else{
        	cout<<"entra a combina"<<endl;
        	Combina(P,K);
        }
    }
    else{//solo tiene hermano derecho
    	cout<<"K menor que cero"<<endl;
        if(P->Ramas[1]->Cuenta>2){
        	cout<<"entra a moverIzquierda"<<endl;
        	//Tiene mas claves que el minimo
        	MoverIzquierda(P,1);
		}else{
			cout<<"entra a combina"<<endl;
			Combina(P,1);
		} 
   }
}




void ArbolB::MoverDerecha(Pagina_Cliente*& P,int K){
  int J;
//     with P.Ramas[K]
    	for(J=P->Ramas[K]->Cuenta; J>=1; J--) {
    		P->Ramas[K]->claves[J+1] = P->Ramas[K]->claves[J];
    		P->Ramas[K]->nombre[J+1] = P->Ramas[K]->nombre[J];
    		P->Ramas[J+1]=P->Ramas[J];
    	}
     P->Ramas[K]->Cuenta=P->Ramas[K]->Cuenta+1;
     P->Ramas[K]->Ramas[1]=P->Ramas[K]->Ramas[0];
     P->Ramas[K]->claves[1]=P->claves[K];
	 P->Ramas[K]->nombre[1] = P->nombre[K];

     P->claves[K]=P->Ramas[K-1]->claves[P->Cuenta];
     P->nombre[K]=P->Ramas[K-1]->nombre[P->Cuenta];
     P->Ramas[K]->Ramas[0]=P->Ramas[K-1]->Ramas[P->Cuenta];
     P->Ramas[K-1]->Cuenta=P->Ramas[K-1]->Cuenta-1;
} 



void ArbolB::MoverIzquierda(Pagina_Cliente*& P,int K){
  int J;
//  with P.Ramas[K-1]// es el nodo con menos claves que el minimo
    P->Ramas[K-1]->Cuenta=P->Ramas[K-1]->Cuenta+1;
    P->Ramas[K-1]->claves[P->Ramas[K-1]->Cuenta]=P->claves[K];
    P->Ramas[K-1]->nombre[P->Ramas[K-1]->Cuenta]=P->nombre[K];
    P->Ramas[K-1]->Ramas[P->Ramas[K-1]->Cuenta]=P->Ramas[K]->Ramas[0] ;
      // baja la clave del nodo padre
//  with P->Ramas[K] // hermano derecho
    P->claves[K]=P->Ramas[K]->claves[1];
	P->nombre[K]=P->Ramas[K]->nombre[1];//sube al nodo padre de la clave 1 del hermano derecho, sustituye a la que bajo
    P->Ramas[0]=P->Ramas[K]->Ramas[1];
    P->Ramas[K]->Cuenta=P->Ramas[K]->Cuenta-1;
    for(J=1; J<=P->Ramas[K]->Cuenta; J++){
    	P->Ramas[K]->claves[J]= P->Ramas[K]->claves[J+1];
    	P->Ramas[K]->nombre[J]= P->Ramas[K]->nombre[J+1];
    	P->Ramas[K]->Ramas[J]=P->Ramas[K]->Ramas[J+1];
    }
}



void ArbolB::Combina(Pagina_Cliente*& P, int K){
//forma un nuevo nodo con el hermano izquierdo la mediana ente el nodo problema y el hermano izquierdo
//situado en el nodo padre y las claves del nodo problema.

  int J;
  Pagina_Cliente *Q = new Pagina_Cliente();
  Q=P->Ramas[K];
//  with P.Ramas[k-1]//hermano izquierdo
    P->Ramas[K-1]->Cuenta=P->Ramas[K-1]->Cuenta+1;
    P->Ramas[K-1]->claves[P->Ramas[K-1]->Cuenta]=P->claves[K];// baja clave mediana desde el nodo padre
    P->Ramas[K-1]->nombre[P->Ramas[K-1]->Cuenta]=P->nombre[K];
	P->Ramas[K-1]->Ramas[P->Ramas[K-1]->Cuenta]=Q->Ramas[0];
    for(J=1; J<=Q->Cuenta; J++){
    	P->Ramas[K-1]->Cuenta=P->Ramas[K-1]->Cuenta+1;
    	P->Ramas[K-1]->claves[P->Ramas[K-1]->Cuenta]=Q->claves[J];
    	P->Ramas[K-1]->nombre[P->Ramas[K-1]->Cuenta]=Q->nombre[J];
    	P->Ramas[K-1]->Ramas[P->Ramas[K-1]->Cuenta]=Q->Ramas[J];
    }
 //Reajustadas las claves y ramas del nodo padre debido a que antes ascendio la clave K
// with P
	for(J= K; J<=P->Cuenta-1; J++){
		P->claves[J]=P->claves[J+1];
		P->nombre[J]=P->nombre[J+1];
    	P->Ramas[J]=P->Ramas[J+1];
  	}
  	P->Cuenta=P->Cuenta-1;
 	delete(Q);
}  

/*
int main() {
    ArbolB* clientes = new ArbolB();
    clientes->InsertarClave(70, "maria", clientes->raiz);
	clientes->InsertarClave(71, "Esteban", clientes->raiz);
    clientes->InsertarClave(72, "Carlos", clientes->raiz);
    clientes->InsertarClave(11, "KUYOG BAZE", clientes->raiz);
    clientes->InsertarClave(12, "JICAPU POTICI", clientes->raiz);
    clientes->InsertarClave(13, "SER XUG", clientes->raiz);
    clientes->InsertarClave(14, "VELU DESE", clientes->raiz);
    clientes->InsertarClave(15, "VUNAW RIPOR", clientes->raiz);
    clientes->InsertarClave(7, "hola13", clientes->raiz);
    clientes->InsertarClave(90, "hola9", clientes->raiz);
	clientes->InsertarClave(10, "Jose", clientes->raiz);
    clientes->InsertarClave(95, "hola95", clientes->raiz);

    
    
    
    clientes->InsertarClave(70, "maria", clientes->raiz);
	clientes->InsertarClave(71, "Esteban", clientes->raiz);
    clientes->InsertarClave(72, "Carlos", clientes->raiz);
    clientes->InsertarClave(11, "KUYOG BAZE", clientes->raiz);
    clientes->InsertarClave(12, "JICAPU POTICI", clientes->raiz);
    clientes->InsertarClave(13, "SER XUG", clientes->raiz);
    clientes->InsertarClave(14, "VELU DESE", clientes->raiz);
    clientes->InsertarClave(15, "VUNAW RIPOR", clientes->raiz);

    
    
   
    clientes->InsertarClave(5, "hola10", clientes->raiz);
    clientes->InsertarClave(6, "hola11", clientes->raiz);
    clientes->InsertarClave(6, "hola12", clientes->raiz);
    clientes->InsertarClave(7, "hola13", clientes->raiz);

    clientes->InsertarClave(8, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(10, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(16, "hola", clientes->raiz);
    clientes->InsertarClave(4, "hola", clientes->raiz);
    clientes->InsertarClave(7, "hola", clientes->raiz);
    clientes->InsertarClave(8, "hola", clientes->raiz);
    clientes->InsertarClave(9, "hola", clientes->raiz);
    clientes->InsertarClave(88, "holatavo", clientes->raiz);
    clientes->InsertarClave(88, "holamundo", clientes->raiz);
    clientes->InsertarClave(10, "hola", clientes->raiz);
    clientes->InsertarClave(15, "hola", clientes->raiz);

	clientes->Search(90,clientes->raiz);
	clientes->Search(15,clientes->raiz);
	clientes->Search(6,clientes->raiz);
	clientes->Search(88,clientes->raiz);
	cout<<"ARBOL ORIGINAL: "<<endl<<endl;
	clientes->ImprimirArbol(clientes->raiz);
	clientes->Eliminar(95, clientes->raiz);
	cout<<"ARBOL despues de eliminar: "<<endl<<endl;
	clientes->ImprimirArbol(clientes->raiz);
	
    delete clientes;
    return 0;
}*/
