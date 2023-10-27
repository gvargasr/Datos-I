//Tarea 3

// 1. Buscar un numero en una lista.

bool lista::buscarNumero(int v){
	if(ListaVacia()){
		cout<<"El numero "<<v<<" no se encuentra en la lista"<<endl;
		return false;
	}
	else
	{
		pnodo aux=primero;
		while(aux!=NULL)
		{
			if(aux->valor == v){
			cout<<"El numero "<<v<<" si se encuentra en la lista."<<endl;
			return true;
		}
			else
			aux=aux->siguiente;
		}
		cout<<"El numero "<<v<<" no se encuentra en la lista"<<endl;
		return false;
	}
}

// 3. Sumar 2 listas del mismo tamano.

void lista::sumarListasIguales(lista a, lista b){
	pnodo& aux = a.primero;
	pnodo& temp = b.primero;
	if(a.largoLista() != b.largoLista()){
		cout<<"Solo suma listas de igual tamano"<<endl;
	}
	else{
		while(aux !=NULL){
			InsertarFinal(aux->valor+temp->valor);
			aux=aux->siguiente;
			temp=temp->siguiente;
		}
		cout<<"Suma terminada"<<endl;	
		delete aux;
		delete temp;
	}
	

}

//5. Recibe numero, los pone en lista y cuenta los pares.
void lista::contarPares(int num){
	
	if (num == 0)
		cout <<"El numero tiene 1 numero par"<<endl;
	else
	{
		while(num!=0)
		{
			int temp =num%10;
			InsertarInicio(temp);
			num=num/10;
		}
		int pares=0;
		pnodo aux=primero;
		while(aux !=NULL)
		{
			if(aux->valor%2 ==0)
			{
				pares++;
				aux=aux->siguiente;
			}
			else
			aux=aux->siguiente;
		}
		cout<<"\nEl numero ingresado tiene: "<<pares<<" numeros pares"<<endl;
	}
}

//7. Escribir una función que recibe dos números de igual tamaño, 
//   se insertan en dos listas y se suman. Los nodos, dejando una lista nueva

void lista::suma2Num(int v1, int v2){
	lista *L1 = new lista();
	lista *L2 = new lista();
	lista *L3 = new lista();
	if(v1==0){
		cout<<"v1 = 0 Suma finalizada"<<endl;
		L3->InsertarInicio(v1+v2);
		
	}
	else
	{
		while(v1!=0)
		{
			int temp =v1%10;
			int temp2 =v2%10;
			L1->InsertarInicio(temp);
			L2->InsertarInicio(temp2);
			v1=v1/10;
			v2=v2/10;
		}
		pnodo aux=L1->primero;
		pnodo aux2=L2->primero;
		while(aux!=NULL)
		{
			L3->InsertarFinal(aux->valor+aux2->valor);
			aux=aux->siguiente;
			aux2=aux2->siguiente;
		}
		cout<<"Lista 1: "<<endl;
		L1->Mostrar();
		cout<<"Lista 2: "<<endl;
		L2->Mostrar();
		cout<<"Lista 3: "<<endl;
		L3->Mostrar();
		delete aux;
		delete aux2;
	}
}