#include<stdio.h>

void sort(int *a){
	int *max,*min;
	min = max = a;
	int i,x,y;
	for(i = 0;i < 10;i++)
		if(min > *(a + i))
			min = a + i,x = i;
	for(i = 0;i < 10;i++)
		if(max < *(a + i))
			max = a + i,y = i;
	int *temp1 = 0,*temp2 = 0;
	temp1 = a + 9;
	a + 9= max;
	a + y = temp1;
	temp2 = a;
	a = min;
	a + x = temp2;
}

int main(){
	int *a;
	int i;
	puts("enter ten nums:");
	for(i = 0;i < 10;i++)
	scanf("%d ",a + i); 
	sort(a);
	for(i = 0;i < 10;i++)	
	printf("%d ",*(a + i));
	return 0;
} 