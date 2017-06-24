#ifndef HEAP_H
#define HEAP_H
#include<iostream>
#include<cstring>
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



#endif // HEAP_H
