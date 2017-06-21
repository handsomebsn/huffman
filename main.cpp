#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include <fstream>
using namespace std;
template<class Type>
class Heap{
public:
    Heap();
    Heap(int n);
    ~Heap();
    void insert(Type data);
    Type del();
    void setcompare(int (*compare)(Type ,Type )){this->compare=compare;}
private:
    Type *array;
    int size;
    int maxsize;
    int (*compare)(Type ,Type );//函数指针
protected:
    bool isfull();
    bool isempty(){return size<=-1;}
    bool kuorong();//有bug
};
template<class Type>
Heap<Type>::Heap(){
maxsize=100;
size=-1;
array=new Type[maxsize];
}

template<class Type>
Heap<Type>::Heap(int n){
    maxsize=n;
    size=-1;
    array=new Type[maxsize];
}
template<class Type>
Heap<Type>::~Heap(){
    delete [] array;
    array=NULL;
}
template<class Type>
bool Heap<Type>::isfull(){
   return this->size>=this->maxsize-1;
}
template<class Type>
bool Heap<Type>::kuorong(){
maxsize=maxsize+100;
Type *tmparray=new Type[maxsize];
if(!tmparray) return false;
memcpy(tmparray,array,sizeof(Type)*size);
delete [] array;
array=tmparray;
return true;
}
template<class Type>
void Heap<Type>::insert(Type data){
  if(isfull())
   if(!kuorong())
    throw "full heap";
int i=0;
for(i=++size;i>0&&(*compare)(array[i/2],data)>0;i/=2)
array[i]=array[i/2];
array[i]=data;

}

template<class Type>
Type Heap<Type>::del(){
if(isempty())
throw "empty heap";
Type tmp1=array[0];
Type tmp=array[size--];
int i,child;
for(i=0;2*i+1<=size;i=child)
{
child=2*i+1;
if(child!=size&&(*compare)(array[child],array[child+1])>0)
child++;
if((*compare)(array[child],tmp)>=0)
break;
array[i]=array[child];
}
array[i]=tmp;
return tmp1;
}


typedef struct Treenode{
 char data;
 int weight;
 struct Treenode *left;
 struct Treenode *right;
 struct Treenode *parent;
}*Tree,*ptrTreenode;

typedef struct{
char codes[258];
int start;
}Hufcode,*ptrHufcode;










int compare(ptrTreenode a,ptrTreenode b){


    return a->weight-b->weight;
}




class Bytewrite;
class Hufmantree
{
public:
   Tree gettree(){return this->tree;}
 Hufmantree();
 Hufmantree(const ptrTreenode array[]);
 Hufcode gethufcode(ptrTreenode ptrtreenode);
 void travel(Tree tree);
private:
Tree tree;
};

Hufmantree::Hufmantree(){
int n;
char c;
int weight;
cout<<"please enter chars number\n";
cin>>n;
Heap<ptrTreenode> heap;
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

Hufmantree::Hufmantree(const ptrTreenode array[]){

    Heap<ptrTreenode> heap(258);
    heap.setcompare(compare);
    int n=0;
for(int i=0;i<258;i++){
    if(array[i])
{heap.insert(array[i]);n++;}
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





void Hufmantree::travel(Tree tree){
if(tree){
cout<<tree->data<<" "<<tree->weight<<" ";
travel(tree->left);
travel(tree->right);
}
}

Hufcode Hufmantree::gethufcode(ptrTreenode ptrtreenode){
    if(!ptrtreenode)
    {cout<<"ptrtreenode null when gethufcode";throw "ptrtreenode null when gethufcode";}
 Hufcode hufcode;
hufcode.start=258;
ptrTreenode parent,p;
parent=ptrtreenode->parent;
p=ptrtreenode;
while(parent){
if(parent->left==p)
     hufcode.codes[--hufcode.start]='0';
    else if(parent->right==p)
    hufcode.codes[--hufcode.start]='1';
     p=parent;
     parent=p->parent;

}
return hufcode;
}



class Bytewrite
{
public:
    friend class Hufmantree;
    Bytewrite();
    ~Bytewrite(){inout.close();}
   void insert(char num);
   void print();
   void print(char c);
   void showtongji();
   ptrTreenode* getarray();
private:
   signed int i;
   char c;
 ifstream inout;
 ///
 ptrTreenode array[258];
};

Bytewrite::Bytewrite(){

    for(int ii=0;ii<258;ii++)
    {array[ii]=NULL;}

inout.open("1.txt",ios::binary);
if(!inout.is_open())
{cout<<"open fail";return;}
c=0x00;
i=7;
for(int i=0;i<258;i++)
array[i]=NULL;
char tmp;
   while(!inout.eof()){
   inout.read(&tmp,sizeof(char));
   cout<<tmp;
   unsigned char tmp1;
   memcpy(&tmp1,&tmp,1);
       if(!array[tmp1]){
          array[tmp1]=new Treenode;
          array[tmp1]->weight=1;
          array[tmp1]->data=tmp;
          array[tmp1]->parent=NULL;
       }else{
        array[tmp1]->weight++;

       }


  }

}
ptrTreenode* Bytewrite::getarray(){




return array;
}

void Bytewrite::insert(char num){
    //cout<<sizeof("a");
char tmp=0x01;
if(num=='1'){
tmp=tmp<<i;
c=tmp|c;}
i--;
if(i==-1)
   { i=7;
    //inout.write(&c,sizeof(char));
   //cout<<c;
    c=0x00;
   }
}



void Bytewrite::print(){
int tmp=0x80;
for(int j=0;j<8;j++)
{
if(c&tmp)
cout<<1;
else
   cout<<0;
tmp=tmp>>1;
}

}



void Bytewrite::print(char c){


    int tmp=0x80;
    for(int j=0;j<8;j++)
    {
    if(c&tmp)
    cout<<1;
    else
       cout<<0;
    tmp=tmp>>1;
    }



}


void Bytewrite::showtongji(){

for(int i=0;i<258;i++)
{
if(array[i]){
print(array[i]->data);
cout<<" "<<array[i]->weight<<endl;

}
}

}




void print(Hufcode hufcode){

    for(int i=hufcode.start;i<258;i++)
    cout<<hufcode.codes[i];
}




int main(){
 Bytewrite a;
 /*char c;
 while(cin>>c)
 {
 if(c!='1'&&c!='0')
     continue;
a.insert(c);
 }*/
 //a.showtongji();
Hufmantree huf(a.getarray());
Hufcode hufcode= huf.gethufcode(a.getarray()[123]);
print(hufcode);
    return 0;
}
