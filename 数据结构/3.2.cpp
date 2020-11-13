#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "DSqString.h"
using namespace std;

void format(DSqString S1,DSqString &S2,DSqString &S3, int n){
    int i,j,x;
    if(n > S1.length) return;
    S2.str=(char *)malloc(n*sizeof(char));
    S3.str=(char *)malloc((S1.length-n)*sizeof(char));  
    for( i=0,j = 0;i<n;i++){
        if(S1.str[i] == ' '&& i == 0) ;
        S2.str[j++] = S1.str[i];
    }
    S2.length = j;
    for (x = 0 ; i < S1.length; i++){
        if(S1.str[i] == ' '&& i == 0) ;
        S3.str[x++] = S1.str[i];
    }
    S3.length = x;
}

int main(){
    DSqString s1,s2,s3;
    StrAssign_Sq(s1,"123459qwertyui");
    StrTraveres_Sq(s1);
    format(s1,s2,s3,9);
    StrTraveres_Sq(s2);
    StrTraveres_Sq(s3);
    return 0;
}
