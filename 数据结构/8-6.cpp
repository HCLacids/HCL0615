#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#define size 100

typedef struct queue{
    ElemType  queue[100];       
    int front;
    int rear;
    int length;
}SqQueue;

void initQue(SqQueue &q){
    q.front=q.rear=0;
    q.length = 0;
}

void push(SqQueue &q, int x){
    if(q.rear==q.front&&q.length) return;
    q.length++;
    q.queue[q.rear]=x;
    q.rear=(q.rear+1)%size;
}

void pop(SqQueue &q, int &x){
    if(!q.length) return ;
    x = q.queue[q.front];
    q.length--;
    q.front=(q.front+1)%size;
}

int main(){
    SqQueue que;
    int x;
    initQue(que);
    for (int i = 0; i < 10; i++){  
        push(que,i);
    }
    for (int i = que.front; i < 10; i++){
        printf("%d,",que.queue[i]);
    }
    puts("\n");
    pop(que,x);
    printf("x is %d\n",x);
    for (int i = que.front; i < 10; i++){
        printf("%d,",que.queue[i]);
    }
    
    return 0;
    
}

