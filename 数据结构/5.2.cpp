#include <iostream>
#define TElemType char
#define MAX_BITREE_SIZE 100
TElemType Nil = '#';
#include <cstdlib>
#include <stdlib.h>
using namespace std;
#include "BiTree.h"

bool SearchBST(BiTree Bi, TElemType key, BiTree &f, BiTree &p){
    f = NULL;
    p = Bi;
    while(p && p->data != key){
        f = p;
        if(key < p->data) p = p->lchild;
        else p = p->rchild;
    }
    if(!p) return false;
    else return true;
}


bool InsertBST(BiTree &Bi, TElemType e){
    BiTree p,f,r;
    if(!SearchBST(Bi, e,f,p)){
        r = (BiTree)malloc(sizeof(BiTNode));
        r->data = e;
        r->lchild = NULL;
        r->rchild = NULL;
        if(!Bi) Bi = r;
        else if(e < f->data) f->lchild = r;
        else f->rchild = r;
        return true;
    }
    else return false;
}

void CreateOrderBiTree(BiTree &Bi,TElemType test[], int n){
    Bi = NULL;
    for (int i = 0; i < n; i++) {
        InsertBST(Bi, test[i]);
    }
}

void visit(TElemType e){
    cout << e << ' ';
}

int main(){
    BiTree Bi;
    char a[10] = "asdfghjkl";
    CreateOrderBiTree(Bi, a, 10);
    InOrderBiTree(Bi,visit);
}