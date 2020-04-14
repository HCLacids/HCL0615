#include<stdio.h>
int main(){
	int a[10],i,j,n;
	printf("输入10个数："); 
	for(i = 0;i < 10;i++)
	scanf("%d",&a[i]);
	for(i = 0;i < 10;i++)
	for(j = i;j < 10;j++){
		if(a[i] > a[j]){
            n = a[i];
		    a[i] = a[j];
		    a[j] = n;}
	}
	printf("该十个数升序为： ");
	for(i = 0;i < 10;i++)
	printf("%2d",a[i]);
    return 0;
 } 