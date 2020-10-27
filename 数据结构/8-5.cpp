#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>

typedef struct queue{
    ElemType  *queue;       
    int front;
    int rear;
    int queuesize;                         
    int incrementsize;
}SqQueue;

void initQueue(SqQueue &q,int quesize,int incrementsize){
    q.queue = (ElemType *)malloc(quesize*sizeof(ElemType));
    q.front = 0;
    q.rear = 1;
    q.queuesize=quesize;
    q.incrementsize = incrementsize;
}

void pushQueue(SqQueue &q,int x){
    if((q.rear+1)%q.queuesize == q.front) return;
    q.queue[q.rear++] = x;
    q.rear %= q.queuesize; 
}

void popQueue(SqQueue &q,int &x){
    if((q.front+1)%q.queuesize == q.rear) return;
    x = q.queue[q.front++];
    q.rear %= q.queuesize; 
}

int main(){
    SqQueue que;int x;
    initQueue(que,10,10);
    for (int i = 0; i < 10; i++){
    pushQueue(que,i);
}
for (int i = que.front+1; i < 9; i++){
    printf("%d,",que.queue[i]);
}
puts("\n");
popQueue(que,x);
printf("x为%d\n",x);
for (int i = que.front+1; i < 9; i++){
    printf("%d,",que.queue[i]);
}
return 0;
}
