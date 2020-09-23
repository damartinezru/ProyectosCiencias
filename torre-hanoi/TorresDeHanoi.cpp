#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <ctime>
#include<stdlib.h>

using namespace std;

double diferenciaDeContadorDeRendimiento(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
        true;            
    }
    else
    {
        hanoi(num-1,A,B,C);
        hanoi(num-1,B,C,A);
    }
}
 
int main(int argc, char** argv)
{
    int n=1;
    char A,B,C;
    
 	while (n<=50){
    	cout<<"Numero de aros: "<<n<<endl;
    	LARGE_INTEGER t_ini, t_fin;
		double secs;
  		QueryPerformanceCounter(&t_ini);
    	hanoi(n,'A','C','B');
    	QueryPerformanceCounter(&t_fin);
		secs = diferenciaDeContadorDeRendimiento(&t_fin, &t_ini);
  		printf("%.16g\n", secs * 1000.0);
    	
		n=n+1;
		
	}
   		
    
    
    return 0;
}
