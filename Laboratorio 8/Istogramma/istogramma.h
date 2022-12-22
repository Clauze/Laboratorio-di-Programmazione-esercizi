#ifndef istogramma_h
#define istogramma_h
#include <fstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

class istogramma
{
private:
    map<char,int> isto;
public:
    istogramma(string file);
    void printIsto();
};

#include "istogramma.hpp"
#endif