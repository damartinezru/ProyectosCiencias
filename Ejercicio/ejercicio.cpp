
#include <cstdlib>
#include <iostream>
using namespace std;

/*struct nodo {int x,y; 
			 nodo*sig;
			};
*/			
int main(int argc, char** argv) {
	
	int N,i,j,suma=0,**a;
	cin>>N;
	a= new int *[N];
	
	for(i=0;i<N;i++){		
		a[i] = new int[N];
		for(j=0;j<N;j++) {
			a[i][j]=j*i;
			suma +=sizeof(**a);		
		}
		suma +=sizeof(*a);	
	}
	for(i=0;i<N;i++){
		for(j=0;j<N;j++) 		
			cout<< a[i][j];
		delete a[i];
	}
	delete a;
	cout<<"\n";
	cout<<sizeof(suma);
	cout<<"\n";
	cout<<sizeof(N);
	cout<<"\n";
	cout<<sizeof(i);
	cout<<"\n";
	cout<<sizeof(j);
	*/
	
/*	int N, i,j, suma = 0;
	nodo *cab = NULL, *Aux;
	cin>> N;
	for(i=0;i<N;i++){
		suma += sizeof(Aux);
		Aux= new nodo;
		Aux-> x = i;
		Aux->y = N-i;
		Aux->sig = cab;
		cab = Aux;

	}
	Aux = cab;

	while(Aux!=NULL){
		//cout << Aux->x<< Aux->y<<endl;
		Aux= Aux->sig;
	}
	cout<<suma;
	cout<<"\n";
	cout<<sizeof(cab);
	cout<<"\n";
	cout<<sizeof(N);
	cout<<"\n";
	cout<<sizeof(i);
	cout<<"\n";
	cout<<sizeof(j);
	for(Aux=cab->sig; Aux!=NULL; Aux=Aux->sig){
		delete cab;
		cab=Aux;
	}
	*/
}

