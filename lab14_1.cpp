#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double sum1 = 0,sum2 = 0,sum3 = 1,sum4 = 0,Max = A[0],Min = A[0]; 
    for(int i=0;i<N;i++){
        sum1 += A[i];
    }
    for(int i=0;i<N;i++){
        sum2 += pow(A[i],2);
    }
    for(int i=0;i<N;i++){
        sum3 *= A[i];
    }
    for(int i=0;i<N;i++){
        sum4 += (1/A[i]);
    }
    for(int i=1;i<N;i++){
        if(A[i]>Max) Max = A[i];
        if(A[i]<Min) Min = A[i]; 
    }
    
    B[0] = sum1/N;
    B[1] = sqrt((sum2/N)-pow(sum1/N,2));
    B[2] = pow(sum3,(1.0/N));
    B[3] = (N/sum4);
    B[4] = Max;
    B[5] = Min;
}
