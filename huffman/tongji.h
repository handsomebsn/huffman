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
public:
    Tongji(const char *filename);
    void close();

};

#endif // TONGJI_H
