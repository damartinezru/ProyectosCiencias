#include <iostream>
#include <cstdlib>
#include "arbol.h"


using namespace std;

nodoArbol *nodoArbol =NULL;


int main(int argc, char** argv) {
	int dato,opc;
	Arbol arbol;	
	arbol.insertar(100);
	arbol.insertar(150);
	arbol.insertar(50);
	
	nodoArbol = arbol.buscarNodoArbol(100);
	cout<<nodoArbol->dato;
	arbol.postorden(nodoArbol);
/*	opc =0;
	do{
		cout<<"1-Insertar nuevo nodo"<<endl;
		cout<<"2-Buscar nodo"<<endl;
		cout<<"3-Buscar nodo padre"<<endl;
		cout<<"4-Borrar nodo"<<endl;
		cout<<"5-Preorden"<<endl;
		cout<<"6-Salir?"<<endl;
		cin>>opc;
			
		switch(opc){
		case 1:
			 cout<<"Insertar un nuevo nodo al arbol"<<endl;
			 cout<<"digite el numero"<<endl;
			 cin>>dato;
			 
			 //arbol.insertar(dato);
			 break;
		case 2:
			 cout<<" Buscar nodo al arbol"<<endl;
			 cin>>dato;
			 cout << arbol.buscarNodoArbol(dato)->dato;
			 break;
	    case 3:
			 cout<<"buscar nodo padre arbol"<<endl;
			 cin>>dato;
			 nodoArbol = arbol.buscarNodoArbol(dato);
			 cout << arbol.buscarPadre(dato,nodoArbol );
			 break;
		case 4:
			 cout<<"Inorden"<<endl;
			 cout<<"digite el numero"<<endl;
			 cin>>dato;
			 nodoArbol = arbol.buscarNodoArbol(dato);
			 arbol.inorden(nodoArbol);			 
			 break;
		case 5:
			 cout<<"Preorden"<<endl;
			 cout<<"digite el numero"<<endl;
			 cin>>dato;
			 nodoArbol = arbol.buscarNodoArbol(dato);
			 arbol.preorden(nodoArbol);			 
			 break;
		case 6:
			break;
			
		}
	}while(opc != 6);
	
	*/
	
}
