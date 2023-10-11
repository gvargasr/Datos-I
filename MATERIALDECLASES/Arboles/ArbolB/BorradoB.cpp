m//Tiene como funcion devolver la nueva raiz si la raiz inicial se ha quedado sin claves
Eliminar (C1:Tipo,Raiz:Pagina)
Variables
      Encontrado: boolean
       P:Pagina
{
   EliminarRegistro(C1:valor a borrar,Raiz,Encontrado)
   if not Encontrado
      Cout<< " el elemento no se encuentra en el árbol"
   else
      if Raiz.Cuenta == 0 // la raíz ha quedado vacia
      {
        P= Raiz
        Raiz= Raiz.Rama[0]
        Delete(P)
      }
}

//Este metodo controla el proceso de borrado de una clave
//Primero busca en el nodo donde se encuentra la clave a eliminar
//Si es una hoja, llama a elimina
// Si no es hoja, se busca el sucesor inmediato, se coloca en el elemento a eliminar
//Luego se suprime el sucesor  en la hoja
EliminarRegistro(C1:valor a borrar,Raiz,Encontrado:boolean)
{
  Variables
     K: posición inicia en 0
     
     if arbolvacio(R) 
        Encontrado= false// se ha llegado debajo de una hoja, la clave no esta en el arbol
     else
     {
       with Raiz
       {
         BuscarNodo(C1,Raiz,Encontrado,K)
         if Encontrado
         {
           if Ramas[K-1]==NULL//Las ramas estan indexadas desde 0 a Max, por lo que este nodo es hoja 2-1
              Quitar(Raiz,K)
           else //No es hoja
           {
              Sucesor(Raiz,K)//reemplaza  Claves[K] por su sucesor
              EliminarRegistro(Claves[K],Ramas[K],Encontrado)//Elimina la clave sucesora en su nodo
              if not Encontrado //inconsistencia debe esta en el nodo
                Cout << "Error en el proceso"
           }
         }  
         else // No ha sido localizada la clave
         {
            EliminarRegistro (C1,Ramas[K],Encontrado)
            // Las llamadas recursivas retornan el control a este punto,  
            // se comprueba que el nodo hijo mantenga un numero
            // claves igual o mayor que el minimo necesario
            if Ramas[K]!=NULL
              if Ramas[K].Cuenta<Min
                 Restablecer(Raiz,K)
         }         
 }

//recibe la direccion del nodo y la posicion de la clave a eliminar.
//Elimina la clave junto con la rama que le corresponde
Quitar(P: Pagina,K:Posicion)
{
  Variable J:posición //entero
   With P
   {
    for J= K+1 to Cuenta 2+1    to 3
    {
       Claves[J-1]=Claves[J]//Desplaza una posicion a la izquierda, con ello elimina la clave
       2            3
       Ramas[ J-1]=Ramas[J]
    }
    Cuenta=Cuenta -1
}

//Busca la clave inmediatamente sucesor de la clave k y reemplaza la clave K
Sucesor (P:Pagina,K:Posicion)
{
  Q:Pagina
  
  Q=P.Ramas[K]
  while Q.Ramas[0]!=NULL
     Q=Q.Ramas[0] 
  P.Claves[K]=Q.Claves[1]
}

//Este realiza las acciones mas complejas del proceso. Restaura el nodo P.Ramas[K]
//el cual ha quedado con un numero menor de claves, menos que el minimo
Restablecer (P:Pagina,K:Posicion)
{
  if K>0//Tiene hermano izquierdo
  {
       if P.Ramas[K-1].Cuentas>Min //Tiene mas claves que el minimo y por tanto puede desplazarse una clave
            MoverDerecha(P,K)
       else
           Combina(P,K)
  }
  else
   {//solo tiene hermano derecho
      if P.Ramas[1].Cuenta>Min
        //Tiene mas claves que el minimo
        MoverIzqda(P,1)
      else 
        Combina(P,1)
   }
} 

//Mueve una clave del nodo antecedente(P) al nodo que se esta restaurando
//Asciende la clave mayor del hermano izquierdo al nodo antecedente
 MoverDerecha (P:Pagina,K:Posicion)
 //En este metodo se deja hueco en el nodo P.Ramas[K] que es el nodo que tiene menos claves que elminimo 
 //necesario, inserta la clave k del nodo antecedente y a su vez asciende la clave mayor ( la mas a la derecha) 
 //del hermano izquierdo
{
  J:Posicion
   with P.Ramas[K]
   {
      for J= Cuenta reduciendo hasta 1
      {
        Claves[J+1]= Claves[J]
        Ramas[J+1]=Ramas[J]
      }
     Cuenta=Cuenta+1
     Ramas[1]=Ramas[0]
     Claves[1]=P.Claves[K] // baja la clave del nodo padre
   }
   //Ahora sube la clave desde el hermano izquierdo al nodo padre, para reemplazar la que bajo
   with P.Ramas[K-1] // hermano izquierdo
   {
     P.Claves[K]=Claves[Cuenta]
     P.Ramas[K].Ramas[0]=Ramas[Cuenta]
     Cuenta=Cuenta-1
   }
}

//Ahora la clave que asciende al nodo antecedente es la clave menor(izquierda) del nodo a restaurar
MoverIzquierda (P:Pagina,K:Posicion)
{
  J:Posicion
  with P.Ramas[K-1]// es el nodo con menos claves que el minimo
  {
    Cuenta=Cuenta+1
    Claves[Cuenta]=P.Claves[K]
    Ramas[Cuenta]=P.Ramas[K].Ramas[0] 
      // baja la clave del nodo padre
  }
  with P.Ramas[K] // hermano derecho
  {
    P.Claves[K]=Claves[1]//sube al nodo padre de la clave 1 del hermano derecho, sustituye a la que bajo
    P.Ramas[0]=Ramas[1]
    Cuenta=Cuenta-1
    for J= 1 hasta Cuenta
    {
       Claves[J]= Claves[J+1]
       Ramas[J]=Ramas[J+1]
    }
  }
}

//Este metodo forma un solo nodo
//Combina el nodo que esta en la rama K con el que esta en la rama k-1 y la clave mediana de ambos
// que se encuentra en el nodo ascendente.
Combina(P:Pagina,K:Posicion)
//forma un nuevo nodo con el hermano izquierdo la mediana ente el nodo problema y el hermano izquierdo
//situado en el nodo padre y las claves del nodo problema.
{
  J:Posicion
  Q:Pagina
  Q=P.Ramas[K]
  with P.Ramas[k-1]//hermano izquierdo
  {
    Cuenta=Cuenta+1
    Claves[Cuenta]=P.Claves[K]// baja clave mediana desde el nodo padre
    Ramas[Cuenta]=Q.Ramas[0]
    for J=1 to Q.Cuenta
    {
      Cuenta=Cuenta+1
      Claves[Cuenta]=Q.Claves[J]
      Ramas[Cuenta]=Q.Rmas[J]
    }
  }
 //Reajustadas las claves y ramas del nodo padre debido a que antes ascendio la clave K
 with P
 {
  for J= K to Cuenta-1
  {
    Claves[J]=Claves[J+1]
    Ramas[J]=Ramas[J+1]
  }
  Cuenta=Cuenta-1
 }
 delete(Q)
}  
