#include <stdio.h>
#include <math.h>
int Mysqrt (int n){
    int i;
    for (i = 0;i*i<=n;i++);
    return i -1;
}
int main(){
    int a;
    scanf("%d",&a);
    if(a < 0 || a > 1000){
        printf("请重新输入：");
        scanf("%d",&a);
    }else{
        printf("%d\n",Mysqrt(a));
    }
    return 0;

}