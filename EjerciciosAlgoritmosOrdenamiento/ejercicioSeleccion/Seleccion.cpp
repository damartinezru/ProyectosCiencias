#include <iostream>
#include <ctime>
using namespace std;


void seleccion(int a[], int N){	
	int i,j,min, aux;
	cout<<"Desordenado: ";
    for(i=0; i<N; i++){
    	cout<<a[i]<<" ";
	}
	cout<<"N: "<<N<<endl;
	
	for(i=0;i<N; i++){
		min = i;
        for(j=i+1;j<N; j++){
        	if(a[j]<a[min]){
        		min = j;	
			} 	
		}	         
        aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
    cout<<"Ordenado: ";
    for(i=0; i<N; i++){
    	cout<<a[i]<<" ";
	}
	cout<<endl;
}

int main(){
	unsigned t0, t1;
	clock_t t;
	int numeros[] = {30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	
	t0=clock();
	seleccion(numeros, 30);
	t1 = clock();
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << time << endl;
	return 0;
}



