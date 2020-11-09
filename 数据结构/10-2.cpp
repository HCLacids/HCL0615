#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "DSqString.h"
using namespace std;

void Swap_String(DSqString &String,char a,char b){
    for (int i = 0; i < String.length; i++)
        if(String.str[i] == a) String.str[i] = b;
}

int main(){
    DSqString string;
    StrAssign_Sq(string,"hal hal hal");
    Swap_String(string,'a','c');
    StrTraveres_Sq(string);
    return 0;
}

