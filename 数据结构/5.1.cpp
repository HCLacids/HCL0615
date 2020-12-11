#include <iostream>
#define TElemType char
#define MAX_BITREE_SIZE 100
TElemType Nil = '#';
#include <cstdlib>
#include <stdlib.h>
using namespace std;
#include "BiTree.h"

void Count_ALL(BiTree BT,int &count){     
   if(BT){ 
    count++;            
    if(BT->lchild)Count_ALL(BT->lchild,count);           
    if(BT->rchild)Count_ALL(BT->rchild,count);
   }
}

void Count_Child(BiTree BT,int &count){     
   if(BT){          
    if(!BT->lchild&&!BT->rchild) count++;
    else {
        Count_Child(BT->lchild,count);
        Count_Child(BT->rchild,count);
    }
   }
 }

int main(){
    BiTree Bi;
    int count_all = 0, count_child = 0;
    InitBiTree(Bi);
    CreateBiTree(Bi);
    Count_ALL(Bi,count_all);
    cout<<count_all<<endl;
    Count_Child(Bi,count_child);
    cout<<count_child<<endl;
    PrintBiTree(Bi,1);
}
