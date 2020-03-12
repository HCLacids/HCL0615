#include <stdio.h>
long func(int n){
    long s;
    if (n > 0){
        s= n*func(n-1);
    }else{
        s = 1;
    }
    return s;
}

int main(){
    int m,n;
    scanf("%d,%d",&m,&n);
    printf("%ld",func(m)/(func(m - n)*func(n)));
    return 0;
}