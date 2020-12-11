#include <iostream>
#define TElemType char
#define MAX_BITREE_SIZE 100
TElemType Nil = '#';
#include <cstdlib>
#include <stdlib.h>
using namespace std;
#include "BiTree.h"

void Count(BiTree BT,int &count){     
   if(BT){          
    if(!BT->lchild&&!BT->rchild) count++;
    else {
        Count(BT->lchild,count);
        Count(BT->rchild,count);
    }
   }
 }

 int main(){
    BiTree Bi;
    int count = 0;
    InitBiTree(Bi);
    CreateBiTree(Bi);
    Count(Bi,count);
    cout<<count<<endl;
}
