#define  ElemType int
#define MAX 10
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "SqStack.h"

using namespace std;

int main(){
    SqStack stack_one,stack_two;
    InitStack_Sq(stack_one);
    InitStack_Sq(stack_two);
    int x;
    for (int i = 0; i < MAX; i++){
        int a = rand();
        if(a % 2) Push_Sq(stack_one,a); //奇数
        else Push_Sq(stack_two,a); //偶数
    }
    cout<<"odd numbers are:";
    while (Pop_Sq(stack_one,x)){
        cout<<x<<endl;
    }
    cout<<"even numbers are:";
    while (Pop_Sq(stack_two,x)){
        cout<<x<<endl;
    }
    return 0;
    
}
