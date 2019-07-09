#include<iostream>
using namespace std;
#define leftchild(i) (2*i+1)

void swap(int *a,int *b){
    // cout << *a << endl;
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printarr(int *A,int N){
    for(int i=0;i<N;i++){
        cout << A[i] <<' ';
    }
    cout << endl;
}

void precdown(int *A,int i,int N){
    int child;
    int tmp;
    for(tmp=A[i];leftchild(i)<N;i=child){
        child = leftchild(i);
        if(child < N-1 && A[child] < A[child+1])
            child++;
        if(tmp < A[child])
            A[i] = A[child];
        else
            break;
    }
    A[i] = tmp;
    printarr(A,9);
}

void heapsort(int *A,int N){
    for(int i=N/2;i>=0;i--){
        precdown(A,i,N);
    }
    for(int i=N-1;i>0;i--){
        swap(&A[0],&A[i]);
        precdown(A,0,i);
    }
}

int main(){
    cout << "hello"<<endl;
    int A[] = {9,8,7,6,5,4,3,2,1};
    heapsort(A,9);
    printarr(A,9);
    return 0;
}