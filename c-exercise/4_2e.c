#include <stdio.h>
int main (){
        for (int j = 1; j <=9; j += 1){
            for(int i = 9 - j; i > 0 ; i--){
                printf(" ");
            }
            for(int p = 1; p < j; p++){
                printf("%d",p);
            }
             for(int p = j; p >= 1; p--){
                printf("%d",p);
            }
            putchar('\n');
        }
    
    return 0;
}