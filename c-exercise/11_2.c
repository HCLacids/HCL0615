#include <stdio.h>

int main(){
    int  y = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < y; j++){
            printf(" ");
        }
        printf("*****\n");
        y++;
    }
    return 0;
}