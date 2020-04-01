#include <stdio.h>

int main(){
    int a[5]= {1,2,4,5,6};
    int x;
    scanf("%d",&x);
    for (int i = 0; i < 5; i++){
        if (x > a[i] && x < a[i + 1]){
            printf("%d%d",a[i],x);
        }else{
            printf("%d",a[i]);
        }
    }
    return 0;
}