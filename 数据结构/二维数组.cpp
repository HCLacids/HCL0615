#include <stdio.h>
#define num 5

int main(){
	int i,j;
	int a[num][num];
	//����5��5�еĶ�ά���� 
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
	//�����ά����
	for(i = 0; i < num; i++){
		for(j = 0; j < num; j++){
			printf("%d",a[i][j]);
		}
		puts("\n");
	} 
	return 0;
} 