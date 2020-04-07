#include <stdio.h>

void xstrcat()
{
    int str1[10];
    int str2[10];
    int i,len1;
    for(i=0;str1[i]!='\0';i++);
        len1=i;
    for(i=0;str2[i]!='\0';i++)
        str1[i+len1]=str2[i];
}