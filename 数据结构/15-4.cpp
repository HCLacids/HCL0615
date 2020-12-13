#include <iostream>
#define TElemType char
#define MAX_BITREE_SIZE 100
TElemType Nil = '#';
#include <cstdlib>
#include <stdlib.h>
using namespace std;
#include "BiTree.h"

int Num(BiTree Bi,int i,int &m){
    if(!Bi) return 0;
    if(m < i) m = i;
    return (1 + Num(Bi->lchild,2 * i, m) + Num(Bi->rchild,2 * i,m));
}

bool Check(BiTree Bi){
    int n,max= 0;
    n = Num(Bi, 1, max);
    if(n == max) return true;
    else return false;
}

int main() {
    BiTree Bi;
    InitBiTree(Bi);
    CreateBiTree(Bi);
    if(Check(Bi)) cout << 'y'<<endl;
    else cout<< 'n'<<endl;
}


