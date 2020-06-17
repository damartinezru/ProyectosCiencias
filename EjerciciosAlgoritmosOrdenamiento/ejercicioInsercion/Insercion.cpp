#include <iostream>
#include <algorithm> 
#include <ctime>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void insercion(int a[], int N){
	int i, j,v;	
	cout<< "Desorganizado:"<<"\n";
	for (i=1; i<=N; i++) {
		cout<< a[i]<<"\n";
	}
	cout<<"N: "<<N<<endl;
	for (i=2; i<=N; i++)
     { j=i;   v=a[j];
       while(a[j-1]>v && j>1)
         {a[j]=a[j-1];
           j--;
         }
        a[j]= v;
      }
    
	cout<< "Organizado:"<<"\n";
	for (i=1; i<=N; i++) {
		cout<< a[i]<<"\n";
	}
	cout<<endl;

	
}

int main(int argc, char** argv) {
  	unsigned t0, t1;
	clock_t t;
	int N=50, i;
	int a[N];
	for(i=0;i<N;i++){
		a[i]=1+ rand()%30;
	}
  	t0=clock();
	insercion(a, N);
  	t1=clock();

  	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Tiempo: " << time << endl;
	return 0;
}
