#include "cola.h"
#include "pila.h"
#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>


struct nodoArbol{
	    int dato;
        nodoArbol *nodoIzq;
        nodoArbol *nodoDer;
};
		

//privados
nodoArbol *crearNodo(int dato){
	nodoArbol *n = new nodoArbol();	
	n->dato=dato;
	n->nodoIzq=NULL;
	n->nodoDer=NULL;
}     

void insercionInterna(int dato, nodoArbol *nodoArb)
{
   if( dato > nodoArb->dato )
         insercionInterna( dato, nodoArb->nodoDer );
    else
         insercionInterna( dato, nodoArb->nodoIzq );
   
}

nodoArbol *buscarNodo(int dato, nodoArbol *p) {
	if(p!=NULL)
  	{
	    if(dato==p->dato)
	      return p;
	    if(dato<p->dato)
	      return buscarNodo(dato, p->nodoIzq);
	    else
	      return buscarNodo(dato, p->nodoDer);
  	}
  	else return NULL;
}

//
  
class Arbol{
	  nodoArbol *raiz;
	  cola *listInorden, *listPreorden, *listPosorden;
	  
      public: Arbol(){
	  		raiz = NULL;
	  		listInorden = new cola;
	  		listPreorden = new cola;
	  		listPosorden = new cola;
	  }
        void insertar(int dato);
        nodoArbol *buscarPadre(int dato, nodoArbol *p);
        void eliminar(int dato);
        nodoArbol *buscarNodoArbol(int dato);
        void inorden(nodoArbol *inicio);
        void postorden(nodoArbol *inicio);
        void preorden(nodoArbol *inicio);
        
      
};



//publicos
void Arbol::insertar(int dato) {
	if(raiz == NULL){
		raiz = crearNodo(dato);
	} 
	insercionInterna(dato, raiz);
}



void Arbol::eliminar(int dato) {
	  
	  nodoArbol *padre = buscarPadre(dato, raiz);
	  nodoArbol *hijo = buscarNodo(dato, padre);
	  
       // 3 casos :
       // 1. Eliminando un nodo hoja
       // 2. Eliminando un nodo con un solo hijo
       // 3. Eliminando un nodo con dos hijos

       // nodo con un solo hijo
       if((hijo->nodoIzq == NULL && hijo->nodoDer != NULL) || (hijo->nodoIzq != NULL && hijo->nodoDer == NULL))
       {
         if(hijo->nodoIzq == NULL && hijo->nodoDer != NULL)
         {
            if(padre->nodoIzq == hijo)
            {
               padre->nodoIzq  = hijo->nodoDer;
               delete hijo;
            }
            else
            {
               padre->nodoDer = hijo->nodoIzq;
               delete hijo;
            }
          }
          return;
       }

       //nodo hoja
       if( hijo->nodoIzq == NULL && hijo->nodoDer  == NULL)
       {
         if(padre->nodoIzq == hijo)
         {
            padre->nodoIzq = NULL;
         }
         else
         {
            padre->nodoDer = NULL;
         }
         delete hijo;
         return;
       }


       // Eliminando un nodo con dos hijos
       // el de la derecha mas a la izquierda
       if (hijo->nodoIzq!= NULL && hijo->nodoDer != NULL)
       {
          nodoArbol* aux;
          aux = hijo->nodoDer;
          if((aux->nodoIzq == NULL) && (aux->nodoDer == NULL))
          {
            hijo = aux;
            delete aux;
            hijo->nodoDer = NULL;
          }
          else // nodo derecho tiene un hijo
          {
            //Si el nodo derecho tiene un hijo izquierdo
            // Buscar todos los hijos a la izquierda

            if(hijo->nodoDer->nodoIzq!= NULL)
            {
               nodoArbol* hijoReemplazo;
               nodoArbol* padreReemplazo;
               
               
               hijoReemplazo = hijo->nodoDer;
               padreReemplazo = hijo->nodoDer->nodoIzq;
               
               while(hijoReemplazo->nodoIzq != NULL)
               {
                  padreReemplazo = hijoReemplazo;
                  hijoReemplazo = hijoReemplazo->nodoIzq;
               }
               hijo->dato = hijoReemplazo->dato;
               delete hijo;
               padreReemplazo->nodoIzq = NULL;
            }
            else
            {
               nodoArbol* tmp;
               tmp = hijo->nodoDer;
               hijo->dato = tmp->dato;
               hijo->nodoDer = tmp->nodoDer;
               delete tmp;
            }

         }
         return;
	}
}


nodoArbol *Arbol::buscarPadre(int dato, nodoArbol *p) {
	nodoArbol* actual = p;
	if (actual == NULL)
       return NULL;

    if(actual->nodoIzq == NULL && actual->nodoDer == NULL)
       return NULL;

    if( (actual->nodoIzq != NULL && actual->nodoIzq->dato == dato)
        || (actual->nodoDer != NULL && actual->nodoDer->dato == dato))
       return actual;

    if(actual->dato > dato)
       return buscarPadre(dato,actual->nodoIzq);

    if(actual->dato < dato)
       return buscarPadre(dato,actual->nodoDer);
}



nodoArbol *Arbol::buscarNodoArbol(int dato) {
	return buscarNodo(dato, raiz);
}

void Arbol::inorden(nodoArbol *nodoA) {
	cout<<"hola"<<nodoA->dato<<endl;
	if(nodoA == NULL){
		cout<< "nulo";
	}
	else{
		int temp;
		Pila pil;
		nodoArbol *actual = nodoA;
		while(actual != NULL || !pil.PilaVacia()){
			while(actual != NULL){
				pil.Push(actual->dato);
				actual = actual->nodoIzq;
				
			}
			//---
			pil.Pop();
			cout<<actual->dato<<" - ";
			actual = actual->nodoDer;
		}
		
	}
	
}

void Arbol::preorden(nodoArbol *nodo) {
	
	nodoArbol *actual = nodo;
	nodoArbol *anterior = nodo;
	if (nodo == NULL) {
		cout<< "nulo";
	} else {		
		while(actual!= NULL || !listPreorden->ColaVacia()) {
			if(actual->nodoIzq != NULL) {
				 
				listPreorden->InsCola(actual->dato);	
				anterior = actual;			
				actual = actual->nodoIzq;
			}
			if(actual->nodoDer != NULL) {
				listPreorden->InsCola(actual->dato);
				anterior=actual;
				actual = actual->nodoDer;				
			}
			
			if(actual->nodoIzq == NULL && actual->nodoDer == NULL){
				if(anterior->nodoIzq = NULL) {
					anterior->nodoDer = NULL;
				} else {
					anterior->nodoIzq = NULL;
				}
			    				
				actual = anterior;
				anterior = buscarPadre(actual->dato, raiz);
				//anterior = actual->descendiente;
								
			}
			if (anterior->nodoIzq->dato == anterior->dato) {
				actual = anterior->nodoDer;
			}
			if(anterior->nodoDer->dato == anterior->dato){
				listPreorden->ImprimirCola();
				listPreorden->AtenderCola();
			}
		}				
	}
	
}

void Arbol::postorden(nodoArbol *nodo){
	if (nodo == NULL) 
        return; 
    Pila s1, s2; 
    s1.Push(nodo->dato); 
    int nodoA; 
  
    while (!s1.PilaVacia()) { 
        nodoA = s1.Pop();          
        s2.Push(nodoA); 
        if (nodo->nodoIzq) 
            s1.Push(nodo->nodoIzq->dato); 
        if (nodo->nodoDer) 
            s1.Push(nodo->nodoDer->dato); 
    } 
  
    while (!s2.PilaVacia()) { 
        nodoA = s2.Pop(); 
        cout << nodoA << " "; 
    } 	
}

#endif
