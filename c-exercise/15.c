#include <stdio.h>

char *strncath(char *a,char *b){
        char *p = a;
        while (*a)
        a++;
        while (*a++ = *b++);
        return p;
}

char *strcpyh(char *a,char *b){
    while (*a++){
        if(*a == 'a' || *a == 'e' || *a == 'i' || *a == 'o' || *a == 'u')
            *b++ = *a;
    }
    return b;
}

void strcnth(char *str,int *A,int *N,int *B,int *E){
    while (*str++){
        if (*str >= 'a' && *str <= 'z' || *str >= 'A' && *str <= 'Z') (*A)++;
        else if(*str >= 0 && *str <= 9) (*N)++;
        else if(*str == ' ') (*B)++;
        else (*E)++;
    }
}