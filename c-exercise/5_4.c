#include <stdio.h>
/*int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int max = a;
    if (b > max) max = b;
    if (c > max) max = c;
    printf("%d",max);
    return 0;
}*/
#define num 3
int main(){
    int a[num];
    for(int i = 0;i < num; i++ ){
        scanf("%d",a+i);
    }
int *max = a;
for (int i = 0;i < num;i++){
    if(a[i] > *max) max = a + i;
}
printf("%d\n",*max);
return 0;
}