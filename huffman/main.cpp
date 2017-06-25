#include"app.h"
#include<cstring>
int main(int argc, char *argv[])
{
App a;
if(argc!=4)
{    cout<<"argv num is wrong use jia or jie ./huff jia dec src\n";return 1;}

if(strcmp(argv[1],"jia")==0)
      a.jiami(argv[2],argv[3]);
    else if(strcmp(argv[1],"jie")==0)
      a.jiemi(argv[2],argv[3]);
    else
    cout<<"argv is wrong use jia or jie ./huff jia dec src\n";
    return 0;
}
