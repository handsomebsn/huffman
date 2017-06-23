#ifndef ALL_H
#define ALL_H
#define NUMCOUNT 256
typedef char Ele;
typedef int Weight;
typedef struct{
Ele data;
Weight weight;
}Huffcell,Tongjicell,*ptrTongjicell;
typedef struct Treenode{
 Ele data;
 int weight;
 struct Treenode *left;
 struct Treenode *right;
 struct Treenode *parent;
}*Tree,*ptrTreenode;

typedef struct{
Ele codes[258];
int start;
}Huffcode,*ptrHuffcode;



#endif // ALL_H
