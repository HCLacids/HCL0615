#include <stdio.h>
#include <string.h>

typedef struct student{
	char name[10];
	float score[5];
}Student;

float Student_average(float score[],float n){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += score[i];
	}
	return sum / n;
}

float Subject_average(Student student[],float n, int *class_name){
	float sum = 0;
	for(int i = 0; i < n; i++){
		sum += student[i].score[*class_name];
	}
	return sum / n;
}

void Max_score(Student student[],float *max_score,int *class_name, char student_name[]){
	float max[10] = {0};
	int  subject[10] = {0};
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 5; j++){
			if (student.score[j] > max[i]){
				max[i] = student.score[j];
				subject[i] = j;
			}
		}
	}
	*max_score = max[0];
	for(int i = 0; i < 10; i++){
		if(max[i] > *max_score)
			*max_score = max[i];
			strcpy(student_name,student[i].name);
			*class_name = subject[i];
	}
}

int main(){
	Student stu[10];
	for(int i = 0; i <10 ; i++){
		scanf("%s",stu[i].name);
		for(int j = 0; j < 5; j++){
			scanf("%.2f",stu[i].score[j]);
		}
	}
	return 0;
}