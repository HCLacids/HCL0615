#include <stdio.h>
void adjust_point(int *n){
	if (*n < 0){
		*n = 0;
	}else if (*n > 100){
		*n =100;
	}
}

int main() {
	int n;
	printf("输入n:");
	scanf("%d",&n);
	adjust_point(&n);
	printf("%d\n",n);

	return 0;
}

