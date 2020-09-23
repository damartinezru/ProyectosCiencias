#include "estructura.h"
#ifndef PILA_H     
#define PILA_H 

class Pila
{	nodo *cab;	
	public:
    Pila (){ cab= new nodo;
             cab->dato=NULL;
             cab->sig=NULL;};
   ~Pila();
     void Push(int V);
     int Pop();
     bool PilaVacia();
     nodo *Top();
 private:
   struct   nodo *z;
 };
 


 Pila::~Pila(){
      nodo *t=cab;
     while (t!=NULL){
           cab=t;
           t=t->sig;
           delete cab;
           }
     }


void Pila:: Push (int v)
{struct nodo *t=new nodo;
 t->dato = v;  t->sig=cab->sig;
cab->sig=t;
}

nodo *Pila:: Top() {
	return cab->sig;
}
int Pila:: Pop()
{int x;
 struct nodo *t = cab->sig;
cab->sig = t->sig; x=t->dato;
delete t; return x;
}

bool Pila::PilaVacia(){
      return cab->sig== NULL;
}

#endif


