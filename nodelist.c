#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    char sid[10];
    char sname[10];
    int sage;
    float c_grade;
    struct node* next;
} Student;

Student* create(){
    Student *p,*head,*q;
    int plot;
    q = head = (Student*)malloc(sizeof(Student));
    scanf("%s,%s,%d,%f",head->sid,head->sname,&(head->sage),&(head->c_grade));
    puts("是否创建结点? 是：1，否：0");
    scanf("%d",&plot);
    while (plot){
        p=(Student*)malloc(sizeof(Student));
        scanf("%s,%s,%d,%f",p->sid,p->sname,&(p->sage),&(p->c_grade));
        q->next = p;
        q = p;
        puts("是否继续创建结点? 是：1，否：0");
        scanf("%d",&plot);
    }
    p->next = NULL;
    return head;
}

void print(Student *List){
    while (List->next != NULL){
        printf("%s,%s,%d,%f\n",List->sid,List->sname,List->sage,List->c_grade);
        List = List->next;
    }
    printf("%s,%s,%d,%f\n",List->sid,List->sname,List->sage,List->c_grade);
}

void c_average(Student *List){
    float sum = 0,num = 1;
    while (List->next != NULL){
        sum += List->c_grade;
        List = List->next;
        num++;
    }
    sum += List->c_grade;
    printf("%f", sum / num);
}

int main(){
    Student *students;
    students=create();
    print(students);
    c_average(students);
    return 0;
}
