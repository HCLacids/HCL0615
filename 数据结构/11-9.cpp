#define ElemType char
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include "LinkList.h"
using namespace std;
void SwapChar (LinkList &String,char ch,char ch2){
    LinkList q,p = String;
    while (p){
        if(p->data == ch)
            p->data = ch2;
        p = p->next;
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
    cout<<"交换的为:"<<endl;
    SwapChar(str,'a','c');
    ListTraverse_L(str);
    return 0;
}
