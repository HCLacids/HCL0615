#include <stdio.h>
#define num 35

typedef struct student{
    char sId[10];
    float sGrade[4];
    float average;
    float sum;
}STU;

void personal_average(STU student[]){
    for (int i = 0; i < num; i++){
        student[i].sum = 0;
        for (int j = 0; i < 4; j++){
            student[i].sum += student[i].sGrade[j];
        }
        student[i].average = student[i].sum / 4;
    }
}

void sort(STU *st,int n){
    STU *i,*j,t;
    for(i = st;i < st + n - 1;i++)
        for(j = i + 1;j < st + n;j++)
            if(i->sum < j->sum){t = *i;*i = *j;*j = t;}
}

void require (STU student[],int n){
    for (int i = 0; i < num; i++){
        if (student[i].sGrade[n] >= 90){
            printf("%s %2.2d %2.2d %2.2d %2.2d %2.2d %2.2d",student[i].sId,student[i].sGrade[0],student[i].sGrade[1],student[i].sGrade[2],student[i].sGrade[3],student[i].sum,student[i].average);
        }
    }
     STU *i,*j,t;
      for(i = student;i < student + n - 1;i++)
        for(j = i + 1;j < student + n;j++)
            if(i->sGrade[n] < j->sGrade[n]){t = *i;*i = *j;*j = t;}
    for (int i = 0; i < 5; i++){
        printf("%s %2.2d %2.2d %2.2d %2.2d %2.2d %2.2d",student[i].sId,student[i].sGrade[0],student[i].sGrade[1],student[i].sGrade[2],student[i].sGrade[3],student[i].sum,student[i].average);
    }
}

int main(){
    STU student[num];
    FILE *fp;
    fp=fopen("stud.dat","aw");
    fwrite(student,sizeof(STU),num,fp);
    fclose(fp);
    return 0;
}