#include <stdio.h>
#define num 100

double max(double *score, int n){
	double max = *score;
	for(int i = 0; i < n; i++)
		if(*(score + i) > max)
			max = *(score + i);
	return max;
}

float rate(double *score, int n){
	float x = 0;
	for(int i = 0; i < n; i++)
		if(*(score + i) >= 60 )
			x++;
	return x / n;
}

void sort(double *score, int n){
	for(int i = 0; i < n - 1;i++){
		for(int j = i; j < n;j++){
			if(*(score + j) < *(score + j + 1)){
				int t = *(score + j);
			 	*(score + j) = (score + j + 1);
			 	*(score + j + 1) = t;
			}
		}
	}
}

int main(){
	double *score;
	printf("请输入100个学生C语言成绩：");
	for(int i = 0; i < num; i++)
		scanf("%f",score + i);
	printf("最高分为：%f\n",max(score,num));
	printf("及格率为：%f\n",rate(score,num));
	printf("分数排序为：\n");
	sort();
	for(int i = 0; i < num; i++)
		printf("%f\n",*(score + i));
	return 0;
}
