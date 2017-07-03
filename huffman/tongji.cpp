#include "tongji.h"
#include<string.h>
Tongji::Tongji(const char *filename){
    double starttime=clock();
    n=0;
    inf.open(filename,ios::binary);
    if(!inf.is_open())
    {cout<<"open failed in Tongji construct";throw "open failed in Tongji construct";}
    for(int i=0;i<NUMCOUNT;i++)
    tongjis[i]=NULL;
    char tmp[BUFFNUM];
    int readnum;
    unsigned char tmp1;
       while(inf.peek()!=EOF){
       inf.read(tmp,sizeof(tmp));
       //cout<<tmp;
       readnum=inf.gcount();
       cout<<readnum<<endl;
        for(int i=0;i<readnum;i++){
            memcpy(&tmp1,&tmp[i],1);
            if(!tongjis[tmp1]){
              tongjis[tmp1]=new Tongjicell;
              tongjis[tmp1]->weight=1;
              tongjis[tmp1]->data=tmp[i];
             // tongjis[tmp1]->parent=NULL;
              n++;
           }else{
            tongjis[tmp1]->weight++;

           }


      }

     }

   double endtime=clock();
   cout<<"tongji time:"<<(endtime-starttime)/CLOCKS_PER_SEC<<endl;
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
