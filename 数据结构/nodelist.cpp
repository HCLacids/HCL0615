#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    char sid[10];
    char sname[10];
    int sage;
    float c_grade;
    struct node *next;
} Student;

Student *create(){
    Student *p,*head,*end;
    int plot;
    head = (Student*)malloc(sizeof(Student));
    end = head; 
    puts("????????? ???1????0");
    scanf("%d",&plot);
    while (plot){
        p=(Student*)malloc(sizeof(Student));
        scanf("%s %s %d %f",p->sid,p->sname,&(p->sage),&(p->c_grade));
        end->next = p;
        end = p;
        puts("?????????????? ???1????0");
        scanf("%d",&plot);
    }
    end->next = NULL;
    return head;
}

void print(Student *List){
    while (List->next != NULL){
        printf("%s %s %d %f\n",List->sid,List->sname,List->sage,List->c_grade);
		List = List->next; 
    }
}

void c_average(Student *List){
    float sum = 0,num = 0;
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