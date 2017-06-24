#include "huffmantree.h"
#include"heap.h"
Huffmantree::Huffmantree(){
int n;
char c;
int weight;
cout<<"please enter chars number\n";
cin>>n;
Heap<ptrTreenode> heap(NUMCOUNT);
heap.setcompare(compare);
for(int i=0;i<n;i++){
   cin>>c>>weight;
   ptrTreenode newnode=new Treenode;
   newnode->data=c;
   newnode->weight=weight;
   heap.insert(newnode);
}
for(int j=0;j<n-1;j++){
ptrTreenode left=heap.del();
ptrTreenode right=heap.del();
ptrTreenode newnode=new Treenode;
left->parent=newnode;
right->parent=newnode;
newnode->left=left;
newnode->right=right;
newnode->weight=left->weight+right->weight;
heap.insert(newnode);
}
this->tree=heap.del();
}

Huffmantree::Huffmantree(const Tongjicell tongjis[],int n){

    Heap<ptrTreenode> heap(NUMCOUNT);
    heap.setcompare(compare);

for(int i=0;i<n;i++){
ptrTreenode tmp=new Treenode;
tmp->data=tongjis[i].data;
tmp->weight=tongjis[i].weight;
tmp->left=NULL;
tmp->right=NULL;
tmp->parent=NULL;
yezis[tongjis[i].data]=tmp;
heap.insert(tmp);
}
//heap.del();
//cout<<heap.del()->data<<"dd";/*
for(;n>1;n--){
ptrTreenode left=heap.del();
ptrTreenode right=heap.del();
ptrTreenode newnode=new Treenode;
left->parent=newnode;
right->parent=newnode;
newnode->left=left;
newnode->right=right;
newnode->weight=left->weight+right->weight;
heap.insert(newnode);
}
this->tree=heap.del();


}





void Huffmantree::travel(Tree tree){
if(tree){
cout<<tree->data<<" "<<tree->weight<<" ";
travel(tree->left);
travel(tree->right);
}
}

Huffcode Huffmantree::gethuffcode(Ele c){
    ptrTreenode ptrtreenode=NULL;
    if(yezis.count(c)==0)
    {cout<<"key not in map when gethuffcode";throw "key not in map when gethuffcode";}
    ptrtreenode=yezis[c];
    if(!ptrtreenode)
    {cout<<"ptrtreenode null when gethuffcode";throw "ptrtreenode null when gethuffcode";}
 Huffcode huffcode;
ptrTreenode parent,p;
parent=ptrtreenode->parent;
p=ptrtreenode;
while(parent){
if(parent->left==p)
   huffcode.insert(0,"0");
    else if(parent->right==p)
   huffcode.insert(0,"1");
     p=parent;
     parent=p->parent;

}
return huffcode;
}
