#include <stdio.h>

typedef struct student {
    char sId[10];
    char sName[5];
    char sSex;
    float sGrade;
}Stu;

void sort(Stu *st,int n){
    Stu *i,*j,t;
    for(i = st;i < st + n - 1;i++)
        for(j = i + 1;j < st + n;j++)
            if(i->sGrade < j->sGrade){t = *i;*i = *j;*j = t;}
}

int main (){
    Stu stu[145];
    FILE *fp,*fp1;
    fp = fopen("student.dat","aw");
    fwrite(stu,sizeof(Stu),145,fp);
    fclose(fp);
    fp1 = fopen("student.dat","r");
    for(int i = 0; i < 145;i++)
    fprintf(fp1,"\n%10s %5s %c %2.2d",stu[i].sId,stu[i].sName,stu[i].sSex,stu[i].sGrade);
    fclose(fp1);
    return 0;
}