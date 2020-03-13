#include <stdio.h>
#define n 10
int main(){
    int num[n];
    for (int i = 0; i < n; i++){
      scanf("%d",&num[i]);
    }
    int x[n];
    int j = 0;
    int p = n - 1;
    for (int i = 0; i < n; i++){
        if (num[i] % 2){
            x[j]  = num[i];
            j++;
        }else{
           x[p] = num[i];
           p--;
        }
    }
     for (int i = 0; i < n; i++){
      printf("%d ",x[i]);
    }
    putchar('\n');
    return 0;
}