#include <stdio.h>
int main(){
    int a[4][5];
    int sum[4] = {0,0,0,0};
    int temp[4][5];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            sum[i] += a[i][j];   
        }
    }
    int max = sum[0];
    for(int i = 0; i < 4; i++){
        if(max < sum[i]){
        max = sum[i];
        }
    }
    for (int i = 0; i < 4; i++){
        if ( max = sum[i])
          for(int j = 0; j < 5; j++){
            temp[i][j] = a[i][j];
            a[i][j] = a[0][j];
            a[0][j] = temp[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
           printf("%d,",a[i][j]);
        }
        printf("\n");
    }
return 0;
}