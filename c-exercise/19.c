#include <stdio.h>

void f (int x){
	int a[4];
	int i;
	for(i = 0;i < 4;i++){
		a[i] = x % 10;
		x /= 10;
	}
	for(i = 0;i < 4;i++)
	printf("%d ",a[3 - i]);
}

int main(){
	int a;
	puts("请输入一个4位数：");
	scanf("%d",&a);
	if(a > 10000 || a < 999){
		puts("请重新输入一个4位数：");
		scanf("%d",&a);
	}
	f(a);
	return 0;
} 