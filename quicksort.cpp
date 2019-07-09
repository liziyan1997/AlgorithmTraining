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

// int median3(int* A,int left,int right){
//     int center = (left+right)/2;
//     if(A[left] > A[center])
//         swap(&A[left],&A[center]);
//     if(A[left] > A[right])
//         swap(&A[left],&A[right]);
//     if(A[center] > A[right])
//         swap(&A[center],&A[right]);
    
//     swap(&A[center],&A[right-1]);

//     return A[right-1];  
// }

void quicksort(int* A,int left,int right){
    int pivlot = A[left];
    int i,j;
    if(left<right){
        i = left+1;
        j = right;
        while(1){
            while(A[i] < pivlot)
                i++;
            while(A[j] > pivlot)
                j--;;
            if(i < j)
                swap(&A[i],&A[j]);
            else
                break;
        }
        swap(&A[left],&A[j]);
        printarr(A,9);

        quicksort(A,left,j-1);
        quicksort(A,j+1,right);
    }
}

int main(){
    cout << "hello"<<endl;
    int A[] = {5,8,1,6,4,2,7,9,3};
    quicksort(A,0,8);
    printarr(A,9);
    return 0;
}