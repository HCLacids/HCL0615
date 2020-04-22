#include <stdio.h>

struct student{
    int num;
    char name[8];
    char sex;
    int age;
    int grade;
};

typedef struct list{
     int num;
    char name[8];
    char sex;
    int age;
    int grade;
    struct list *next;
}List;


int main(){
    struct student stu[10] = {
        {101,"Zhang","M",19,95.6},
        {102,"Wang","F",18,92.4},
        {103,"Zhao","M",19,85.7},
        {104,"Li","M",20,96.3},
        {105,"Gao","M",19,90.2},
        {106,"Lin","M",18,91.5},
        {107,"Ma","F",17,98.7},
        {108,"Zhen","M",21,90.1},
        {109,"Xu","M",19,89.8},
        {110,"Mao","F",18,94.9}};
    for(int i = 0; i < 9;i++){
        for(int j = 0; j <9 - i;j++){
            if(stu[j].grade > stu[j + 1].grade){
                struct student t;
                t.age = stu[j].age;
                t.grade = stu[j].grade;
                strcpy(t.name,stu[j].name);
                t.num = stu[j].num;
                t.sex = stu[j].sex;
                stu[j + 1].age= stu[j].age;
                stu[j + 1].grade = stu[j].grade;
                strcpy(stu[j + 1].name, stu[j].name);
                stu[j + 1].num = stu[j].num;
                stu[j + 1].sex = stu[j].sex;
                stu[j].age = t.age;
                stu[j].grade = t.grade;
                strcpy(stu[j].name, t.name);
                stu[j].num = t.num;
                stu[j].sex = t.sex;
            }
        }
    }
    List *p =(List*)malloc(sizeof(List));
    List *temp = p;
    for (int i = 0; i < 10; i++){
        List *a =(List*)malloc(sizeof(List));
        a ->age = stu[i].age;
        a ->grade = stu[i].grade;
        strcpy(a -> name,stu[i].name);
        a ->num = stu[i].num;
        a ->sex = stu[i].sex;
        a ->next = NULL;
        a -> next = temp -> next;
        temp ->next = a; 
    }
}
        

    
