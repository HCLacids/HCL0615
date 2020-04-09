#include <stdio.h>
int main(){
    int count_C = 0, count_N = 0, count_B = 0, count_E = 0,count_c = 0;
    char c[3][80];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 80; j++){
            if (c[i][j] >= 'a' &&  c[i][j] <= 'z'){
              count_c++;
            }else if(c[i][j] >= 'A' && c[i][j] <= 'Z'){
                count_C++;
            } else if(c[i][j] >= '0' && c[i][j] <= '9')
                count_N++;
            else if(c[i][j] == ' ')
            count_B++;
            else{
             count_E++;
            } 
          }
    }
    printf("大写字母：%d,小写字母：%d,数字：%d,空格：%d,其他字符：%d",count_C,count_c,count_N,count_B,count_E);
    return 0;
}