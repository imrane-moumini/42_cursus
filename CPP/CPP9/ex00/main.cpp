#include "BitcoinExchange.hpp"


int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        std::cout << "wrong number of arguments\n";
        return (1);
    } 

    
    std::ifstream fileCSV("data.csv");
    std::ifstream fileArg(argv[1]);
    if (fileCSV.fail())
    {
        std::cout << "cannot open the file that your provied please check the filename\n";
        return (1);
    }

    if (fileArg.fail())
    {
        std::cout << "cannot open the file that your provied please check the filename\n";
        return (1);
    }

    btc obj(fileCSV);
    obj.getValue(fileArg);
    fileArg.close();
    fileCSV.close();
}
