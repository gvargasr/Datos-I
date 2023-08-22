#include <iostream>

using namespace std;

class nodo {  //Creacion de la clase nodo

	private:
		nodo *siguiente;
		int valor;

	public:
		
		//Constructores
		nodo(int num) { //Para hacer el primero de la cola
			siguiente = NULL; 
			valor = num; 
		} 
		
		nodo(int num, nodo *puntero) { //Para agregar mas a la cola
			valor = num;
			siguiente = puntero;
		}

	friend class cola; // Enlaza con la clase cola

};

typedef nodo *pnodo; // Alias a los punteros de los nodos

class cola {

	private:
		pnodo primero;
		pnodo ultimo;
	
	public:
		cola() { primero = NULL; ultimo = NULL; };
		void push(int num); // Insertar nodo a la cola
		int pop(); // Extraer nodo de la cola
		void imprimir();

};

void cola::push(int num) { // Insertar nodo a la cola

	if (primero == NULL) { // Primer elemento
		primero = new nodo(num);
		ultimo = primero;
	}
	else { // Resto de elementos
		ultimo = new nodo(num, ultimo);
	}

};

int cola::pop() { // Extraer nodo de la cola
	
	int numero = 0; //No hace falta, es solo para imprimir el numero que sale
	if (primero == NULL) { // No hay elementos
		cout << "La cola esta vacia" << endl;
	}
	else if (ultimo == primero) { // Solo un elemento
		numero = primero -> valor; //No hace falta, es solo para imprimir el numero que sale
		ultimo = NULL;
		primero = NULL;
	}
	else { // 2 o mas elementos
		numero = primero -> valor; //No hace falta, es solo para imprimir el numero que sale
		pnodo aux = ultimo;
		while (aux -> siguiente != primero) {
			aux = aux -> siguiente;
		}
		aux -> siguiente = NULL;
		primero = aux;
		
	}
	return numero;

};

void cola::imprimir() {
	pnodo aux = ultimo;
	while (aux != NULL) {
		cout << aux -> valor << " -> ";
		aux = aux -> siguiente;
	}
	cout << endl;
};


int main() {

	cola nuevaCola;
	nuevaCola.push(1);
	nuevaCola.push(2);
	nuevaCola.push(3);
	nuevaCola.push(4);
	nuevaCola.imprimir();
	cout<< nuevaCola.pop()<<endl;
	nuevaCola.imprimir();
	cout<< nuevaCola.pop()<<endl;
	nuevaCola.imprimir();
	nuevaCola.push(7);
	nuevaCola.imprimir();
	//nuevaCola.imprimir();
	//nuevaCola.imprimir();
	/*nuevaCola.push(5);
	nuevaCola.push(6);
	cout << nuevaCola.pop() << endl;
	cout << nuevaCola.pop() << endl;
	nuevaCola.push(7);
	nuevaCola.push(8);
	nuevaCola.push(9);
	nuevaCola.push(10);
	nuevaCola.imprimir();*/
	
	
	
	return 0;
};
