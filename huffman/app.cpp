#include "app.h"
#include<cstring>
App::App()
{

}
void App::jiami(const char *decname, const char *srcname){
Tongji tongji(srcname);
//tongji.print();
//cout<<tongji.count();
ptrTongjicell *ptrtongjicell=tongji.gettongji();
int n=0;
Tongjicell tongjis[NUMCOUNT];
for(int i=0,j=0;i<NUMCOUNT;i++)
{if(ptrtongjicell[i]){
    tongjis[j]=*ptrtongjicell[i];
    n++;
    j++;
    }
}

tongji.close();
Huffmantree huff(tongjis,n);
for(int i=0;i<n;i++)
//{cout<<tongjis[i].data<<" ";
//printbit(tongjis[i].data);
//cout<<endl;
    elehuffcode[tongjis[i].data]=huff.gethuffcode(tongjis[i].data);//}
ofstream outf;
outf.open(decname,ios::binary);
if(!outf.is_open())
{throw "open fail in app::jiami";}
char qianming[]="phoenix";
outf.write(qianming,sizeof(qianming));
outf.write((char*)&n,sizeof(n));
for(int i=0;i<n;i++)
    outf.write((char*)&tongjis[i],sizeof(Tongjicell));
outf.close();
Bitwrite bitwrite(decname);
ifstream inf;
inf.open(srcname,ios::binary);
if(!inf.is_open())
throw "open fail in app::jiami 1";
char c;
Huffcode huffcode;
while(!inf.eof())
{
inf.read(&c,sizeof(char));
huffcode=elehuffcode[c];
//cout<<huffcode<<endl;
for(int i=0;i<huffcode.size();i++)
bitwrite.insert(huffcode.at(i));
}
for(int i=0;i<7;i++)
bitwrite.insert('0');
bitwrite.close();
//cout<<n<<endl;
}

void App::jiemi(const char *decname, const char *srcname){
    ifstream inf;
    inf.open(srcname,ios::binary);
    if(!inf.is_open())
    throw "open fail in app::jiami 1";
    char qianming[10];
     inf.read(qianming,sizeof("phoenix"));
     //cout<<qianming;
     if(strcmp(qianming,"phoenix")!=0)
     {cout<<"not jiemi file"; return; }
     int n;
     inf.read((char*)&n,sizeof(n));
     Tongjicell tongjis[NUMCOUNT];
     for(int i=0;i<n;i++){
       inf.read((char*)&tongjis[i],sizeof(Tongjicell));
     }
     Huffmantree huff(tongjis,n);
     for(int i=0;i<n;i++)
        huffcodeele[huff.gethuffcode(tongjis[i].data)]=tongjis[i].data;




}
