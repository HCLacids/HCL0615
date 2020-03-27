#include<stdio.h>
long factorial (int n){
    if(n>0){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
    
}
int main(){
    long n = 0;
    for (int i = 1; i <= 20; i++){
        n += factorial(i);
    }
    printf("%ld",n);
    return 0;
}