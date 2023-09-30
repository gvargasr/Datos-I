
//BuscarNodo
//Parámetros

//Clave: Valor a insertar   14
//P: Apuntador del tipo Pagina   3 5 8 15
//Encontrado:boolean Esta=F
//K:posición 0

// Este método examina la pagina referenciada por P. De no //encontrarse el valor nuevo, K será el índice de la rama por //donde bajar

 {                                                                                                                     P1      P4
  If clave < P.claves[1]                                            // recuerde que los arreglos aquí inician en 1     3  5 8 15   ctas=4
      14<3x
  {
     Encontrado=false;
     K=0; //rama por donde descender
  }
  else
  {
    //Examina claves de la pagina
     K=P.Cuenta; // Numero de claves de la Pagina                      K=0  K=4 3
     While(Clave<P.claves[K] ) and (K>1)                               14<15si  y K>1 ambas   14<8x  y K>1
       K=K-1;
    Encontrado=Clave=P.Claves[K];                                      if clave==P.claves[k]  14==8 False
   }
}

//Inserta

//Parámetros

//C1: Valor a insertar
//Raiz: Apuntador del tipo Pagina

//Variables internas
//EmpujarArriba:boolean
//X:TipoClave
//Xr:Apuntador del tipo Pagina
//P:Apuntador del tipo Pagina

{
    Empujar(C1,Raiz,EmpujarArriba,X,Xr);
    If EmpujaArriba T
         // La propagación del proceso de división llego a la raíz, es     
        //creado un nuevo nodo  
   {
       P= new que crea una nueva pagina, según la clase
       P.Cuenta=1;
       P.Claves[1]=X;//Clave mediana que ha ascendido
       P.Ramas[0]=Raiz;
       P.Ramas[1]=Xr;
       Raiz=P //Nueva Raiz
    }
}

//Método de Empujar
//Parámetros

//C1: Valor a insertar
//R: Apuntador del tipo Pagina
//EmpujaArriba:boolean
//Mdna:Tipo de la Información 
//X:Apuntador del tipo de la Pagina

//Variables Internas
//K:Posicion
//Esta:Booleana //Detectsa que la clave ya esta en el nodo
{
  If ArbolVacio
   {
    // Termina la recursión, estamos  en rama vacia
     Empuja Arriba=true;
     Mdna=C1;
     Xr=NULL;
  }
  else
  {
    BuscarNodo(C1,R,Esta,K)//K es la rama por donde seguir   SALE
    If Esta  FALSE
       Cout Elemento repetido                                                          //NO REPETIDOS
    Empujar(C1,R.Rama[K],EmpujaArriba,Mdna,Xr);                                        //llamada recursiva  14,R[3] F T  F  Mdna=0 14  Xr null null
    If EmpujaArriba                                                                    // T
     If R.Cuenta<Max  //No esta lleno                                                     4<4 Nodo lleno  Max=4
      {
          EmpujaArriba=false;
           MeterHoja(Mdna,Xr,R,K);//Inserta la clave Mdna en el nodo   
           //R, posición k+1
      }
     Else  //Nodo lleno 
     {
        EmpujaArriba=true;                                                              //T
        DividirNodo(Mdna,Xr,R,K,Mdna,Xr);                                              // 14 null 3 5 8 15  K=3 14 null 
      }
  } 
}

//Método de MeterHoja
//Parámetros

//X: TipoClave                                                                        14 
//Xder: Apuntador del tipo Pagina                                                     null 
//P: Apuntador del tipo Pagina                                                        Mder (nueva)
//K:posición                                                                          0

//Variables internas
//I: Posicion                                                                        I=

{
 // Se trabajara con P
 With P  Mder (nueva)
  {
     For I= Cuenta reduciendo hasta K+1  I=1 reduciendo  K+1 (solo una vez)
     {
        // Son desplazadas Claves/ramas para insertar X                              P1 P2
        Claves[I+1]=Claves[I];                                                      14 15 x x 
        Ramas[I+1]=Ramas[I];
  }
    Claves[K+1]=X;
    Ramas[K+1]=Xder;
    Cuenta=Cuenta+1;
 }

//Método de DividirNodo
//Parámetros

//X: TipoClave                                                                       14
//Xder: Apuntador del tipo Pagina                                                   null
//P: Apuntador del tipo Pagina                                                      3 5 8 15
//K:posición                                                                        3
//Mda:TipoClave                                                                     14
//Mder:Apuntador del tipo Pagina                                                    null

//Variables internas
//I: Posicion                                                                      0
//Posmda:Posicion                                                                  0 3

{
  If K <=Min // Min es la posicion central, la clave se localiza a la izq         3<=2
    Posmda=Min;
 Else
    Posmda=Min+1; 3
Mder= new que crea una nueva pagina, según la clase
With P   3 5 8 15x
{
   For I=Posmda+1 to Max  I=4 to 4( solo una vez)
   {
     Mder.Claves[I-Posmda]=Claves[I];// Es desplazada la mitas                   I=4  4-3=1
     //derecha al nuevo nodo, la clave mediana se queda en el nodo 
    //izquierdo
    Mder.Ramas[I-Posmda]=Ramas[I];
   }
Mder.Cuenta = Max-Posmda; //Claves en el Nuevo nodo                             4-3=1
Cuenta=Posmda;//Claves que quedan en nodo izq                                   3
//Insercion de clave X y su rama derecha
If K <=Min  K=3<=2x
   MeterHoja (X,Xder,P,K); //inserta en nodo izq
Else
    MeterHoja (X,Xder,Mder,K-Posmda)                                           14   null  paginanueva 3-3=0     LLAMADA A METERHOJA
    //extrae mediana del nodo izq
Mda=Claves[Cuenta];                                                            8
Mder.Ramas[0]=Ramas[Cuenta];// Rama 0 del nuevo nodo es la 
//rama de la mediana
Cuenta=Cuenta-1 //Disminuye ya que se quita la mediana
}
}
