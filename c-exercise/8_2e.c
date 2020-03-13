#include <stdio.h>
#define n 10
#define s 4
int average(int score[n][s]){
    int sum = 0;
    for(int i = 0; i < s; i++){
        sum += score[n][i];
    }
    return sum / s ;
}
float rate(int score[n][s],int x){
    int P = 0;
    for (int i = 0; i < n; i++){
        if(score[i][x] >=60){
            P++;
        }
    }
    return (double)P / n ;
}
int rate(int score[n][s],char name[],int x){
    int max = score[0][x];
     for (int i = 0; i < n; i++){
        if(score[i][x] > max){
            max = score[i][x];
            name[0] = name[i];
        }
    }
    return max;
}

int main(){
    int student[n][s];
    char name[n] = {};
    return 0;
}