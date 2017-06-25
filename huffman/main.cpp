#include"app.h"


int main(int argc, char *argv[])
{
App a;
a.jiami("1.huf","1.txt");
a.jiemi("1.txt","1.huf");
//cout<<getfilesize("1.txt");
/*Tongjicell tongjis[3];
tongjis[0].data='a';
tongjis[0].weight=1;
tongjis[1].data='b';
tongjis[1].weight=1;
tongjis[2].data='c';
tongjis[2].weight=1;
Huffmantree huff(tongjis,3);
cout<<huff.gethuffcode('a')<<endl;
cout<<huff.gethuffcode('b')<<endl;
cout<<huff.gethuffcode('c')<<endl;*/
    return 0;
}
