#include<stdio.h>
int main(){
    int a[50];
    int z[50];
    int x = 0;
    int p = 0;
     int j = 0;
    for (int i = 0; i < 50; i++){
        scanf("%d",&z[i]);
        if (z[i] == -1){
          break;
        } else{
            p++;
        }
    }
    for (int i = 0; i < p; i++){
        if (z[i] != -1)
        a[i] = z[i];
    }
    
    for (int i = 1; i <= p; i++){
        if(a[i-1] < a[i]){
            int temp;
            temp = a[i -1];
            a[i -1] = a[i];
            a[i] = temp;
        }
    }
    for (int i = 0; i < p; i++){
        printf("%d,",a[i]);
    }
    for (int i = 0; i < p; i++){
        for (int m = 0; m < 4; m++){
        if(a[i] % 2 == 0){
            a[i] /= 10;
            j++;
        }}
        if(j == 4){
            x++;
        }
        j = 0;
    }
    
    printf("%d",x);
   
    return 0;
}

