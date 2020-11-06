#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "SqQueue.h"
#include "SqStack.h"

using namespace std;

void reverse_que(SqStack Stack,SqQueue &Queue){
    int temp; 
    while (DeQueue_Sq(Queue,temp)){ //出队
        Push_Sq(Stack,temp); //进栈
    }
    while (Pop_Sq(Stack, temp)){//出栈
        EnQueue_Sq(Queue,temp);//进队
    }
}

int main(){
    SqStack s;
    SqQueue q;
    InitQueue_Sq(q);
    InitStack_Sq(s);
    int x;
    for (int i = 0; i < 10; i++){
        EnQueue_Sq(q,i); //进队
    }
    for (int i = 0; i < 10; i++){
        cout<<q.queue[i]; //遍历
    }
    cout<<endl;
    reverse_que(s,q);
    for (int i = 0; i < 10; i++){
        DeQueue_Sq(q,x); //出队
        cout<<x;
    }
    cout<<endl;
    return 0;
}
