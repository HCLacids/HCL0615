#include <stdio.h>

int main(){
    float sum = 0;
    double x = 2, y = 1;
    for(int i = 1; i <= 20; i++){
        sum += x / y;
        int temp = x;
        x += y;
        y = temp;
    }
    printf("%f",sum);
    return 0;
}