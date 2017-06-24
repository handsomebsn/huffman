#ifndef Huffmantree_H
#define Huffmantree_H
#include"all.h"
#include<iostream>
#include<map>
using namespace std;
class Huffmantree
{
public:
   Tree gettree(){return this->tree;}
 Huffmantree();
 Huffmantree(const Tongjicell tongjis[],int n);
 Huffcode gethuffcode(Ele c);
 void travel(Tree tree);
private:
Tree tree;
map<Ele,ptrTreenode> yezis;
map<Ele,Huffcode> elehuffcode;
map<Huffcode,Ele> huffcodeele;
};

#endif // Huffmantree_H
