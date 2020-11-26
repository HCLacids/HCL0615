#define  ElemType int
#include <iostream>
using namespace std;
#include "TSMatrix.h"


ElemType add(TSMatrix ts){
    ElemType sum = 0;
    for (int k = 0; k < ts.t; k++){
        if(ts.data[k].i == ts.data[k].j)
            sum+=ts.data[k].e;
    }
    return sum;
}


int main(){
    TSMatrix ts;
    CreateSMatrix(ts);
    cout<<add(ts)<<endl;
    return 0;
}
