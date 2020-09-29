#include <stdio.h>
#define num 5

int main(){
	int i,j;
	int a[num][num];
	//构建5行5列的二维数组 
	for(i = 0; i < num; i++){
		for(j = 0;j < num; j++){
			if(j == i){
				a[i][j] = 1;
			}
			else{
				a[i][j] = 0;
			}
		}
	}
	//输出二维数组
	for(i = 0; i < num; i++){
		for(j = 0; j < num; j++){
			printf("%d",a[i][j]);
		}
		puts("\n");
	} 
	return 0;
} 