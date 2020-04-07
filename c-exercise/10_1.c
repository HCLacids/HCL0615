#include <stdio.h>

int main(){
    int a[3][3];
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < 3; i++){
        int j = 0;
        sum1 = a[i][j];
        j++;
    }
    for (int i = 2; i >= 0; i--){
        int j = 2;
        sum2 = a[i][j];
        j--;
    }
    printf("%d,%d",sum1,sum2);
    return 0;
}