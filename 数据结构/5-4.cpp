#define  ElemType int
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "SqList.h"

using namespace std;

void delete_range(SqList &List, int s, int t){
    if(s > t || s >= List.length || !List.length) return;
    while (List.elem[t - 1]){
        List.elem[s++] = List.elem[t++];
        List.length += s-t-1;
    }
}

int main(){
    SqList list;
    InitList_Sq(list,10,10);
    for (ElemType i = 0; i < 10; i++){
        list.elem[i] = i;
    }
    delete_range(list,2,3);
    for (ElemType i = 0; i < 8; i++){
        printf("%d",list.elem[i]);
    }
    puts("\n");
    return 0;
}
