#include <iostream>
using namespace std;

class pila 
{
   private:
   int Tope;
   int Pila [5];
  


public:
      
       pila(){
       Tope = -1;
       for(int i =0;i<5;i++){
         Pila[i]=0;    
           }
       }
       
      bool pilaVacia(){return Tope < 0;}        
      void push(int v); 
      void pop ();
      void imprimir();
};

void pila:: push (int v)
{
         if(Tope <(5-1))
         {
            Tope++;
            Pila[Tope]= v; 
           
         }
         else
             cout<<"La pila esta llena";  
}   

void pila:: pop ()
{
         if(!pilaVacia()){
            Tope--;
         }
         else{
         cout<<"La pila esta vacia";  
         }
}  

void pila:: imprimir()
{
     for(int i = Tope;i>=0;i--)
     {
        cout<<Pila[i]<<"->";        
           }
}
 
 int main()
{
    pila pila;
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);
    pila.push(10);
    cout<<" "<<endl;
 //   pila.push(10);
   pila.imprimir();
    cout<<" "<<endl;  
    cout<<" "<<endl; 
    cout<<" "<<endl; 
    pila.pop();
   pila.imprimir();
    cout<<" "<<endl;  
    cout<<" "<<endl; 
    cout<<" "<<endl; 
   pila.push(34);
    pila.imprimir();
   
   cin.get();
   return 0;   
      
}

