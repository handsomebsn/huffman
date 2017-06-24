#ifndef TONGJI_H
#define TONGJI_H
#include<fstream>
#include<iostream>
#include"all.h"
using namespace std;
class Tongji
{private:
    ifstream inf;
    ptrTongjicell tongjis[NUMCOUNT];
    int n;
public:
    Tongji(const char *filename);
    ~Tongji();
    void close();
    void print();
    ptrTongjicell* gettongji();
    int count(){return n;}

};

#endif // TONGJI_H
