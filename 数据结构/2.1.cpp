#define  ElemType int
#define MAX 100
#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct {
    ElemType queue[MAX];
    int front;
    int count;
}QueueType;

void initQue(QueueType &que){
    que.front = 0;  //队首指针指向开头
    que.count = 0; //计数为0
} //队列初始化

void pushQue(QueueType &que,ElemType x){
    if(que.count >= MAX) return ; //判满
    que.queue[que.count++] = x; //进队
}//进队

void popQue(QueueType &que,ElemType &x){
    if(que.count == 0) return ; //判空
    x = que.queue[que.front++]; //出队
} //出队

void getQue(QueueType &que,ElemType &x){
    if(que.count == 0) return ; //判空
    x = que.queue[que.front]; //取队头元素
} //取队头元素

bool IsEmpty(QueueType &que){
    return que.count ? true : false ; //判空
}//判空

int main(){
    int x;
    QueueType q;
    initQue(q);
    for (int i = 0; i < 10; i++){
        pushQue(q,i);
    }
    popQue(q,x);
    cout<<x<<endl;
    getQue(q,x);
    cout<<x<<endl;
    popQue(q,x);
    cout<<x<<endl;
    if(IsEmpty(q)) cout<<"not empty"<<endl;

    return 0;
}
