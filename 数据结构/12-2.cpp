#include <iostream>
typedef int ElemType;
using namespace std;

void enter(ElemType Array[],int n){
    cout<<"输入"<<n<<"阶矩阵";
    for (int i = 0; i < n * (n + 1) / 2; i++)
        cin>>Array[i];
}

void add(ElemType A[], ElemType B[], ElemType C[], int n){
    for (int i = 0; i < n * (n + 1) / 2; i++){
        C[i] = A[i] + B[i];
    }
}

void print_Array(ElemType Array[],int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i >= j) cout<<Array[i * (i + 1) / 2 + j]<<" ";
            else if(j > i) cout<<Array[j * (j + 1) / 2 + i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"请输入矩阵阶数:";
    cin>>n;
    ElemType A[n], B[n],C[n];
    enter(A,n);
    enter(B,n);
    cout<<"A矩阵："<<endl;
    print_Array(A,n);
    cout<<"B矩阵："<<endl;
    print_Array(B,n);
    add(A,B,C,n);
    cout<<"C矩阵："<<endl;
    print_Array(C,n);
    return 0;
}
