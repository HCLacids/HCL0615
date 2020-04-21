#include <stdio.h>

int main(void){
    int year,mon,day,i,j,k;
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("请输入年月日版\n");
    scanf("%d%d%d",&year,&mon,&day);
    j = 0;
    for(i = 0;i <= mon - 2;i++){
        j += a[i];
    }
    k = j+day;
    if((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && mon >= 3)
    printf("为%d年的第%d天",year,k+1);
    else
    printf("为%d年的第%d天",year,k);
}

/*#include <stdio.h>
int main(void){
    int year,month,day,sum=0;
    printf("请输入日期：");
    scanf("%d/%d/%d",&year,&month,&day);
    if (year%4==0)
    {
       if (month<3)
    {
        sum=31*(month-1)+day;
    }
    else if(8>month>3){
        if (month%2==0)
        {
            sum=60+(month/2-1)*31+(month/2-2)*30+day;
        }
        else
        {
             sum=60+(month-1/2-1)*31+(month-1/2-1)*30+day;
        }
    }
    else
    {
           if (month%2==0)
        {
            sum=213+(month/2-4)*31+(month/2-4)*30+day;
        }
        else
        {
             sum=213+(month-1/2-3)*31+(month-1/2-3)*30+day;
        }
    }
    }
    else
    {
         if (month<3)
    {
        sum=31*(month-1)+day;
    }
    else if(8>month>3){
        if (month%2==0)
        {
            sum=59+(month/2-1)*31+(month/2-2)*30+day;
        }
        else
        {
             sum=59+(month-1/2-1)*31+(month-1/2-1)*30+day;
        }
    }
    else
    {
           if (month%2==0)
        {
            sum=212+(month/2-4)*31+(month/2-4)*30+day;
        }
        else
        {
             sum=212+(month-1/2-3)*31+(month-1/2-3)*30+day;
        }
    } 
    }
   printf("这一天是该年的第%d天",sum);
    return 0;
}*/