#include <stdio.h>

int main(){
    int x;
    int n = 1;
    int y;
    printf("请输入一个5位以下的数：");
    scanf("%d",&x);
    y = x;
    while (x /10){
        n++;
        x /= 10;
    }
    printf("位数:%d\n",n);
    for (int i = 0; i < n; i++){
        printf("%d",y % 10);
        y /= 10;
    }
    printf("\n");
    return 0;
}