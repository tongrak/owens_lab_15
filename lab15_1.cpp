#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *A, int N ,int M){
	cout << fixed << setprecision(2);
    for(int i = 0; i < N*M; i++){
        cout << *(A+i);
        if((i+1)%M==0) cout << endl;
        else cout << " ";
    }
}

void randData(double *A, int N, int M){
	for(int i=0; i<N*M;i++){
		*(A+i)=(rand()%101)/100.0;
	}
}

void findRowSum(const double *A, double *out, int Y, int X){
	int v=0;
	double holder=0;
	for(int i=0;i<X*Y;i++){
		holder+=*(A+i);
		if((i+1)%X==0){
			*(out+v)=holder;
			holder=0;
			v++;
		}
	}
}

void findColSum(const double *A, double *out, int Y, int X){
	int v=0;
	double holder[X]={};
	for(int i=0;i<X*Y;i++){
		holder[v]+=*(A+i);
		v++;
		if((i+1)%X==0){
			v=0;
		}
	}
	for(int j=0;j<X;j++){
		*(out+j)=holder[j];
	}
}