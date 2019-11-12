#include<stdio.h>
int factorial (int n){
    if(n>0){
        return n*factorial(n-1);
    }
    else{
        return 1;
    }
    
}
int combination(int n , int r){
    if (n > 0 && r > 0 && n >= r){
        return n*factorial(n-1)/(r*factorial(r-1)*(n-r)*factorial(n-r-1));
    }
    else{
        return 1 ;
    }   
}
int main (void){
int n , r ;
printf("请输入两个整数:");
scanf("%d%d",&n,&r);
printf("%d\n",combination(n , r ));
return 0 ;
}