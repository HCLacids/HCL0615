#include <stdio.h>
int main(){
    int M,F,C;
    for(M = 0; M <=100;M++){
        for(F= 0;F <= 100;F++ ){
            for(C  = 0;C <= 100;C++){
                if (5*M + 3*F + C/3 == 100 && M + F + C == 100)
                    printf("%d,%d,%d\n",M,F,C);
            }
        }   
    }
  return 0;
}