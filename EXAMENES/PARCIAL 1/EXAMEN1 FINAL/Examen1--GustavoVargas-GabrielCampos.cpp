#include <iostream>
#include <stdlib.h> 

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
    
    void InsertarInicio(int v);//No retornan nada
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } //retorna True o False
    void Mostrar();//imprimir
    void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    void Sumanum(int num);
    int largoLista();// retorno un valor numerico
    
    //EXAMEN1
    void UNO(long long Num1, long long Num2);
    void DOS();
	void TRES(long long Num1, long long Num2);
	void CUATRO(long long num1, long long num2);
	 

	
    
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
       cout << "No hay elementos AQUI";  
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


 void lista::Sumanum(int num)//23456
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


//EXAMEN 1

//UNO

void lista::UNO(long long Num1, long long Num2){
	int cont = 0;
	int cont2 = 0;
	long long tempo = Num1;
	if (tempo == 0)
        cont = 1;
    while (tempo != 0) {
        tempo = tempo / 10;
        ++cont;
    }
    tempo = Num2;
    if (tempo == 0)
        cont2 = 1;
    while (tempo != 0) {
        tempo = tempo / 10;
        ++cont2;
    }
    cout<<"\t \n.:Ejercicio UNO:."<<endl<<endl;
    if(cont != cont2){
    	cout<<"Num1: "<<Num1<<endl;
		cout<<"Num2: "<<Num2<<endl;
		cout<<endl;
		cout<<"Largo de los numeros es diferente"<<endl;
	//	exit(0);
	}else if(cont%5 == 0 && cont%2 != 0){
	long long temp = abs(Num1);
	long long temp2 = abs(Num2);
	long long aux = abs(Num1);
	lista L1;
	lista L2;
	lista Suma;
	while(aux > 0){
		L1.InsertarInicio(temp%10);
		L2.InsertarFinal(temp2%10);
		aux = temp/10;
		temp = temp2/10;
		temp2 = aux;
	}
	pnodo n1 = L1.primero;
	pnodo n2 = L2.primero;
	while(n1){
		Suma.InsertarFinal(n1->valor+n2->valor);
		n1 = n1->siguiente;
		n2 = n2->siguiente;
	}
	cout<<"Num1: "<<abs(Num1)<<endl;
	cout<<"Num2: "<<abs(Num2)<<endl;
	cout<<endl;
	cout<<"Lista 1:"<<endl;
	L1.Mostrar();
	cout<<endl;
	cout<<"Lista 2:"<<endl;
	L2.Mostrar();
	cout<<endl;
	cout<<"Listas Sumadas:"<<endl;
	Suma.Mostrar();
	} else{
		cout<<"Numero1: "<<Num1<<endl<<"Numero2: "<<Num2<<endl;
		cout<<"Largo Num1: "<<cont<<endl;
		cout<<"Largo Num2: "<<cont2<<endl;
		cout<<"\n\nNumeros deben ser de un largo multiplo de 5 y este largo debe ser impar.\n"<<endl;
	}
}

//DOS

void lista::DOS() 
{
	cout<<"\t\n .:Ejercicio DOS:."<<endl<<endl;
	pnodo aux = primero;
	bool orden = true;
	cout<<"Lista Original: "<<endl;
	Mostrar();
	cout<<endl<<endl<<"Listas Generadas: "<<endl;
	lista L1;
		while (aux!=NULL&&ListaVacia()!=true){
			L1.InsertarFinal(aux->valor);
			if (aux->siguiente!=NULL) {
				if (aux->valor > aux->siguiente->valor){
					orden = false;
					L1.InsertarInicio(1);
					L1.InsertarInicio(0);
					L1.InsertarInicio(1);
					L1.InsertarFinal(0);
					L1.InsertarFinal(-1);
					L1.InsertarFinal(0);
					L1.Mostrar();
					while (L1.ListaVacia()!=true){
						L1.BorrarFinal();
					}		
				}
			}	
		aux = aux->siguiente;
		}
	if (orden==false){
		L1.InsertarInicio(1);
		L1.InsertarInicio(0);
		L1.InsertarInicio(1);
		L1.InsertarFinal(0);
		L1.InsertarFinal(-1);
		L1.InsertarFinal(0);
	}
	if (ListaVacia()==true){
		cout<<"Vacia"<<endl;
	}
	L1.Mostrar();	
	cout<<endl<<endl;	
}

//TRES
void lista::TRES(long long Num1, long long Num2){
	int cont = 0;
	int cont2 = 0;
	long long tempo = Num1;
	if (tempo == 0)
        cont = 1;
    while (tempo != 0) {
        tempo = tempo / 10;
        ++cont;
    }
    tempo = Num2;
    if (tempo == 0)
        cont2 = 1;
    while (tempo != 0) {
        tempo = tempo / 10;
        ++cont2;
    }
    if(cont != cont2){
    	cout<<"\t\n .:Ejercicio TRES:."<<endl<<endl;
    	cout<<"Num1: "<<Num1<<endl;
		cout<<"Num2: "<<Num2<<endl;
		cout<<endl;
		cout<<"Largo de los numeros es diferente"<<endl<<endl;
		//exit(0);
	}
	
	long long temp = abs(Num1);
	long long temp2 = abs(Num2);
	long long aux = abs(Num1);
	lista L1;
	lista L2;
	lista Suma;
	int a = 2;
	int b = -1;
	int c = a;
	if(cont%2 == 0){
	while(aux > 0){
		L1.InsertarInicio(a);
		L1.InsertarInicio(0);
		L1.InsertarInicio(a);
		L1.InsertarInicio(temp2%10+1);
		L1.InsertarInicio(temp2%10);
		L1.InsertarInicio(temp2%10-1);
		L1.InsertarInicio(-a);
		L1.InsertarInicio(0);
		L1.InsertarInicio(-a);
		
		L1.InsertarFinal(-b);
		L1.InsertarFinal(0);
		L1.InsertarFinal(-b);
		L1.InsertarFinal(temp%10-1);
		L1.InsertarFinal(temp%10);
		L1.InsertarFinal(temp%10+1);
		L1.InsertarFinal(b);
		L1.InsertarFinal(0);
		L1.InsertarFinal(b);
		
		aux = temp/10;
		temp = temp2/10;
		temp2 = aux;
		c = a;
		a = b;
		b = c;
	}
	}else{
		while(aux > 0){
		L1.InsertarInicio(b);
		L1.InsertarInicio(0);
		L1.InsertarInicio(b);
		L1.InsertarInicio(temp%10+1);
		L1.InsertarInicio(temp%10);
		L1.InsertarInicio(temp%10-1);
		L1.InsertarInicio(-b);
		L1.InsertarInicio(0);
		L1.InsertarInicio(-b);
		
		L1.InsertarFinal(-a);
		L1.InsertarFinal(0);
		L1.InsertarFinal(-a);
		L1.InsertarFinal(temp2%10-1);
		L1.InsertarFinal(temp2%10);
		L1.InsertarFinal(temp2%10+1);
		L1.InsertarFinal(a);
		L1.InsertarFinal(0);
		L1.InsertarFinal(a);
		
		aux = temp/10;
		temp = temp2/10;
		temp2 = aux;
		c = a;
		a = b;
		b = c;
	}
	}
	cout<<"\t\n .:Ejercicio TRES:."<<endl;
	cout<<"Num1: "<<abs(Num1)<<endl;
	cout<<"Num2: "<<abs(Num2)<<endl;
	cout<<endl;
	cout<<"Lista 1:"<<endl;
	L1.Mostrar();

}


//CUATRO

void lista::CUATRO(long long num1, long long num2){
	cout<< "***************************************************************************************"<<endl;
	cout<< "\t\n .:Ejercicio CUATRO:."<<endl;
	cout<< "***************************************************************************************"<<endl;
	cout<<"Num1: "<<num1<<endl;
	cout<<"Num2: "<<num2<<endl;
	lista L1;
	lista L2;
	lista L3;
	long long tamano = 10;
	long long temp = num1;
	while (num1*10>tamano)
	{
		L1.InsertarInicio(temp%10);
		temp = temp/10;
		tamano = tamano*10;
	}
	temp = num2;
	tamano = 10;
	while (num2*10>tamano)
	{
		L2.InsertarInicio(temp%10);
		temp = temp/10;
		tamano = tamano*10;
	}
	if(L1.largoLista()==L2.largoLista())
	{
		long long index1 = 1;
		long long  index2 = L2.largoLista();
		long long numop = 0;
		long long  anadir =0;
		bool operar = true;
		pnodo aux1 = L1.primero;
		pnodo aux2 = L2.primero;
		pnodo temp = aux2;
		L1.Mostrar();
		L2.Mostrar();
		if (L1.largoLista()%2==1)
		{
			while (operar == true)
		{
			int pos1 = 1;
			int pos2 = 1;
			int pos3 = 1;
			
			while(pos1!=index1)
			{
				aux1 = aux1->siguiente;
				pos1 = pos1+1;
			}
			while(pos2!=index2)
			{
				aux2 = aux2->siguiente;
				pos2 = pos2+1;
			}
			while(pos3!=index1)
			{
				temp = temp->siguiente;
				pos3 = pos3+1;
			}
			L3.InsertarFinal(abs((aux1->valor+aux2->valor)-temp->valor));
			L3.Mostrar();
			aux1 = L1.primero;
			aux2 = L2.primero;
			temp = aux2;
			int tempInd = index1;
			index1 = L1.largoLista()-numop;
			index2 = tempInd;
			pos1 = 1;
			pos2 = 1;
			pos3 = 1;
			while( pos1!=index1)
			{
				aux1 = aux1->siguiente;
				pos1 = pos1+1;
			}
			while( pos2!=index2)
			{
				aux2 = aux2->siguiente;
				pos2 = pos2+1;
			}
			while( pos3!=index1)
			{
				temp = temp->siguiente;
				pos3 = pos3+1;
			}
			L3.InsertarFinal(abs((aux1->valor+aux2->valor)-temp->valor));
			L3.Mostrar();
			aux1 = L1.primero;
			aux2 = L2.primero;
			temp = aux2;
			numop = numop+1;
			index1 = 1+numop;
			index1 = L2.largoLista()-numop;
			
			if (numop==(L1.largoLista()/2))
			{
				index1 = L1.largoLista()/2+1;
				index2 = L1.largoLista()/2+1;
				pos1 = 1;
				pos2 = 1;
			while(pos1!=index1)
			{
				aux1 = aux1->siguiente;
				pos1 = pos1+1;
			}
			while(pos2!=index2)
			{
				aux2 = aux2->siguiente;
				pos2 = pos2+1;
			}
				L3.InsertarFinal(aux1->valor*aux2->valor);
				operar = false;
			}
		}
		}
		while (operar == true)
		{
			int pos1 = 1;
			int pos2 = 1;
			int pos3 = 1;
			while(pos1!=index1)
			{
				aux1 = aux1->siguiente;
				pos1 = pos1+1;
			}
			while(pos2!=index2)
			{
				aux2 = aux2->siguiente;
				pos2 = pos2+1;
			}
			while(pos3!=index1)
			{
				temp = temp->siguiente;
				pos3 = pos3+1;
			}
			L3.InsertarFinal(abs((aux1->valor+aux2->valor)-temp->valor));
			L3.Mostrar();
			aux1 = L1.primero;
			aux2 = L2.primero;
			temp = aux2;
			int tempInd = index1;
			index1 = L1.largoLista()-numop;
			index2 = tempInd;
			pos1 = 1;
			pos2 = 1;
			pos3 = 1;
			while( pos1!=index1)
			{
				aux1 = aux1->siguiente;
				pos1 = pos1+1;
			}
			while( pos2!=index2)
			{
				aux2 = aux2->siguiente;
				pos2 = pos2+1;
			}
			while( pos3!=index1)
			{
				temp = temp->siguiente;
				pos3 = pos3+1;
			}
			L3.InsertarFinal(abs((aux1->valor+aux2->valor)-temp->valor));
			L3.Mostrar();
			aux1 = L1.primero;
			aux2 = L2.primero;
			temp = aux2;
			numop = numop+1;
			index1 = 1+numop;
			index2 = L2.largoLista()-numop;
			if (numop==(L1.largoLista()/2))
			{
				operar = false;
			}
		}
	cout<<"Final:"<<endl;
	L3.Mostrar();
	long long finnum = 0;
 	int dig = 10;
 	pnodo auxnum = L3.primero;
 	while (auxnum->siguiente!=NULL){
  		finnum = finnum + auxnum->valor;
  		while (auxnum->siguiente->valor >= dig){
   			dig = dig*10; 
  		}
  	finnum = finnum*dig;
  	dig = 10;
  	auxnum = auxnum->siguiente;
 	}
 	finnum = finnum + auxnum->valor;
 	cout<<finnum<<endl;
	}else if (L1.largoLista()!=L2.largoLista())
	{
		cout<<"Diferente tamaño"<<endl;
	}
}



int main()
{
 // UNO  
 	lista L1;
    L1.UNO(612572563512225, -35654134589102);
    L1.UNO(61257, 89102);
 //   L1.UNO(61257, 89102);
    L1.~lista();
    cout<<endl<<endl<<endl;
    
    
  //DOS 
	lista L3;
	L3.InsertarFinal(6);
	L3.InsertarFinal(1);
	L3.InsertarFinal(2);
	L3.InsertarFinal(7);
	L3.InsertarFinal(8);
	L3.InsertarFinal(16);
	L3.InsertarFinal(100);
	L3.InsertarFinal(-200);
	L3.InsertarFinal(-300);
	L3.InsertarFinal(-400);
	L3.InsertarFinal(10);
	L3.InsertarFinal(20);
	L3.InsertarFinal(3);
	L3.DOS();
	L3.~lista();
	cout<<endl<<endl<<endl;
   
   
 //TRES  
    L1.TRES(612572563512345, -123458910245856);
    L1.TRES(61257, 89102);
    L1.TRES(612345, 107895);
    L1.TRES(1234, 4456);
	L1.~lista();
    cout<<endl<<endl<<endl;
   

 // CUATRO
 	lista L4;
    L4.CUATRO(612572563512225, 356541345891021);
    L4.CUATRO(61257, 89102);
    L4.CUATRO(6123,8910);

  // cin.get();
  
	cout<<endl<<endl<<"################## EXAMEN 1 ####################"<<endl;
	cout<<"\nIntegrantes:\nGustavo Vargas Ramirez   --- 200409141 \nGabriel Campos Gutierrez --- 2023093692"<<endl;
	cout<<endl<<"*********************************************************************************"<<endl<<endl;	
	cout<<"###########################################################"<<endl;
	cout<<"################## PROGRAMA FINALIZADO ####################"<<endl;
	cout<<"###########################################################"<<endl;  
    return 0;
}
