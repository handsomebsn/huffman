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
};

#endif // APP_H
