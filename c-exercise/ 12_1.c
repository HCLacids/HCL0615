#include <stdio.h>

int max_q(int x, int y){
    if(x < y){
        int temp = x;
        x = y;
        y = temp;
    }
while (x % y){
    int temp = y;
    y = x % y;
    x = temp;
}

    return y;
}

int min_q (int x, int y){
    int z =max_q(x,y);
    return x * y / z;
}

int main (){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d,%d",max_q(a,b),min_q(a,b));
    return 0;
}