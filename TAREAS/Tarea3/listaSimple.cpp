#include <iostream>
using namespace std;

class nodo { // Constructores
   public:
   	
   	
nodo(int v)//3
    {
       valor = v;
       siguiente = NULL;
    }

nodo(int v, nodo  *signodo)
    {
       valor = v;
       siguiente = signodo;
    }


   private:
    int valor=0;
    nodo *siguiente;// Clase Autoreferencia
    
        
   friend class lista;
};

typedef nodo *pnodo; //Alias

//void no retorna nada
//bool retorna False o True
//int retorna entero

class lista {
   public:
    lista() { primero =  NULL; }//constructor
    ~lista();//destructor
    bool buscarNumero(int v);
    void InsertarInicio(int v);//No retornan nada
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    void sumaNum(int num);
    int largoLista();// retorno un valor numerico
    void contarPares(int num);
    void promedio(int num);
    void sumarListasIguales(lista a, lista b);
    void suma2Num(int v1, int v2);
    bool buscarPosicion(int pos);
    int buscarPosicionValor(int pos);
    void sumarListasDiferentes(lista& a, lista& b);
    void procesarParesImpares(int num);
    void elevarParesImpares(int num);
    void crearListaNum(int a);
	void enlazarListas(int a, int b);
	void sumarCentro(int a);
	

    
   private:
    pnodo primero;
   
};

lista::~lista()
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
   primero= NULL;
}

int lista::largoLista(){
    int cont=0;

    pnodo aux= primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    cout<< endl;
    }
    
}

void lista::InsertarInicio(int v)//3 10 265
{
   if (ListaVacia())
   {
   
     primero = new nodo(v);//6
     
   }
   else
   {
     //primera forma
 //  primero=new nodo (v,primero);
    //segunda forma
    pnodo nuevo=new nodo(v);
    nuevo->siguiente=primero;
    primero=nuevo;
     
    
    
     
   }
}
 
void lista::InsertarFinal(int v)//76
{
   if (ListaVacia())
     primero = new nodo(v);
   else
      { 
      //primera forma
	    //pnodo aux = primero;
      //  while ( aux->siguiente != NULL)
      //   aux= aux->siguiente;
      //  aux->siguiente=new nodo(v);
       
       //segunda forma 
       pnodo aux = primero;
        while ( aux->siguiente != NULL)
         aux= aux->siguiente;
        pnodo nuevo=new nodo(v);
        aux->siguiente=nuevo;
      }    
}


void lista::InsertarPos(int v,int pos)
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1)
		{
        	//OPcion1
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
          //OPcion 2
          //InsertarInicio(v);
        }      
        else{
             nodo *aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;;
            }
			 else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) 
		{   pnodo temp=primero;
		    primero= NULL;
		    delete temp;
        } 
		else 
		{

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
        }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1)
		{
        	pnodo temp=primero;
        	primero=primero->siguiente;
        	delete temp; //BorrarInicio();
        }
		else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            pnodo temp=aux->siguiente;
            aux->siguiente=aux->siguiente->siguiente;
            delete temp;
            }
        }
     }

}
 

void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos AQUI"<<endl;  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }	
}


 void lista::sumaNum(int num)//23456
{
   if (num == 0)
      cout << "Suma igual a 0";
   else
   {
   
       while (num!=0)
       {
	   
	     int temp=num%10;
		 InsertarInicio(temp);
		 num=num/10;
       }
      int suma=0;
      pnodo aux=primero; 
      while(aux !=NULL)
      {
      	suma=suma+aux->valor;
      	aux=aux->siguiente;
	  }
	  cout<<suma<<endl;
   }
	
}

//TAREA #2
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
void lista::promedio(int num){
	
	if(num==0)
		cout<<0<<endl;
	else
	{
		while(num!=0)
		{
			int temp =num%10;
			InsertarInicio(temp);
			num=num/10;
		}
		pnodo aux=primero;
		int cant = 0;
		float suma =0;
		while(aux!=NULL)
		{
			suma=suma+aux->valor;
			cant=cant+1;
			aux=aux->siguiente;
		}
		suma=suma/cant;
		cout<<suma<<endl;
	}
}

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

//2. Escribir una función para buscar un número en una posición especifica

bool lista:: buscarPosicion(int pos){
    if(ListaVacia()){
              cout << "Lista vacia" <<endl;
              return false;
    }else{
		if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        return false;
        }
		else{
			pnodo aux=primero;
			while(pos > 1){
				aux=aux->siguiente;
				pos -= 1;
			}
			cout<<"El valor de la posicion solicitada es: "<<aux->valor<<endl;
			return true;
        }
     }

}

int lista:: buscarPosicionValor(int pos){
    if(ListaVacia()){
              cout << "Lista vacia" <<endl;
              return -1;
    }else{
		if((pos>largoLista())||(pos<0)){
			
        cout << "Error en posicion" << endl;
        return false;
        }
		else{
			pnodo aux=primero;
			while(pos > 1){
				aux=aux->siguiente;
				pos = pos-1;
			}
			return aux->valor;
        }
     }

}

// 3. Sumar 2 listas del mismo tamano.

void lista::sumarListasIguales(lista a, lista b){
	pnodo &aux = a.primero;
	pnodo &temp = b.primero;
	if(a.largoLista() != b.largoLista()){
		cout<<"Solo suma listas de igual tamano"<<endl;
		return;
	}
	else{
		while(aux !=NULL){
			InsertarFinal(aux->valor+temp->valor);
			aux=aux->siguiente;
			temp=temp->siguiente;
		}
		cout<<"Suma terminada"<<endl;	
	}
	

}
//4. Escribir una función para sumar dos listas de diferente tamaño

void lista::sumarListasDiferentes(lista& a, lista& b){
	pnodo& auxA = a.primero;
	pnodo& auxB = b.primero;
		while(auxA != NULL || auxB != NULL){
			InsertarFinal(auxA->valor+auxB->valor);
			auxA=auxA->siguiente;
			auxB=auxB->siguiente;
		}
		if (auxA->siguiente == NULL) {
			while(auxB !=NULL){
			InsertarFinal(auxB->valor);
			auxB=auxB->siguiente;
			}
		} else {
			while(auxA !=NULL){
			InsertarFinal(auxA->valor);
			auxA=auxA->siguiente;
			}
		}
		delete auxA;
		delete auxB;
}


//5. Recibe numero, los pone en lista y cuenta los pares.


//6. Recibe un numero, lo separa en una lista y los pares se suman los impares se multiplican.
void lista::procesarParesImpares(int num){
	if (num == 0)
		cout <<"Suma = 0 Multiplicacion = 0"<<endl;
	else
	{
		while(num!=0)
		{
			int temp =num%10;
			InsertarInicio(temp);
			num=num/10;
		}
		int suma=0;
		int multiplicacion=1;
		pnodo aux=primero;
		while(aux !=NULL)
		{
			if(aux->valor%2 ==0)
			{
				suma=suma+aux->valor;
				aux=aux->siguiente;
			}
			else
				multiplicacion=multiplicacion*aux->valor;
				aux=aux->siguiente;
		}
		cout<<"Suma = "<<suma<<"Multiplicacion = "<<multiplicacion<<endl;
	}
}



//7. Escribir una funcion que recibe dos numeros de igual tamaño, 
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

void lista::crearListaNum(int a){
	while (a!=0){	   
	     int temp=a%10;
		 InsertarInicio(temp);
		 a=a/10;
       }
}

// 8. Recibe un numero, lo separa en una lista y
//los dÃ­gitos pares se elevan a la 3 y los impares a la dos.
void lista::elevarParesImpares(int num){
		while(num!=0)
		{
			int temp =num%10;
			InsertarInicio(temp);
			num=num/10;
		}
		pnodo aux=primero;
		while(aux !=NULL)
		{
			if(aux->valor%2 ==0)
			{
				aux->valor = aux->valor*aux->valor*aux->valor;
				aux=aux->siguiente;
			}
			else
				aux->valor = aux->valor*aux->valor;
				aux=aux->siguiente;
		}
	}


//usan crearListaNum
void lista::enlazarListas(int a,int b) {
	lista *L1 = new lista();
	lista *L2 = new lista();
	L1->crearListaNum(a);
	L2->crearListaNum(b);
	cout<<"\nLista 1: "<<endl;
    L1->Mostrar();
    cout<<"\nLista 2: "<<endl;
	L2->Mostrar();  
	pnodo aux = L1->primero;
	pnodo aux2 = L2->primero;
	pnodo aux3 = L1->primero->siguiente;
	while(aux->siguiente->siguiente!=NULL){
		aux->siguiente = aux2->siguiente->siguiente;
		aux2->siguiente->siguiente=aux3;
		aux2=aux->siguiente;
		aux=aux3->siguiente;
		aux3=aux3->siguiente->siguiente;
	}
	aux->siguiente = L2->primero;
	aux2->siguiente->siguiente = aux3;
	cout<<"\nResultado: "<<endl;
	cout<<"\nLista 1: "<<endl;
	L1->Mostrar();
	cout<<"\nLista 2: "<<endl;
	L2->Mostrar();

}

void lista::sumarCentro(int a) {
	cout<<"\nNumero a evaluar: "<<a<<endl;
	if(a < 99){
		cout<<"Debe utilizar un numero de cantidad de digitos impar mayor o igual a 100"<<endl;
	}
	else{
		crearListaNum(a);
		pnodo aux = primero;
		int largo = largoLista();
		int centro = (((largo-1)/2)+1);
		int valor = buscarPosicionValor(centro);
		int cont = 1;
		if(largo % 2 == 0){
			cout<<"La lista debe ser impar"<<endl;
			}
			else{
			while(cont <= largo){
				if(cont == centro){
				aux = aux->siguiente;
				cont = cont +1;
				}
			else{
				aux->valor = aux->valor + valor;
				aux = aux->siguiente;
				cont = cont + 1;
			}
		}	
	}
	}

}

int main()
{
   lista L1;//instancia null
   lista L2;
   lista L3;
   lista L4;
   lista L5;
   lista L6;
   lista L7;
   lista L8;
 
   cout<< "***************************************************************************************"<<endl<<endl<<endl;
  // L8.promedio(1233455);
   
   L1.InsertarInicio(2);
   L1.InsertarInicio(1);
   L1.InsertarFinal(3);
   L1.InsertarInicio(6);
   L1.InsertarFinal(4);
   L1.InsertarFinal(0);
//   L1.InsertarPos(1479,1);
//   L1.InsertarInicio(88);
   L2.InsertarFinal(1);
   L2.InsertarInicio(2);
   L2.InsertarInicio(5);
   L2.InsertarInicio(9);
   L2.InsertarInicio(7);
   L2.InsertarInicio(8);
   L2.InsertarInicio(35);
//   L2.InsertarInicio(98);
 //  L2.InsertarInicio(55);
 //  cout<<"Tarea #3"<<endl;
 
 /* 
   cout<<"\nPregunta 1: Buscar un numero en una lista."<<endl;
   L1.Mostrar();
   L1.buscarNumero(44);
   L1.buscarNumero(6);
   L1.buscarNumero(35);


   cout<<"\nPregunta 2: Buscar en posicion."<<endl;   
   L1.Mostrar();
   L2.Mostrar();
   L1.buscarPosicion(3);
   L2.buscarPosicion(5);
 */

   /*
   cout<<"\nPregunta 3: Sumar 2 listas del mismo tamano."<<endl;
   L1.Mostrar();
   L2.Mostrar();
   L3.sumarListasIguales(L1,L2);
   L3.Mostrar();
   L1.Mostrar();

   */


/*   
   cout<<"\n Pregunta 4: Sumar 2 listas de diferente tamano."<<endl;
   L1.Mostrar();
   L2.Mostrar();
   cout<<"Lista Sumada: "<<endl;
   L3.sumarListasDiferentes(L1,L2);
   L3.Mostrar();
*/


/*   cout<<"\n Pregunta 5: Recibe numero, los pone en lista y cuenta los pares.\n ";
   L3.contarPares(1246852);
   L3.Mostrar();
*/


/*   cout<<"\nPregunta 6: Suma pares, multiplica impares";
   L6.procesarParesImpares(12345678);

*/

/*
   cout<<"\nPregunta 7: Escribir una función que recibe dos números de igual tamaño,\n se insertan en dos listas y se suman. Los nodos, dejando una lista nueva"<<endl;
   L1.suma2Num(12345, 76587);
*/   
   
   
/*   cout<<"Pregunta 8: 

   L6.elevarParesImpares(12345);
   L6.Mostrar();
*/
 //   L6.promedio(858485);
	cout<<"TAREA #4"<<endl;
	cout<<"Enlazar Listas: "<<endl;
	L3.enlazarListas(612340,879521);
	
	cout<<endl<<"\nIngresa numero en lista y suma el valor del centro a su derecha e izquierda"<<endl;
	L6.sumarCentro(1234568);
	L6.Mostrar();

//   cin.get();
   return 0;


} 

