#include <iostream>
#include <fstream>
#include "AAMenu.h"
#include "RNRest.h"


using namespace std;
/*
class Nodo {
	public:
  int codRest;
  Nodo *padre;
  Nodo *Hizq;
  Nodo *Hder;
  int color;
  int contador;
  string nombreRest;
  AAMenu listaMenu;
  
  friend class ArbolRN;
};

typedef Nodo *NodoPtr;

class ArbolRN {
  public:
  NodoPtr Raiz;
  NodoPtr TNULL;
*/

RNRest::RNRest() {
    TNULL = new Nodo;
    TNULL->color = 0;
    TNULL->Hizq = nullptr;
    TNULL->Hder = nullptr;
    Raiz = TNULL;
}

  void RNRest::initializeNULLNode(NodoPtr nodo, NodoPtr padre) {
    nodo->codRest = 0;
    nodo->padre = padre;
    nodo->Hizq= nullptr;
    nodo->Hder = nullptr;
    nodo->color = 0;
    nodo->contador = 0;
    nodo ->nombreRest = "";
  }
  
  void RNRest::insertarBalanceado(NodoPtr NodoEva) {
    NodoPtr ucodRest;
    cout << "Restaurante " << NodoEva->codRest << ":" << NodoEva->nombreRest << " ha sido agregado." << endl;
    while (NodoEva->padre->color == 1) {
      if (NodoEva->padre == NodoEva->padre->padre->Hder) {
        ucodRest = NodoEva->padre->padre->Hizq;
        if (ucodRest->color == 1) {
          ucodRest->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Hizq) {
            NodoEva = NodoEva->padre;
            RotacionDerecha(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionIzquierda(NodoEva->padre->padre);
        }
      } else {
        ucodRest = NodoEva->padre->padre->Hder;

        if (ucodRest->color == 1) {
          ucodRest->color = 0;
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          NodoEva = NodoEva->padre->padre;
        } else {
          if (NodoEva == NodoEva->padre->Hder) {
            NodoEva = NodoEva->padre;
            RotacionIzquierda(NodoEva);
          }
          NodoEva->padre->color = 0;
          NodoEva->padre->padre->color = 1;
          RotacionDerecha(NodoEva->padre->padre);
        }
      }
      if (NodoEva == Raiz) {
        break;
      }
    }
    Raiz->color = 0;
  }
  
  NodoPtr RNRest::Busqueda(NodoPtr nodo, int numbuscado) {
    if (nodo == TNULL || numbuscado == nodo->codRest) {
      return nodo;
    } else if (nodo->Hizq==nullptr&&nodo->Hder==nullptr&&numbuscado != nodo->codRest){
    	return NULL;
	}

    if (numbuscado < nodo->codRest) {
      return Busqueda(nodo->Hizq, numbuscado);
    }
    return Busqueda(nodo->Hder, numbuscado);
  }
  
  bool RNRest::BusquedaBool(NodoPtr nodo, int numbuscado) {
    if (nodo == TNULL || numbuscado == nodo->codRest) {
      return true;
    } else if (nodo->Hizq==nullptr&&nodo->Hder==nullptr&&numbuscado != nodo->codRest){
    	return false;
	}

    if (numbuscado < nodo->codRest) {
      return BusquedaBool(nodo->Hizq, numbuscado);
    }
    return BusquedaBool(nodo->Hder, numbuscado);
  }
  
  void RNRest::rbModificar(NodoPtr uRaiz, NodoPtr vValor) {
    if (Raiz->padre == nullptr) {
      Raiz = vValor;
    } else if (uRaiz == uRaiz->padre->Hizq) {
      uRaiz->padre->Hizq = vValor;
    } else {
      uRaiz->padre->Hder = vValor;
    }
    vValor->padre = uRaiz->padre;
  }
  
  
  void RNRest::MostrarRN1(NodoPtr raiz, string indent, bool ultimo) {
    if (raiz != TNULL) {
      cout << indent;
      if (ultimo) {
        cout << "Derecha----";
        indent += "   ";
      } else {
        cout << "Izquierda----";
        indent += "|  ";
      }

      string sColor = raiz->color ? "Rojo" : "Negro";
      cout << raiz->codRest << "(" << sColor << ")" << "Nombre:" << raiz->nombreRest << endl;
      MostrarRN1(raiz->Hizq, indent, false);
      MostrarRN1(raiz->Hder, indent, true);
    }
  }
  
    Nodo* RNRest::FindNodeWithHighestContador(NodoPtr root) {
        if (root == TNULL) {
            return nullptr;
        }

        Nodo* maxNode = root;
        if (root->Hizq != TNULL) {
            Nodo* leftMaxNode = FindNodeWithHighestContador(root->Hizq);
            if (leftMaxNode != nullptr && leftMaxNode->contador > maxNode->contador) {
                maxNode = leftMaxNode;
            }
        }
        if (root->Hder != TNULL) {
            Nodo* rightMaxNode = FindNodeWithHighestContador(root->Hder);
            if (rightMaxNode != nullptr && rightMaxNode->contador > maxNode->contador) {
                maxNode = rightMaxNode;
            }
        }
		if(maxNode != NULL){
			cout<<"El Restaurante mas buscado es: "<<maxNode->codRest<<":"<<maxNode->nombreRest<<", buscado "<<maxNode->contador<<" veces."<<endl;
			ofstream archivo_salida("Reporte_Restaurante_Mas_Buscado.txt");
    		if (!archivo_salida.is_open()) {
        		cerr << "No se pudo abrir el archivo." <<endl;
    		}
    		archivo_salida << "\t .:REPORTE RESTAURANTE MAS BUSCADO:."<<endl<<endl<<endl;
    		archivo_salida << "El Restaurante mas buscado es: \nCodigo: "<<maxNode->codRest<<"\nRestaurante: "<<maxNode->nombreRest<<"\nFue buscado "<<maxNode->contador<<" veces."<<endl;
    		archivo_salida.close();
		}
        return maxNode;
    }


void RNRest::PreOrderTraversal(NodoPtr raiz, ofstream& archivo_salida) {
    if (raiz != TNULL) {
        archivo_salida << raiz->codRest << " (" << (raiz->color ? "Rojo" : "Negro") << ") Nombre: " << raiz->nombreRest << endl;
        PreOrderTraversal(raiz->Hizq, archivo_salida);
        PreOrderTraversal(raiz->Hder, archivo_salida);
    }
}

void RNRest::MostrarRN2(NodoPtr raiz, string indent, bool ultimo, string nombre) {
    ofstream archivo_salida("Reporte_Restaurante_" + nombre + ".txt");
    if (!archivo_salida.is_open()) {
        cerr << "No se pudo abrir el archivo." << endl;
    } else {
        archivo_salida << "\t.:REPORTE LISTA RESTAURANTES:." << endl << endl << endl;
        PreOrderTraversal(Raiz, archivo_salida);
        archivo_salida.close();
        cout << "Reporte generado" << endl;
    }
}



  
  void RNRest::RotacionIzquierda(NodoPtr nodo) {
    NodoPtr y = nodo->Hder;
    nodo->Hder = y->Hizq;
    if (y->Hizq != TNULL) {
      y->Hizq->padre = nodo;
    }
    y->padre = nodo->padre;
    if (nodo->padre == nullptr) {
      this->Raiz = y;
    } else if (nodo == nodo->padre->Hizq) {
      nodo->padre->Hizq = y;
    } else {
      nodo->padre->Hder = y;
    }
    y->Hizq = nodo;
    nodo->padre = y;
  }

  void RNRest::RotacionDerecha(NodoPtr nodo) {
    NodoPtr y = nodo->Hizq;
    nodo->Hizq = y->Hder;
    if (y->Hder != TNULL) {
      y->Hder->padre= nodo;
    }
    y->padre = nodo->padre;
    if (nodo->padre == nullptr) {
      this->Raiz = y;
    } else if (nodo == nodo->padre->Hder) {
      nodo->padre->Hder = y;
    } else {
      nodo->padre->Hizq= y;
    }
    y->Hder = nodo;
    nodo->padre = y;
  }

  void RNRest::insertar(int codRestnuevo, string nombrenuevo) {
  	NodoPtr temp = BusquedaMRest(codRestnuevo);
  	if (temp->codRest==codRestnuevo){
  		cout<<"Restaurante: "<<codRestnuevo<<":"<<nombrenuevo<<" no fue agregado"<<endl;
	  }
	  else {
	  	NodoPtr nodo = new Nodo;
    nodo->padre = nullptr;
    nodo->codRest = codRestnuevo;
    nodo->Hizq = TNULL;
    nodo->Hder = TNULL;
    nodo->color = 1;
    nodo->nombreRest = nombrenuevo;

    NodoPtr y = nullptr;
    NodoPtr x = this->Raiz;

    while (x != TNULL) {
      y = x;
      if (nodo->codRest < x->codRest) {
        x = x->Hizq;
      } else {
        x = x->Hder;
      }
    }

    nodo->padre = y;
    if (y == nullptr) {
      Raiz = nodo;
    } else if (nodo->codRest< y->codRest) {
      y->Hizq = nodo;
    } else {
      y->Hder = nodo;
    }

    if (nodo->padre== nullptr) {
    	cout << "Restaurante " << codRestnuevo << ":" << nombrenuevo << " ha sido agregado." << endl;
      	nodo->color = 0;
      	return;
    }

    if (nodo->padre->padre == nullptr) {
    	cout << "Restaurante " << codRestnuevo << ":" << nombrenuevo << " ha sido agregado." << endl;
      	return;
    }

    insertarBalanceado(nodo);
	  }
  }

  void RNRest::insertarBus(int codRestnuevo, string nombrenuevo) {
  	NodoPtr temp = BusquedaMRest(codRestnuevo);
  	if (temp->codRest==codRestnuevo){
  	//	cout<<"Restaurante: "<<codRestnuevo<<":"<<nombrenuevo<<" no fue agregado"<<endl;
	  }
	  else {
	  	NodoPtr nodo = new Nodo;
    nodo->padre = nullptr;
    nodo->codRest = codRestnuevo;
    nodo->Hizq = TNULL;
    nodo->Hder = TNULL;
    nodo->color = 1;
    nodo->nombreRest = nombrenuevo;

    NodoPtr y = nullptr;
    NodoPtr x = this->Raiz;

    while (x != TNULL) {
      y = x;
      if (nodo->codRest < x->codRest) {
        x = x->Hizq;
      } else {
        x = x->Hder;
      }
    }

    nodo->padre = y;
    if (y == nullptr) {
      Raiz = nodo;
    } else if (nodo->codRest< y->codRest) {
      y->Hizq = nodo;
    } else {
      y->Hder = nodo;
    }

    if (nodo->padre== nullptr) {
    //	cout << "Restaurante " << codRestnuevo << ":" << nombrenuevo << " ha sido agregado." << endl;
      	nodo->color = 0;
      	return;
    }

    if (nodo->padre->padre == nullptr) {
    //	cout << "Restaurante " << codRestnuevo << ":" << nombrenuevo << " ha sido agregado." << endl;
      	return;
    }

    insertarBalanceado(nodo);
	  }
  }

  NodoPtr RNRest::getRaiz() {
    return this->Raiz;
  }
  
  NodoPtr RNRest::BusquedaMRest(int numbuscado) {
    return Busqueda(this->Raiz, numbuscado);
  }
  
  void RNRest::MostrarRN() {
    if (Raiz) {
      MostrarRN1(this->Raiz, "", true);
    }
  }
  
    void RNRest::MostrarRN3(string nombre) {
    if (Raiz) {
      MostrarRN2(this->Raiz, "", true, nombre);
    }
        cout << "Reporte generado"<<endl<<endl<<endl;

  }
  
  bool RNRest::BusquedaB(int numbuscado) {
    return BusquedaBool(this->Raiz, numbuscado);
  }

  void RNRest::ModificarNodo(int numbusqueda, string nuevonom)
  {
  	NodoPtr aux = BusquedaMRest(numbusqueda);
  	if (aux->codRest!=numbusqueda){
  		cout<<"Codigo Invalido"<<endl;
	  } else {	
 	 	string tempnom;
  		tempnom = aux->nombreRest;
  		aux->nombreRest = nuevonom;
  		cout<<"El restaurante fue modificado"<<endl;
		cout<<"Anterior: "<<numbusqueda<<":"<<tempnom<<endl;
		cout<<"Nuevo: "<<numbusqueda<<":"<<aux->nombreRest<<endl;	  }
	}

	
	Nodo* RNRest::BuscarNodo (int numbusqueda){
	NodoPtr aux = BusquedaMRest(numbusqueda);
  	if (aux->codRest!=numbusqueda){
  		cout<<"Restaurante "<<numbusqueda<<" no se encuentra."<<endl;
  		return NULL;
	  } else {
	  	aux->contador++;
		cout<<"\n.:Restaurante encontrado:."<<endl;
		cout<<"- Codigo: "<<aux->codRest<<endl;
		cout<<"- Nombre: "<<aux->nombreRest<<endl;
		return aux;
	  }
  	}
  	
  	Nodo* RNRest::BuscarNodoBus (int numbusqueda){
	NodoPtr aux = BusquedaMRest(numbusqueda);
  	if (aux->codRest!=numbusqueda){
  	//	cout<<"Restaurante "<<numbusqueda<<" no se encuentra."<<endl;
  		return NULL;
	  } else {
	  	aux->contador++;
	//	cout<<"Restaurante encontrado:"<<endl;
	//	cout<<"- Codigo: "<<aux->codRest<<endl;
	//	cout<<"- Nombre: "<<aux->nombreRest<<endl;
		return aux;
	  }
  	}

void RNRest::ArregloBorrar(NodoPtr Nodo) {
    NodoPtr NodoAux;
    while (Nodo != this->Raiz && Nodo->color == 0) {
      if (Nodo == Nodo->padre->Hizq) {
        NodoAux = Nodo->padre->Hder;
        if (NodoAux->color == 1) {
          NodoAux->color = 0;
          Nodo->padre->color = 1;
          RotacionIzquierda(Nodo->padre);
          NodoAux = Nodo->padre->Hder;
        }

        if (NodoAux->Hizq->color == 0 && NodoAux->Hder->color == 0) {
          NodoAux->color = 1;
          Nodo = Nodo->padre;
        } else {
          if (NodoAux->Hder->color == 0) {
            NodoAux->Hizq->color = 0;
            NodoAux->color = 1;
            RotacionDerecha(NodoAux);
            NodoAux = Nodo->padre->Hder;
          }

          NodoAux->color = Nodo->padre->color;
          Nodo->padre->color = 0;
          NodoAux->Hder->color = 0;
          RotacionIzquierda(Nodo->padre);
          Nodo = this->Raiz;
        }
      } else {
        NodoAux = Nodo->padre->Hizq;
        if (NodoAux->color == 1) {
          NodoAux->color = 0;
          Nodo->padre->color = 1;
          RotacionDerecha(Nodo->padre);
          NodoAux = Nodo->padre->Hizq;
        }

        if (NodoAux->Hder->color == 0 && NodoAux->Hizq->color == 0) {
          NodoAux->color = 1;
          Nodo = Nodo->padre;
        } else {
          if (NodoAux->Hizq->color == 0) {
            NodoAux->Hder->color = 0;
            NodoAux->color = 1;
            RotacionIzquierda(NodoAux);
            NodoAux = Nodo->padre->Hizq;
          }

          NodoAux->color = Nodo->padre->color;
          Nodo->padre->color = 0;
          NodoAux->Hizq->color = 0;
          RotacionDerecha(Nodo->padre);
          Nodo = this->Raiz;
        }
      }
    }
    Nodo->color = 0;
  }
  
  void RNRest::AsistenteBorrarNodo(NodoPtr Nodo, int codBorrar) {
    NodoPtr Nodo_z = TNULL;
    NodoPtr Nodo_x, Nodo_y;
    while (Nodo != TNULL) {
      if (Nodo->codRest == codBorrar) {
        Nodo_z = Nodo;
      }

      if (Nodo->codRest <= codBorrar) {
        Nodo = Nodo->Hder;
      } else {
        Nodo = Nodo->Hizq;
      }
    }

    if (Nodo_z == TNULL) {
      cout << "Codigo no encontrado en el arbol" << endl;
      return;
    }

    Nodo_y = Nodo_z;
    int ColorY = Nodo_y->color;
    if (Nodo_z->Hizq == TNULL) {
      Nodo_x = Nodo_z->Hder;
      rbModificar(Nodo_z, Nodo_z->Hder);
    } else if (Nodo_z->Hizq == TNULL) {
      Nodo_x = Nodo_z->Hizq;
      rbModificar(Nodo_z, Nodo_z->Hizq);
    } else {
      Nodo_y = minimo(Nodo_z->Hder);
      ColorY = Nodo_y->color;
      Nodo_x = Nodo_y->Hder;
      if (Nodo_y->padre == Nodo_z) {
        Nodo_x->padre = Nodo_y;
      } else {
        rbModificar(Nodo_y, Nodo_y->Hder);
        Nodo_y->Hder = Nodo_z->Hder;
        Nodo_y->Hder->padre = Nodo_y;
      }

      rbModificar(Nodo_z, Nodo_y);
      Nodo_y->Hizq = Nodo_z->Hder;
      Nodo_y->Hizq->padre = Nodo_y;
      Nodo_y->color = Nodo_z->color;
    }
    delete Nodo_z;
    if (ColorY == 0) {
      ArregloBorrar(Nodo_x);
    }
  }
  
  void RNRest::borrarNodo(int codBorrar) {
    AsistenteBorrarNodo(this->Raiz, codBorrar);
  }
  
  NodoPtr RNRest::minimo(NodoPtr nodo) {
    while (nodo->Hizq != TNULL) {
      nodo = nodo->Hizq;
    }
    return nodo;
  }
  

