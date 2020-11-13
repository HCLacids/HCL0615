#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "DSqString.h"
using namespace std;

void count_char(DSqString string){
    int AtoZ[26] = {0};
    int number[10] = {0};
    for (int i = 0; i < string.length; i++){
        if(string.str[i] >= 'A' && string.str[i] <= 'Z'){
            AtoZ[string.str[i] - 'A']++;
        }
        else if(string.str[i] >= '0' && string.str[i] <= '9'){
            number[string.str[i] - '0']++;
        }
    }
    cout<<"出现的字母有："<<endl;
    for (int i = 0; i < 26; i++){
        if(AtoZ[i]) printf("%c的个数为%d\n",i + 65,AtoZ[i]);
    }
    cout<<"出现的数字有："<<endl;
    for (int i = 0; i < 10; i++){
        if(number[i]) cout<<i<<"的个数为"<<number[i]<<endl;
    }
}

int main(){
    DSqString str;
    StrAssign_Sq(str,"1234567890ASDFSAF");
    StrTraveres_Sq(str);
    count_char(str);
    return 0;
}
