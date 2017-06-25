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

string charbit(char c){
    int tmp=0x80;
    string haha;
    for(int j=0;j<8;j++)
    {
    if(c&tmp)
     haha.append("1");
    else
      haha.append("0");
    tmp=tmp>>1;
    }
    return haha;
}



int compare(ptrTreenode a,ptrTreenode b){


    return a->weight-b->weight;
}
int compare(int a, int b){


    return a-b;
}
long getfilesize(const char *filename){

      ifstream in(filename);
      if(!in.is_open())
          throw "open failed";
      in.seekg(0,ios::end);
      long size = in.tellg();
      in.close();
      return size;
}
