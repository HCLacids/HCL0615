#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int array[n][2];
	for (int i = 0; i< n;i++)
		for (int j = 0; j <2;j++)
			scanf("%d",&array[i][j]);
	for (int i = 0;i < n;i++){
		if (array[i][0]%array[i][1]==0)
			printf("true");
		else printf("false");
	}
	return 0;
}

