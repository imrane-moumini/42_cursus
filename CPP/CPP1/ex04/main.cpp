#include <string>
#include <iostream>
#include <cstring>
#include <fstream>


int main(int argc, char *argv[]) {
    if (argc != 4)
    {
        std::cout << "wrong number of arguments\n";
        return (1);
    } 
    std::string strFile;
    std::ifstream file(argv[1]);
    if (file.fail())
    {
        std::cout << "cannot open the file that your provied please check the filename\n";
        return (1);
    }
    std::string name = argv[1];
    name.append(".replace");
    std::ofstream Outfile(name.c_str());
    if (Outfile.fail())
    {
        std::cout << "cannot create the file that your provied please check the filename\n";
        return (1);
    }

    size_t locationOccur = 0;
    while(std::getline(file, strFile))
    {
        locationOccur = strFile.find(argv[2]);
        while (locationOccur != std::string::npos)
        {
            strFile.erase(locationOccur,std::strlen(argv[2]));
            strFile.insert(locationOccur, argv[3]);
            locationOccur = strFile.find(argv[2], locationOccur);
        }
        Outfile << strFile << std::endl;
    }
    Outfile.close();
    file.close();
} 



