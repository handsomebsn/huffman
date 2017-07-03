#ifndef BITWRITE_H
#define BITWRITE_H

#include<fstream>
#include<iostream>
#include"all.h"
using namespace std;
class Bitwrite
{private:
    ofstream outf;
    char c;
    int i;
    char buff[BUFFNUM];
    int bufi;
public:
    Bitwrite(const char *filename, bool app=true);

    void insert(char bit);
    void close();
    int pushfull();

};

#endif // BITWRITE_H
