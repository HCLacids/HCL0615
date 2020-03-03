#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main(){
    int r;
    printf("请输入半径");
   scanf("%d",&r);
   printf("圆的周长为：%.7f,面积为：%.7f\n",2*PI*r,PI*r*r);
    return 0;
}