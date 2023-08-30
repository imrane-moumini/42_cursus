#ifndef HARL_H
#define HARL_H
#include <string>
#include <iostream>
#include <cstring>
#include <fstream>

class Harl{
private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
public:
    Harl();
    Harl(Harl& harl);
    ~Harl();

    void complain(std::string level);
    // tu lui indiques dans level le niveau de plainte
    // en fonction du level il dira un message different
    // ce message different c les fonctions privee
    // pas le droit au if

};
#endif