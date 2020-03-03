#include <stdio.h>
int main(){
    int m,i = 0,n = 0, q = 0, z=0;
     int p = 1;
    printf("请输入钱数目（单位分）：\n");
    scanf("%d",&m);
    do{
        p = m /25;
        i++;
    }while ( p<=0);
    do{
        p = (m-i*25) /10;
        n++;
    }while ( p<=0);
    do{
        p = (m- i*25-n*10)/5;
        q++;
    }while ( p<=0);
    do{
        p = (m-i*25-n*10-q*5)/1;
        z++;
    }while ( p<=0);
    printf("%d",i+n+q+z);
    return 0;
}