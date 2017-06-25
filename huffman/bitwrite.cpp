#include "bitwrite.h"

Bitwrite::Bitwrite(const char *filename,bool app)
{   if(app)
        outf.open(filename,ios::binary|ios::app);
        else
    outf.open(filename,ios::binary);
    if(!outf.is_open())
    {cout<<"open fail";return;}
    i=7;
}

void Bitwrite::insert(char bit){
    //cout<<sizeof("a");
    char tmp=0x01;
    if(bit=='1'){
    tmp=tmp<<i;
    c=tmp|c;}
    i--;
    if(i==-1)
       { i=7;
        outf.write(&c,sizeof(char));
       //cout<<c;
        c=0x00;
       }

}


void Bitwrite::close(){


    outf.close();
}

int Bitwrite::pushfull(){
int num=0;
if(i==7)
    num=0;
else
    num=i+1;
for(int i=0;i<num;i++)
insert('0');
return num;
}
