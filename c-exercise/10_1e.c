#include <stdio.h>
#include <string.h>

struct individual{
    int num[10];//学号
    char name[10][8]; //姓名
    char sex[10]; //性别
    int age[10];
    int grade[10];
};

struct temp{
    int num;
    char name[8];
    char sex;
    int age;
    int grade;
};

int main(){
    struct individual student;
    for(int i = 0; i < 10;i++){
        scanf("%d%s%c%d%d",student.num,student.name[i],student.sex,student.age,student.grade);
    }
     for(int i = 0; i < 10;i++){
        printf("%d%s%c%d%d",student.num[i],student.name[i],student.sex[i],student.age[i],student.grade[i]);
    }
    for(int i = 0; i < 9;i++){
        for(int j = 0; j <9 - i;j++){
            if(student.grade[j] > student.grade[j + 1]){
                struct temp t;
                t.age = student.age[j];
                t.grade = student.grade[j];
                strcpy(t.name,student.name[j]);
                t.num = student.num[j];
                t.sex = student.sex[j];
                student.age[j + 1] = student.age[j];
                student.grade[j + 1] = student.grade[j];
                strcpy(student.name[j + 1], student.name[j]);
                student.num[j + 1] = student.num[j];
                student.sex[j + 1] = student.sex[j];
                student.age[j] = t.age;
                student.grade[j] = t.grade;
                strcpy(student.name[j], t.name);
                student.num[j] = t.num;
                student.sex[j] = t.sex;
            }
        }
    }
     for(int i = 0; i < 10;i++){
        printf("%d%s%c%d%d\n",student.num[i],student.name[i],student.sex[i],student.age[i],student.grade[i]);
    }
    return 0;
}