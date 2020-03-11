#include <stdio.h>

int main(){
    int p[17] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
    int x = 0;
    for(int j = 0; j < 17 ; j++){
     for (int i = 0; i < 17; i++){
        if (p[i] != 0){
            x++;
        }
        if(x == 7){
            printf("%d ",p[i]);
            p[i] = 0;
            x = 0;
        }
    }
    }
    return 0;
}