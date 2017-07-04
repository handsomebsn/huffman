#ifndef APP_H
#define APP_H
#include"tongji.h"
#include"huffmantree.h"
#include"bitwrite.h"
class App
{
public:
    App();
    void jiami(const char *decname,const char *srcname);
    void jiemi(const char *decname,const char *srcname);
    void jiemi(char bit, ofstream &outf);
    //map<Ele,Huffcode> elehuffcode;
    Huffcode elehuffcode[NUMCOUNT];
    unsigned char xiabiao;
    //
    map<Huffcode,Ele> huffcodeele;
private:
    Huffcode huffcode;
};

#endif // APP_H
