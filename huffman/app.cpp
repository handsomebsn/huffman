#include "app.h"

App::App()
{

}
void App::jiami(const char *decname, const char *srcname){
Tongji tongji(srcname);
ptrTongjicell *ptrtongjicell=tongji.gettongji();
int n=0;
Tongjicell tongjis[NUMCOUNT];
for(int i=0;i<NUMCOUNT;i++)
{if(ptrtongjicell[i]){
    tongjis[i]=*ptrtongjicell[i];
    n++;
    }
}
Huffmantree huff(tongjis,n);




}

void App::jiemi(const char *decname, const char *srcname){






}
