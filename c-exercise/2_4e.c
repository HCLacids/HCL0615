#include <stdio.h>
int main(){
    long int x;
    int sum = 0;
    printf("请输入一个四位整数：\n");
    scanf("%ld",&x);
    for(int i = 0; i <= 4; i++){
        sum += x%10;
        x /=10;
    }
    printf("%d\n",sum);
    return 0;
}