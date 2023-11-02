#include <iostream>
#include <fstream>
#include "AAMenu.h"
#include "AVLProducto.h"
using namespace std;
/*
class NodoM {
public:
  int codMenu;
  int nivel;
  int contador;
  NodoM *Hizq;
  NodoM *Hder;
  string nombreMenu;
  AVLProducto listaProducto;

  friend class ArbolA;
};

typedef NodoM *NodoMPtr;

class ArbolA {
  public:
  NodoMPtr Raiz;
  NodoMPtr TNULL;*/

AAMenu::AAMenu() {
	TNULL = new NodoM;
	TNULL->nivel = 0;
	TNULL->codMenu = 0;
	TNULL->contador = 0;
	TNULL->Hizq = nullptr;
	TNULL->Hder = nullptr;
	Raiz = TNULL;
}
  
 void AAMenu::IniciarNodoNULL(NodoMPtr NodoMenu) {
    NodoMenu->codMenu = 0;
    NodoMenu->contador = 0;
    int nivel;
    NodoMenu->Hizq= nullptr;
    NodoMenu->Hder = nullptr;
    NodoMenu ->nombreMenu = "";
  }

  NodoMPtr AAMenu::Busqueda(NodoMPtr NodoMenu, int numbuscado) {
    if (NodoMenu == NULL || NodoMenu->codMenu == 0 ||numbuscado == NodoMenu->codMenu) {
      return NodoMenu;
    }
    if (numbuscado < NodoMenu->codMenu) {
      return Busqueda(NodoMenu->Hizq, numbuscado);
    }
    return Busqueda(NodoMenu->Hder, numbuscado);
  }
  
  

  
  
	
	void AAMenu::BuscarNodoMenu (int numbusqueda){
	NodoMPtr aux = BusquedaM(numbusqueda);
  	if (aux->codMenu!=numbusqueda){
  		cout<<"Menu "<<numbusqueda<<" no se encuentra."<<endl;
	  } else {
	  	aux->contador++;
		cout<<"\n.:Menu encontrado:."<<endl;
		cout<<"- Codigo: "<<aux->codMenu<<endl;
		cout<<"- Nombre: "<<aux->nombreMenu<<endl;
	  }
  	}
  	
  		NodoMPtr AAMenu::BuscarNodoMenu1 (int numbusqueda){
			NodoMPtr aux = BusquedaM(numbusqueda);
  			if (aux->codMenu!=numbusqueda){
  				return NULL;
			  } else {
			  	return aux;
		  }
  	}
  	
  	  		NodoMPtr AAMenu::BuscarNodoMenu2 (int numbusqueda){
			NodoMPtr aux = BusquedaM(numbusqueda);
  			if (aux->codMenu!=numbusqueda){
  				return NULL;
			  } else {
			  	aux->contador++;
			  	return aux;
		  }
  	}

  void AAMenu::Giro(NodoMPtr NodoMenu, NodoMPtr x, NodoMPtr z){
		if (x == TNULL){
			Raiz = NodoMenu;
		}else if (NodoMenu->codMenu < x->codMenu){
			NodoMenu->Hder = x;
			if (z->Hizq == x){
				z->Hizq = NodoMenu;
			} else if (z->Hder == x){
				z->Hder = NodoMenu;
			} else {
				Raiz = NodoMenu;
			}
		} else if (NodoMenu->codMenu < x->Hder->codMenu) {
			NodoMenu->Hder = x->Hder;
			x->Hder = NodoMenu;
		} else {
			x->Hder = NodoMenu;
		}
		
	}
	
	void AAMenu::Reparto(NodoMPtr NodoMenu, NodoMPtr Der, NodoMPtr Izq){
		if (NodoMenu == TNULL){
			
		} else {
			Reparto(NodoMenu->Hizq, NodoMenu,nullptr);
			if (NodoMenu->Hder != TNULL){
				if (NodoMenu->Hder->nivel == NodoMenu->nivel){
				Reparto(NodoMenu->Hder->Hder, nullptr,NodoMenu->Hder);
				Reparto(NodoMenu->Hder->Hizq, NodoMenu,NodoMenu->Hder);
			} else {
				Reparto(NodoMenu->Hder, nullptr,NodoMenu);
			}
			}
			NodoMPtr NodoMenuaux = NodoMenu->Hder;
			int NodoMenunivel = NodoMenu->nivel;
			int NodoMenumax= Raiz->nivel;
			if (NodoMenu->Hizq != TNULL && NodoMenu->Hder != TNULL){
				if(NodoMenuaux->Hder->nivel == NodoMenunivel){
					
				NodoMenuaux->nivel = NodoMenuaux->nivel + 1;
				NodoMenu->Hder = NodoMenuaux->Hizq;
				NodoMenuaux->Hizq = NodoMenu;
			if (Der == nullptr){
				Izq -> Hder = NodoMenuaux;
			} else if (Izq == nullptr){
				NodoMenuaux->Hder = Der;
				this->Raiz = NodoMenuaux;
			} else if (Izq == nullptr && Der == nullptr){
				this->Raiz = NodoMenuaux;
			} else {
				Der->Hder = NodoMenuaux;
				NodoMenuaux->Hizq = Izq;
			}
				
			}

			} else if (NodoMenunivel==NodoMenumax && NodoMenuaux != TNULL && NodoMenuaux->Hder != TNULL) {
				if(NodoMenuaux->Hder->nivel == NodoMenunivel){
				NodoMenuaux->nivel = NodoMenuaux->nivel + 1;
				NodoMenu->Hder = NodoMenuaux->Hizq;
				NodoMenuaux->Hizq = NodoMenu;
				this->Raiz = NodoMenuaux;
			} 
			}else if (NodoMenunivel==0 && NodoMenuaux != TNULL && NodoMenuaux->Hder != TNULL){
				NodoMenuaux->nivel = NodoMenuaux->nivel + 1;
				if (Der == nullptr){
				Izq -> Hder = NodoMenuaux;
			} else if (Izq == nullptr){
				NodoMenuaux->Hder = Der;
				this->Raiz = NodoMenuaux;
			} else if (Izq == nullptr && Der == nullptr){
				this->Raiz = NodoMenuaux;
			} else {
				Der->Hder = NodoMenuaux;
				NodoMenuaux->Hizq = Izq;
			}
				NodoMenu->Hder = NodoMenuaux->Hizq;
				NodoMenuaux->Hizq = NodoMenu;
			} 
		}
	}
  
  NodoMPtr AAMenu::BusquedaM(int numbuscado) {
    return Busqueda(this->Raiz, numbuscado);
  }
  
  
  
  void AAMenu::insertar(int codMenunuevo, string nombrenuevo) {
  	NodoMPtr temp = BusquedaM(codMenunuevo);
  	if (temp->codMenu==codMenunuevo){
    cout <<"Menu: "<<codMenunuevo<<":"<<nombrenuevo<<" no fue agregado"<<endl;
	  }
	  else {
	cout << "Menu " << codMenunuevo << ":" << nombrenuevo << " ha sido agregado." << endl;
	NodoMPtr NodoMenu = new NodoM;
    NodoMenu->codMenu = codMenunuevo;
    int nivel = 0;
    NodoMenu->Hizq= TNULL;
    NodoMenu->Hder = TNULL;
    NodoMenu ->nombreMenu = nombrenuevo;
    
	NodoMPtr y = this->Raiz;
    NodoMPtr x = this->Raiz;
    NodoMPtr z = nullptr;

    while (x != TNULL) {
      z = y;
	  y = x;
      if (NodoMenu->codMenu < x->codMenu) {
			x = x->Hizq;
      } else {
		  	x = x->Hder;
		  }
      }
	  Giro(NodoMenu, y,z);
	  Reparto(this->Raiz,nullptr,nullptr);
    }
}

void AAMenu::BorrarNodo(int codMenuBorrar){
	AAMenu Temp;
	cout<<"pre postorden"<<endl;
	Temp.postordenNuevoArbol(this->Raiz,codMenuBorrar);
	this->Raiz = Temp.Raiz;
	cout<<"El codigo: "<<codMenuBorrar<<" se borro"<<endl;
}

void AAMenu::postordenNuevoArbol(NodoMPtr NodoMenu, int codBorrar) {
	cout<<"postorden"<<endl<<"Nodo: "<<NodoMenu->codMenu<<endl;
	if (NodoMenu!=TNULL && NodoMenu->codMenu!=0) {
		if (NodoMenu->codMenu != codBorrar){
			cout<<"Entra a insertar"<<endl;
		postordenNuevoArbol(NodoMenu->Hizq, codBorrar);
		postordenNuevoArbol(NodoMenu->Hder, codBorrar);
		this->insertarnodo(NodoMenu);
		} else {
			cout<<"Entra a borrar"<<endl;
		postordenNuevoArbol(NodoMenu->Hizq, codBorrar);
		postordenNuevoArbol(NodoMenu->Hder, codBorrar);
		}
	}
	
}

void AAMenu::insertarnodo(NodoMPtr NodoInsertado){
	NodoMPtr NodoMenu = new NodoM;
    NodoMenu->codMenu = NodoInsertado->codMenu;
    int nivel = 0;
    NodoMenu->Hizq= TNULL;
    NodoMenu->Hder = TNULL;
    NodoMenu ->nombreMenu = NodoInsertado->nombreMenu;
    NodoMenu->listaProducto = NodoInsertado->listaProducto;
    
	NodoMPtr y = this->Raiz;
    NodoMPtr x = this->Raiz;
    NodoMPtr z = nullptr;

    while (x != TNULL) {
      z = y;
	  y = x;
      if (NodoMenu->codMenu < x->codMenu) {
			x = x->Hizq;
      } else {
		  	x = x->Hder;
		  }
      }
	  Giro(NodoMenu, y,z);
	  Reparto(this->Raiz,nullptr,nullptr);
    }


void AAMenu::postorden(NodoMPtr NodoMenu, std::ofstream& file) {
    if (NodoMenu != TNULL) {
        file <<"Nombre: "<< NodoMenu->nombreMenu<<"\n"<<"Codigo: "<<NodoMenu->codMenu <<"\n\n";
        file <<"###############################"<<endl;
        preOrden(NodoMenu->Hizq, file);
        preOrden(NodoMenu->Hder, file);
    }
}

  void AAMenu::insertarBus(int codMenunuevo, string nombrenuevo) {
  	NodoMPtr temp = BusquedaM(codMenunuevo);
  	if (temp->codMenu==codMenunuevo){
 //   cout <<"Menu: "<<codMenunuevo<<":"<<nombrenuevo<<" no fue agregado"<<endl;
	  }
	  else {
//	cout << "Menu " << codMenunuevo << ":" << nombrenuevo << " ha sido agregado." << endl;
	NodoMPtr NodoMenu = new NodoM;
    NodoMenu->codMenu = codMenunuevo;
    int nivel = 0;
    NodoMenu->Hizq= TNULL;
    NodoMenu->Hder = TNULL;
    NodoMenu ->nombreMenu = nombrenuevo;
    
	NodoMPtr y = this->Raiz;
    NodoMPtr x = this->Raiz;
    NodoMPtr z = nullptr;

    while (x != TNULL) {
      z = y;
	  y = x;
      if (NodoMenu->codMenu < x->codMenu) {
			x = x->Hizq;
      } else {
		  	x = x->Hder;
		  }
      }
	  Giro(NodoMenu, y,z);
	  Reparto(this->Raiz,nullptr,nullptr);
    }
}



  
void AAMenu::preOrden(NodoMPtr NodoMenu, std::ofstream& file) {
    if (NodoMenu != TNULL) {
        file <<"Nombre: "<< NodoMenu->nombreMenu<<"\n"<<"Codigo: "<<NodoMenu->codMenu <<"\n\n";
        file <<"###############################"<<endl;
        preOrden(NodoMenu->Hizq, file);
        preOrden(NodoMenu->Hder, file);
    }
}

void AAMenu::generateReport(NodoMPtr NodoMenu, string nomRest) {
    std::ofstream file;
    file.open("Reporte_Menu_" + nomRest + ".txt"); 
    file << "\t .:REPORTE LISTA DE MENUS:."<<endl<<endl<<endl;
    preOrden(NodoMenu, file); 
    file.close();
}
  
  
NodoMPtr AAMenu::findMaxContador(NodoMPtr root) {
    NodoMPtr maxNode = root;
    NodoMPtr leftNode = nullptr;
    NodoMPtr rightNode = nullptr;

    if (root != TNULL) {
        leftNode = findMaxContador(root->Hizq);
        rightNode = findMaxContador(root->Hder);

        if (leftNode != TNULL && leftNode->contador > maxNode->contador) {
            maxNode = leftNode;
        }
        if (rightNode != TNULL && rightNode->contador > maxNode->contador) {
            maxNode = rightNode;
        }
    
    cout<<"El Menu mas buscado es: "<<maxNode->codMenu<<":"<<maxNode->nombreMenu<<", buscado "<<maxNode->contador<<" veces."<<endl;
	ofstream archivo_salida("Reporte_Menu_Mas_Buscado.txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
    archivo_salida << "\t .:REPORTE MENU MAS BUSCADO:."<<endl<<endl<<endl;
    archivo_salida << "El Menu mas buscado es: \nCodigo: "<<maxNode->codMenu<<"\nMenu: "<<maxNode->nombreMenu<<"\nFue buscado "<<maxNode->contador<<" veces."<<endl;
    archivo_salida.close();
    }
    return maxNode;
}	

	

/*

int main() {
	AAMenu AA;
  AA.insertar(1, "Macdonal");
  AA.insertar(32, "Bk");
  AA.insertar(8, "Papa Johns");
  AA.insertar(90, "Sub");
  AA.insertar(12, "Smash");  
  AA.BorrarNodo(8);
  AA.BuscarNodoMenu(8);
  AA.BuscarNodoMenu(1);
  AA.BuscarNodoMenu(32);
  AA.BuscarNodoMenu(90);
  AA.BuscarNodoMenu(12);
}

*/
