#include <stdio.h>

int main(){
    int array[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int key;
    scanf("%d",&key);
    int low = 0,hight = 14;
    int mid;
    while (low <= hight){
        mid = (low + hight) / 2;
        if (key == array[mid]){
            printf("%d",mid + 1);
        }else if (key > array[mid]){
            low = mid;
        }else{
            hight = mid;
        }
    }
    return 0;
}