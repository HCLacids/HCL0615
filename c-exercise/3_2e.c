#include <stdio.h>

int main(){
    int x;
    printf("请输入百分制成绩");
    scanf("%d",&x);
    if (x < 0 || x > 100){
        printf("请输入百分制成绩");
        scanf("%d",&x);
    }
    /*
    do{
    printf("请输入百分制成绩");
    scanf("%d",&x);
    }while(x >= 0 && x <= 100)
    */
  /* if ( x >=90 && x <=100){
       printf("成绩%d 等级A",x);
   }
   if ( x >=80 && x <=89){
       printf("成绩%d 等级B",x);
   }
   if ( x >=70 && x <=79){
       printf("成绩%d 等级C",x);
   }
   if ( x >=60 && x <=69){
       printf("成绩%d 等级D",x);
   }
   if (x < 60){
       printf("成绩%d 等级E",x);
   }*/
   
   switch(x / 10){
       case 10 : printf("成绩%d 等级A",x);
       case 9 : printf("成绩%d 等级A",x); break;
       case 8 : printf("成绩%d 等级B",x); break;
       case 7 : printf("成绩%d 等级C",x); break;
       case 6 : printf("成绩%d 等级D",x); break;
       default : printf("成绩%d 等级E",x); break;
   }
   return 0 ;
}