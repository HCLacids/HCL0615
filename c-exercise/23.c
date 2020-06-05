#include <stdio.h>

typedef struct student{
    char id[10];
    char name[5];
    float score[3];
}STU;

void subject_average(STU student[], int class_id, float average[]){
    float sum = 0;
    for (int i = 0; i < 10; i++){
        sum += student[i].score[class_id];
    }
    average[class_id] = sum / 10.0;
}

void top(STU student[], int class_id){
    STU *t;
    t = student;
    for (int i = 0; i < 10; i++){
        if(t->score[class_id] < student[i].score[class_id]){
            t = student + i;
        }
    }
}

int main(){
    STU student[10];
    float subjectAverage[3];
    subject_average(student,1,subjectAverage);
    return 0;
}