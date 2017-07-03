#ifndef ALL_H
#define ALL_H
#define NUMCOUNT 256
#define BUFFNUM 4096
#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
typedef char Ele;
typedef int Weight;
typedef struct{
Ele data;
Weight weight;
}Tongjicell,*ptrTongjicell;
typedef struct Treenode{
 Ele data;
 int weight;
 struct Treenode *left;
 struct Treenode *right;
 struct Treenode *parent;
}*Tree,*ptrTreenode;

typedef string Huffcode,*ptrHuffcode;

void printbit(char c);
string charbit(char c);
int compare(ptrTreenode a,ptrTreenode b);
int compare(int a,int b);
long getfilesize(const char *filename);
#endif // ALL_H
