#include <stdio.h>
int main(){
    int score[5][6];
    char name[5] = {"张大明","李小红","王志强","汪晓成","李丹"};
    for(int i;i < 5; i++){
        for(int j; j < 4; j++){
            score[i][4] += score[i][j];
        }
    }
   for (int p = 0; p < 4; p++){
        for (int i = 1; i <= 5; i++){
            if(score[i - 1] < score[i][4]){
            int temp = score[i][4];
            score[i][4] = score[i - 1][4];
            score[i -1][4] = temp;
            int t = name[i -1];
            name[i -1] = name[i];
            name[i] = t;
        }
            if(score[i - 1][4] = score[i][4]){
                if(score[i - 1][0] + score[i - 1][1] < score[i][0] + score[i][1]){
                int temp = score[i][4];
                score[i][4] = score[i - 1][4];
                score[i -1][4] = temp;
                int t = name[i -1];
                name[i -1] = name[i];
                name[i] = t;
                }
        }
    }
    }
   
    for (int i = 1; i <= 5; i++){
        int x = 1;
        if (score[i][4] != score[i-1][4]){
            x++;
        }
       printf("No%d:%c,%d",x,name[i],score[i][4]);
    }
    return 0;
}