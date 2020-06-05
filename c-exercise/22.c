#include <stdio.h>

typedef struct student{
    long num;
    char name[5];
    float score[3];
} STU;

void print (STU *student,int n){
    for(int i = 0; i < n;i++){
        printf("%ld %s",student->num,student->name);
        for (int j = 0; i < 3; j++){
            printf("%f",student->score[i]);
        }
    }
}

void input(STU *student,int n){
    for(int i = 0; i < n;i++){
        scanf("%ld %s",student->num,student->name);
        for (int j = 0; i < 3; j++){
            scanf("%f",student->score[i]);
        }
    }
}

int main (){
    STU student[5];
    printf(student,5);
    input(student,5);
    return 0;
}