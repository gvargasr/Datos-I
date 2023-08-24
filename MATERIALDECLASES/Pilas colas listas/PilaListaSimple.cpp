#include <iostream>
using namespace std;
#include "listaSimple.cpp"

class pilaLS: private lista {
	public:
		void Pop(){
			lista::BorrarInicio();
		}
		void Push(int v){
			lista::InsertarInicio(v);
		}
		void MostrarPila(){
			lista::Mostrar();
		}
		bool PilaVacia(){
			if(lista::ListaVacia())
			cout<<"Esta vacia"<<endl;
		}
	
};



int main(){
	pilaLS pilals;
	pilals.PilaVacia();
	pilals.Push(20);
	pilals.Push(21);
	pilals.Push(62);
	pilals.Push(42);
	pilals.Push(78);
	pilals.Push(31);
	pilals.MostrarPila();
	pilals.Pop();
	pilals.MostrarPila();
	pilals.Pop();
	pilals.MostrarPila();
	pilals.Push(69);
	pilals.MostrarPila();


}

