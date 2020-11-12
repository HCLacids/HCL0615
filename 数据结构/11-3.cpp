#define ElemType char
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "LinkList.h"
using namespace std;
void DelChar (LinkList &String,char ch){
    LinkList q,p = String;
    while (p->next){
        if(p->next->data == ch){
        q = p->next;
        p->next = q->next;
        free(q);
        }
       else p = p->next;
    }
}
int main(){
    LinkList str;
    InitList_L(str);
    int x,i=1;
    char ch;
    cin>>x;
    while (x){
        cin>>ch;
        ListInsert_L(str,i,ch);
        i++;
        cin>>x;
    }
    ListTraverse_L(str);
    cout<<"删除的为:";
    cin>>ch;
    DelChar(str,ch);
    ListTraverse_L(str);
    return 0;
}
