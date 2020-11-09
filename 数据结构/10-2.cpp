#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "DSqString.h"
using namespace std;

void DelString(DSqString &String, char c){
    int j = 0;
    for (int i = 0; i < String.length; i++){
        if(String.str[i] != c) String.str[j++] = String.str[i];
    }
    String.length = j;
}

int main(){
    DSqString string;
    StrAssign_Sq(string,"hcl hcl hcl");
    DelString(string, 'c');
    StrTraveres_Sq(string);
    return 0;
}
