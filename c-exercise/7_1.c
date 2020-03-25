#include <stdio.h>
int main(){
    int count_C = 0, count_N = 0, count_B = 0, count_E = 0;
    char c;
    while ((c=getchar()) != EOF){
        if(c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        count_C++;
        else if(c >= '0' && c <= '9')
        count_N++;
        else if(c == ' ')
        count_B++;
        else{
            count_E++;
        }
    }
    printf("字母：%d,数字：%d,空格：%d,其他字符：%d",count_C,count_N,count_B,count_E);
    return 0;
}