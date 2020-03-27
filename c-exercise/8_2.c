#include <stdio.h>
int main(){
    int n =1,m = 7;
    for (int i = 1; i <= 7; i++){
       if (i <= 4){
          for (int j = 1;j <= 4-i; j++){
              printf(" ");
          }
          for (int j = 1;j <= n; j++){
              printf("*");
          }
          for (int j = 1;j <= 4-i; j++){
              printf(" ");
          }
             n += 2;
       }
       if (i > 4)
       {
           for (int j = 1;j <= i - 4; j++){
              printf(" ");
          }
            for (int j = 2;j < m; j++){
              printf("*");
          }
          for (int j = 1;j <= i - 4; j++){
              printf(" ");
          }
          m -= 2;
       }
       printf("\n");
    }
    return 0;
}