#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "LinkList.h"

int check(LinkList L,int x){
    int num = 0;
    while (L){
        if(L->data == x) num++;
        L = L->next;
    }
    return num;
}

int main(){
    LinkList List;
    InitList_L(List);
    for (int i = 0; i < 10; i++){
        ListInsert_L(List,i,i);
    }
    printf("%d",check(List,5));
    return 0;
}
