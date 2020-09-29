#include <stdio.h>
#define num 100

typedef struct student{
	char sid[10];
	char sname[10];
	char sex;
	float grades[30];
} STUDENT;

float s_average(STUDENT	students[], int index){
	float sum = 0;
	int i;
	for(i = 0; i < 30; i++){
		sum += students[index].grades[i];
	}
	return sum / 30;
}
float c_average(STUDENT	students[], int index){
	float sum = 0;
	int i;
	for(i = 0; i < 30; i++){
		sum += students[i].grades[index];
	}
	return sum / num;
}

int main(){
	STUDENT students[num];
	float saverage = s_average(students,0);
	float caverage = c_average(students,0);
	return 0;
}