#include<stdio.h>

void sort(int *a){
	int max = *a,min = *a,x,y;
	for(int i = 0;i < 10;i++){
		if(min > a[i]){
			min = a[i];
			x = i;
		}	
		else if(max < a[i]){
			max = a[i];
			y = i;
		}
	}	
	int first = *a;
	a[0] = min;
	*(a+x)= first;	
	int last = a[9];
	*(a+9)= max;
	*(a+y) = last;
}

int main(){
	int p[10] = {2,1,3,4,5,6,7,8,10,9};
	int *a = p;
	puts("enter ten nums:");
	//for(int i = 0;i < 10;i++)
	//scanf("%d",(a+i)); 
	sort(a);
	for(int i = 0;i < 10;i++)	
	printf("%d ",a[i]);
	return 0;
} 