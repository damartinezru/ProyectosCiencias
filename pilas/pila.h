#include "estructura.h"
#ifndef PILA_H     
#define PILA_H 

class Pila
{public:
    Pila (){ cab= new nodo;
             cab->dato=NULL;
             cab->sig=NULL;};
   ~Pila();
     void Push(int V);
     int Pop();
     bool vacia();
 private:
   struct  nodo *cabeza, *z;
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
 t->dato = v;  t->siguiente=cabeza->siguiente;
cabeza->siguiente=t;
}

int Pila:: Pop()
{int x;
 struct nodo *t = cabeza->siguiente;
cabeza->siguiente = t->siguiente; x=t->dato;
delete t; return x;
}

bool Pila::PilaVacia(){
      return cab->sig== NULL;
}

#endif


