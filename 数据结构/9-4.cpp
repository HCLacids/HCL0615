#include <stdio.h>
#include <iostream>
#include <cstdlib>
#define MAX 20
using namespace std;

typedef struct StackQueue{
    int space[MAX];
    int front,rear,top; // 队首指针 队尾指针 栈顶指针
}SQ;

void InitSQ(SQ &sq){
    sq.top = 0;
    sq.front = sq.rear = MAX - 1;
}

void EnQueue(SQ &sq,int e){
    if(sq.top == sq.rear) return ; //无多余空间
    sq.space[sq.rear--] = e;
}

void PushStack(SQ &sq,int e){
    if(sq.top == sq.rear) return ; //无多余空间
    sq.space[sq.top++] = e;
}

void traverseSQ(SQ sq){
    for(int i = 0; i< sq.top;i++)
        cout<<sq.space[i];
    cout<<endl;
    for (int i = sq.front; i > sq.rear; i--)
        cout<<sq.space[i];
}

int main(){
    SQ sq;
    InitSQ(sq);
    EnQueue(sq,2);
    EnQueue(sq,1);
    PushStack(sq,2);
    PushStack(sq,0);
    traverseSQ(sq);
    return 0;
}
