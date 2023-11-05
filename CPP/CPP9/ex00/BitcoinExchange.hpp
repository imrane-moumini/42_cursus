#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>
class btc {
    public:
        btc(std::ifstream& fileCSV);
        btc(btc& copy);
        btc& operator=(btc& copy);
        ~btc();
        void getValue(std::ifstream& fileArg);
        
    private:

        //var
        std::multimap<std::string, std::string> mapCSV;
        int findDate;
        std::string lastDate;
        std::string firstDate;
        std::string saveDate;


        // methods
        std::multimap<std::string, std::string> fillMap(std::ifstream& file, int nbr);
        int count(const char *str);
        std::string createNewDay(std::string day);
        std::string createNewMonth(std::string month);
        std::string createNewYear(std::string year);
        std::string newDate(std::string date);
        bool checkYear(std::string date);
        bool checkDay(std::string date);
        bool checkMonth(std::string date);
        bool checkDate(std::string date);
        bool checkValue(std::string nbrStr);
        std::string extractFirstPart(std::string line, int nbr);
        std::string extractLastPart(std::string line, int nbr);






        
};


#endif