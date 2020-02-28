#include <stdio.h>

int main() {
	float p = 1.00, r = 0.09;
	int n = 10;
	for (int i = 0; i < n; i++){
		p *= (1 + r); 
	}
	printf("p = %d%%\n",(int)(p*100));
	return 0;
}
