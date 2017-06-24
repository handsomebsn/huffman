#include "tongji.h"
#include<string.h>
Tongji::Tongji(const char *filename){
    n=0;
    inf.open(filename,ios::binary);
    if(!inf.is_open())
    {cout<<"open failed in Tongji construct";throw "open failed in Tongji construct";}
    for(int i=0;i<NUMCOUNT;i++)
    tongjis[i]=NULL;
    char tmp;
       while(!inf.eof()){
       inf.read(&tmp,sizeof(char));
       cout<<tmp;
       unsigned char tmp1;
       memcpy(&tmp1,&tmp,1);
           if(!tongjis[tmp1]){
              tongjis[tmp1]=new Tongjicell;
              tongjis[tmp1]->weight=1;
              tongjis[tmp1]->data=tmp;
             // tongjis[tmp1]->parent=NULL;
              n++;
           }else{
            tongjis[tmp1]->weight++;

           }


      }


}


Tongji::~Tongji(){

for(int i=0;i<NUMCOUNT;i++)
{
    if(tongjis[i])
    delete tongjis[i];
    tongjis[i]=NULL;

}


}


void Tongji::close(){


    inf.close();
}

void Tongji::print(){
for(int i=0;i<NUMCOUNT;i++)
if(tongjis[i])
{
  printbit(tongjis[i]->data);
  cout<<" "<<tongjis[i]->weight<<endl;

}

}



ptrTongjicell* Tongji::gettongji(){



    return tongjis;
}
