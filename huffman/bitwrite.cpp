#include "bitwrite.h"

Bitwrite::Bitwrite(const char *filename)
{   outf.open(filename,ios::binary);
    if(!outf.is_open())
    {cout<<"open fail";return;}
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
