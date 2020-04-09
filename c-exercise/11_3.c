#include <stdio.h>
#include <string.h>

int main(){
    char s1[10], s2[10];
    gets(s1);
    gets(s2);
    int sum = 0;
    int sz1 = strlen(s1);
    int sz2 = strlen(s2);
    if(sz1 < sz2) sz1 = sz2 ;
    for (int i = 0; i < sz1; i++){
        sum += s1[i] - s2[i];
    }
    printf("%d",sum);
    return 0;
}