#include "all.h"
void printbit(char c){
    int tmp=0x80;
    for(int j=0;j<8;j++)
    {
    if(c&tmp)
    std::cout<<1;
    else
      std::cout<<0;
    tmp=tmp>>1;
    }



}


int compare(ptrTreenode a,ptrTreenode b){


    return a->weight-b->weight;
}
int compare(int a, int b){


    return a-b;
}
