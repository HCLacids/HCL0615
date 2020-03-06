#include <stdio.h>
#define num 5
int main (){
    int a[num];
     for(int i = 0; i < num; i++){
       scanf("%d",&a[i]);
    }
    int *max;
    int *min;
    max = a;
    min = a;
    for(int i = 0; i < num; i++){
        if(a + i > max){
            max = a + i;
        }
    }
    for(int i = 0; i < num; i++){
        if(a + i < min){
            min = a + i;
        }
    }
    printf("max = %d min = %d\n",*max,*min);
    return 0;
}