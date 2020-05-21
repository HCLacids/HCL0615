#include<stdio.h>

void sort_three(int *a,int *b,int *c){
	if(*a > *b){
		int temp = *b;
		*b =* a;
		*a = temp;
	}
	if(*b > *c){
		int temp = *c;
		*c =* b;
		*b = temp;
	}
	if(*a > *b){
		int temp = *b;
		*b =* a;
		*a = temp;
	}
}

int main(){
	int a,b,c;
	puts("enter three nums:");
	scanf("%d,%d,%d",&a,&b,&c);
	sort_three(&a,&b,&c);	
	printf("%d,%d,%d",a,b,c);
	return 0;
} 