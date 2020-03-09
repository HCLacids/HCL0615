#include <stdio.h>

int main(){
    int sum ;
    int SUM = 0;
    for (int i = 2; i <= 1000; i++){
        sum = 1;
        for(int j = 2; j <=i/2; j++){
            if(i % j == 0){
                sum += j;
            }
        }
        if(sum == i){
            printf("%d+",i);
            SUM += i;
        }
    }
    printf("0=%d",SUM);
    putchar('\n');
    return 0;
}