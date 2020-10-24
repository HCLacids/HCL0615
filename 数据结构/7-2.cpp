#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "LinkList.h"
using namespace std;

void Initiate(LinkList &head){
    if(!(head=(LNode *)malloc(sizeof(LNode))))
        exit(1);
    head->next = head;
}

bool Append(LinkList &head, ElemType x){
    LinkList p;
    if(!(p = (LNode *)malloc(sizeof(LNode)))) return false;
    p->data = x;
    p->next = head->next;
    head->next = p;
    head = p;
    return true;
}

bool Delete(LinkList &head, ElemType &d){
    LinkList front,p;
    front = head->next;
    if(front->next == front) return false;
    else{
        p = front->next;
        d = p->data;
        front->next = p->next;
        free(p);
        return true;
    }
}

void print(LinkList node,int x){
	int i;
	for(i = 0;i < x;i++){
		node = node->next;
		printf("%d",node->data);
	}
puts("\n");
}

int main(){
    int x;
    LinkList head;
    Initiate(head);
    Append(head,1);
    Append(head,2);
    print(head,3);
    Delete(head,x);
    printf("%d\n",x);
    print(head,2);
    return 0;
}
