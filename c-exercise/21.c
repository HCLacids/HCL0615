#include <stdio.h>

typedef struct date{
    int year;
    int month;
    int day;
} Date;

int count_date(Date *date){
    int i,j,k;
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    j = 0;
    for(i = 0;i <= (*date).month - 2;i++){
        j += a[i];
    }
    k = j + (*date).day;
    if(((*date).year % 4 == 0 &&(*date).year % 100 != 0 || (*date).year % 400 == 0) && (*date).month >= 3)
    return k + 1;
    else
    return k;
}

void main(){
    Date date;
    printf("请输入年月日\n");
    scanf("%d %d %d",&date.year,&date.month,&date.day);
    printf("%d天",count_date(&date));
}