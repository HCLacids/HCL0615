#include <stdio.h>

int main(){
    int a[10][10];
    for (int i = 0; i < 0; i++){
        if (i = 0){
            a[i][i] = 0;
            printf("%d\n",a[i][i]);
        } else{
            for (int j = 0; j < 10; j++){
                if (j = 0){
                    a[i][j] = 1;
                    printf("%d",a[i][j]);
                }
                else if(j = i){
                    a[i][j] = 1;
                    printf("%d\n",a[i][j]);
                    break;
                }else{
                    a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
                    printf("%d",a[i][j]);
                }
            }
        }
    }
    return 0;
}