#include "app.h"
#include<cstring>
App::App()
{

}
void App::jiami(const char *decname, const char *srcname){
    double starttime=clock();
Tongji tongji(srcname);
//tongji.print();
//cout<<tongji.count();
ptrTongjicell *ptrtongjicell=tongji.gettongji();
int n=0;long bitsum=0;int mod;
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
for(int i=0;i<n;i++){
    memcpy(&xiabiao,&tongjis[i].data,1);
    elehuffcode[xiabiao]=huff.gethuffcode(tongjis[i].data);}
//bitsum
for(int i=0;i<n;i++){
    memcpy(&xiabiao,&tongjis[i].data,1);
bitsum=bitsum+elehuffcode[xiabiao].size()*tongjis[i].weight;
}
mod=bitsum%8;
//cout<<endl<<bitsum%8<<endl;
//bitsum end
ofstream outf;
outf.open(decname,ios::binary);
if(!outf.is_open())
{throw "open fail in app::jiami";}
char qianming[]="phoenix";
outf.write(qianming,sizeof(qianming));
outf.write((char*)&n,sizeof(n));
outf.write((char*)&mod,sizeof(mod));
for(int i=0;i<n;i++)
    outf.write((char*)&tongjis[i],sizeof(Tongjicell));
outf.close();
Bitwrite bitwrite(decname);
//
ifstream inf;
inf.open(srcname,ios::binary);
if(!inf.is_open())
throw "open fail in app::jiami 1";
char buff[BUFFNUM];
int readum;
Huffcode huffcode;
while(inf.peek()!=EOF)
{
     inf.read(buff,sizeof(buff));
     readum=inf.gcount();
     //
     for(int ii=0;ii<readum;ii++){
         memcpy(&xiabiao,&buff[ii],1);
     huffcode=elehuffcode[xiabiao];
     //cout<<huffcode<<endl;
     for(int i=0;i<huffcode.size();i++)
     bitwrite.insert(huffcode.at(i));
     }
}
bitwrite.pushfull();
bitwrite.close();
//cout<<n<<endl;
double endtime=clock();
cout<<"jia time:"<<(endtime-starttime)/CLOCKS_PER_SEC<<endl;

}

void App::jiemi(const char *decname, const char *srcname){
    ifstream inf;int ntmp=8;long filesize;
     filesize=getfilesize(srcname);
     //cout<<filesize;
    inf.open(srcname,ios::binary);
    if(!inf.is_open())
    throw "open fail in app::jiami 1";
    char qianming[10];
     inf.read(qianming,sizeof("phoenix"));
     //cout<<qianming;
     if(strcmp(qianming,"phoenix")!=0)
     {cout<<"not jiemi file"; return; }
     int n,mod;
     inf.read((char*)&n,sizeof(n));
     inf.read((char*)&mod,sizeof(mod));
     Tongjicell tongjis[NUMCOUNT];
     for(int i=0;i<n;i++){
       inf.read((char*)&tongjis[i],sizeof(Tongjicell));
     }
     Huffmantree huff(tongjis,n);
     for(int i=0;i<n;i++)
        huffcodeele[huff.gethuffcode(tongjis[i].data)]=tongjis[i].data;
     char c;
     ofstream outf;
     outf.open(decname,ios::binary);
    if(!outf.is_open())
     throw "open fail in app::jiami 2";
     while(inf.peek()!=EOF){
       inf.read(&c,sizeof(char));

       string tmp=charbit(c);

        if(inf.tellg()==filesize&&mod!=0)ntmp=mod;

        for(int i=0;i<ntmp;i++)
        jiemi(tmp.at(i),outf);

     }

inf.close();
outf.close();

}
void App::jiemi(char bit,ofstream &outf){
huffcode.append(&bit,sizeof(bit));
if(huffcodeele.count(huffcode)!=0)
{
outf.write(&huffcodeele[huffcode],sizeof(Ele));
huffcode.clear();

}

}
