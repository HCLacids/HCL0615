#include <stdio.h>
#include <math.h>
int equal(int n){
    if (n % 10 == n / 100 && n %10 != n / 10 % 10 || n % 10 == n / 10 % 10 && n % 10 != n / 100 || n /100 % 10 == n / 100 && n / 100 != n % 10 ){
        return 1;
    }else{
        return 0;
    }
    
}
int func(int n){
    if (sqrt(n) == (int)sqrt(n)){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int x;
    scanf("%d",&x);
    if(func(x) && equal(x)){
        printf("yes");
    }
    return 0;
}