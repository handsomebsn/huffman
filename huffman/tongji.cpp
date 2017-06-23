#include "tongji.h"
Tongji::Tongji(const char *filename){
    inf.open("1.txt",ios::binary);
    if(!inf.is_open())
    {cout<<"open fail";return;}
}


void Tongji::close(){


    inf.close();
}
