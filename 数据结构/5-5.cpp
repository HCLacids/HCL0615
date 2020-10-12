#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "LinkList.h"

void reverse(LinkList &L){
    if(L == NULL || L->next == NULL || L->next|| L->next->next == NULL) return ;
    LNode *old, *new_head ,*temp;
    new_head = NULL;
    while(old){
        temp = old->next;
        old->next = new_head;
        new_head = old;
        old = temp;
    }
    L = new_head;
}

int main(){
    LinkList List;
    InitList_L(List);
    for (int i = 0; i < 10; i++){
        ListInsert_L(List,i,i);
    }
    reverse(List);
     for (int i = 0; i < 10; i++){
        printf("%d",List->data);
        List = List ->next;
    }
    return 0;
}
