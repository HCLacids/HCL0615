#include <stdio.h>

int judge(int x, int num,int *i){
    if( x % num == 0){
        printf("能被%d整除\n",num);
        *i = *i + 1;
    }
    return 0;
}

int main (){
    int a;
    int *sum ;
    *sum = 0;
    scanf("%d",&a);
    judge(a,3,sum);
    judge(a,5,sum);
    judge(a,7,sum);
    printf("能被以上%d数整除\n",*sum);
    return 0;
}