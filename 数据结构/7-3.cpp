#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "SqStack.h"

int main(){
    SqStack stack;
    int x;
    InitStack_Sq(stack,10,10);
    for (int i = 0; i < 10; i++){
        scanf("%d",&x);
        Push_Sq(stack,x);
    }
    for (int i = 0; i < 10; i++){
        Pop_Sq(stack,x);
        printf("%d",x);
    }
    return 0;
}
