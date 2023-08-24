#include <iostream>
using namespace std;
#include "listaSimple.cpp"

class QueueLS: private lista {
	public:
		void dequeue(){
			lista::BorrarInicio();
		}
		void enqueue(int v){
			lista::InsertarFinal(v);
		}
		void Mostrar(){
			lista::Mostrar();
		}
		bool QueueLSVacia(){
			if(lista::ListaVacia())
			cout<<"Esta vacia"<<endl;
		}
	
};



int main(){
	
	QueueLS queue;
	queue.QueueLSVacia();
	queue.enqueue(27);
	queue.enqueue(55);
	queue.enqueue(10);
	queue.enqueue(54);
	queue.enqueue(78);
	queue.enqueue(63);
	queue.enqueue(26);
	queue.dequeue();
	queue.enqueue(77);
	queue.Mostrar();
	queue.QueueLSVacia();

}

