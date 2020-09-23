#include <algorithm> 
#include <ctime>
#include <iostream> 
using namespace std;


int intercambio(int a[],int j);
	
int main(int argc, char** argv) {
	unsigned t0, t1;
	clock_t t;
	
	int N=55,i,j,aux;
	int a[N];
	for(i=0;i<N;i++){
		a[i]=1+ rand()%30;
	}
	t0=clock();
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				if(a[j]>a[j+1])
					intercambio(a,j);
	
	for(i=0;i<N;i++){
		cout<<a[i]<<" ";
	}
	
	t1 = clock();
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << time << " segundos"<< endl;
	return 0;
	
	return 0;
}
int intercambio(int a[],int j){
	int aux;
	aux= a[j];
	a[j] = a[j+1];
	a[j+1] = aux;
	return a[j],a[j+1];
	}
