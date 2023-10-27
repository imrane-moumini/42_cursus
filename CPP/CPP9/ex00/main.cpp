#include "BitcoinExchange.hpp"
bool checkYear(std::string date)
{
    // compter nombre delement avant premier tirer
        // regarder si 4 élément meme si c grand pas grave
    int pos = static_cast<int>(date.find('-'));
    std::string dateStr = date.substr(0, pos);
    int nbr = std::atoi(dateStr.c_str());
    //std::cout << "YEAR: "<< dateStr<< std::endl;
    if (dateStr.size() < 4 || dateStr.size() > 4)
        return (false);
    if (nbr <= 0)
        return (false);
    return (true);
    
}

bool checkDay(std::string date)
{
    // c'est juste ce qu'il y a entre 2 tiret
    int pos1 = static_cast<int>(date.find('-'));
    int pos2 = static_cast<int>(date.find('-', pos1 + 1));
    std::string dateStr = date.substr(pos1 + 1, pos2 - pos1 - 1);
    int nbr = std::atoi(dateStr.c_str());
    //std::cout << "DAY: " << dateStr<< std::endl;
    if (dateStr.size() < 2 || dateStr.size() > 2)
    {
        // g pas la bonne dateStr, elle est trop grande
        
        std::cout << dateStr.size() << std::endl;
        //std::cout << "c3.1\n";
        return (false);
    }
    if (nbr <= 0)
    {
        //std::cout << "c3.2\n";
        return (false);
    }
    if (nbr > 31)
    {
        //std::cout << "c3.3\n";
        return (false);
    }
    return (true);
    //checker si jamais c 2 tiret d'affilé
}

bool checkMonth(std::string date)
{
    // c'est juste ce qu'il y a entre 2 tiret
    int pos1 = static_cast<int>(date.find('-'));
    int pos2 = static_cast<int>(date.find('-', pos1 + 1));
    std::string dateStr = date.substr(pos2 + 1, date.length() - pos2 - 2);
    //std::cout << "MONTH: "<< dateStr<< std::endl;
    int nbr = std::atoi(dateStr.c_str());
    if (dateStr.size() < 2 || dateStr.size() > 2)
    {
        //std::cout << "c4.1\n";
        std::cout<<dateStr.size() <<std::endl;
        return (false);
    }
    if (nbr <= 0)
    {
        //std::cout << "c4.2\n";
        return (false);
    }
    if (nbr > 12)
    {
        //std::cout << "c4.3\n";
        return (false);
    }
    return (true);
}
bool checkDate(std::string date)
{
    if (std::count(date.begin(), date.end(), '-') != 2)
    {
        //std::cout << "c1\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }    
    if (!checkYear(date))
    {
        //std::cout << "c2\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    if (!checkDay(date))
    {
        //std::cout << "c3\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    if (!checkMonth(date))
    {
        //std::cout << "c4\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    return (true);
}
bool checkValue(std::string nbrStr)
{
    for (long unsigned int i = 0; i < nbrStr.size(); i++)
    {
        if (nbrStr[i] != '.' && nbrStr[i] != ' ' && !std::isdigit(nbrStr[i]))
        {
            //std::cout << "c5\n";
            //std::cout << nbrStr[i] << std::endl;
            std::cout << "Error: bad input => " << nbrStr << std::endl;
            return (false);
        }
    }
    float nbr = std::atof(nbrStr.c_str());
    if (nbr < 0 || nbr > 1000)
    {
        if (nbr < 0)
            std::cout << "Error: not a positive number." << std::endl;
        else
            std::cout << "Error: too large a number." << std::endl;
        return (false);
    }
    return (true);
}
std::string extractFirstPart(std::string line, int nbr)
{
    // faut que je renvoit tout ce qui est avant la virgule
    std::string extractStr;
    size_t pos;
    if (nbr == 1)
        pos = line.find(',');
    else
        pos = line.find('|');
    if (pos != std::string::npos)
        extractStr = line.substr(0,(pos));
    // en gros je recupère meme les espace ce qui créer ce pb
    // sinon je remplace == par contient
    //else
      //renvoyer une erreur
    return (extractStr);  
}

std::string extractLastPart(std::string line, int nbr)
{
    // faut que je renvoit tout ce qui est avant la virgule
    std::string extractStr;
    size_t pos;

     if (nbr == 1)
        pos = line.find(',');
    else
        pos = line.find('|');
    if (pos != std::string::npos)
        extractStr = line.substr((pos+1),(line.length() - (pos + 1)));
    //else
      //renvoyer une erreur
    return (extractStr);  
}

std::multimap<std::string, std::string>& fillMap(std::multimap<std::string, std::string>& mapFile,std::ifstream& file, int nbr){
    std::string firstPart;
    std::string secondPart;
    std::string line;
    std::pair<std::string, float>  pair;
    while(std::getline(file, line))
    {
        firstPart = extractFirstPart(line, nbr);
        secondPart = extractLastPart(line, nbr);
        mapFile.insert(std::make_pair(firstPart,secondPart));
    }
    return (mapFile);
}
int main(int argc, char *argv[])
{
    
    if (argc != 2)
    {
        std::cout << "wrong number of arguments\n";
        return (1);
    } 
    std::multimap<std::string, std::string> mapCSV;
    std::multimap<std::string, std::string> mapArg;
    
    
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
    

    mapCSV = fillMap(mapCSV,fileCSV,1);
    mapArg = fillMap(mapArg,fileArg,0);
   
    for (std::multimap<std::string, std::string>::iterator itArg = mapArg.begin(); itArg != mapArg.end(); itArg++)
    {
        if (!checkDate(itArg->first))
            itArg++;
        if (!checkValue(itArg->second))
            itArg++;
        for (std::multimap<std::string, std::string>::iterator itCSV = mapCSV.begin(); itCSV != mapCSV.end(); itCSV++)
        {
            if (itArg->first.find("date") == std::string::npos && itArg->first.find(itCSV->first) != std::string::npos )
            {
                std::cout << itCSV->first << " => " << itArg->second << " = ";
                std::cout << (std::atof((itArg->second).c_str()) * std::atof((itCSV->second).c_str()) ) << std::endl;
            }
        }
    }
    fileArg.close();
    fileCSV.close();
}