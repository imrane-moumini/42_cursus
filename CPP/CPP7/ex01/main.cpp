#include "iter.hpp"


int main(void)
{
    int iTab[5] = {0,1,2,3,4};
    char cTab[5] = {'a','b','c','d','e'};
    std::string sTab[5] = {"haha", "hbhb", "hchc", "hdhd", "hehe"};
    iter(iTab, 5, print);
    iter(cTab, 5, print);
    iter(sTab, 5, print);
}