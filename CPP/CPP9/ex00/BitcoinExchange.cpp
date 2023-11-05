#include "BitcoinExchange.hpp"

btc::btc(std::ifstream& fileCSV) : findDate(0)
{
    mapCSV = fillMap(fileCSV, 1);
    firstDate = (mapCSV.begin())->first.c_str();
    std::multimap<std::string, std::string>::iterator it;

    it = mapCSV.end();
    it--;
    lastDate = (it->first).c_str();
}
btc::btc(btc& copy) : findDate(copy.findDate), lastDate(copy.lastDate), firstDate(copy.firstDate), saveDate(copy.saveDate)
{
    if (this != &copy)
    {
        for (std::multimap<std::string, std::string>::const_iterator it = copy.mapCSV.begin(); it != copy.mapCSV.end(); ++it) {
            this->mapCSV.insert(*it);
        }
    }
}
btc& btc::operator=(btc& copy)
{
    if (this != &copy)
    {
        for (std::multimap<std::string, std::string>::const_iterator it = copy.mapCSV.begin(); it != copy.mapCSV.end(); ++it) {
            this->mapCSV.insert(*it);
        }
        findDate = copy.findDate;
        lastDate = copy.lastDate;
        firstDate = copy.firstDate;
        saveDate = copy.saveDate;
    }
    return (*this);
}
btc::~btc()
{
    
}
void btc::getValue(std::ifstream& fileArg)
{
     std::string line;
    while(std::getline(fileArg, line))
    {
        std::string firstPart;
        std::string secondPart;
        firstPart = extractFirstPart(line, 0);
        secondPart = extractLastPart(line, 0);
        if (line.find("date") == std::string::npos)
        {
            findDate = 0;
            if (!checkDate(firstPart))
                findDate = 1;
            if (findDate == 0 && !checkValue(secondPart))
                findDate = 1;
            if (findDate == 0  &&  firstDate > firstPart)
            {
                std::cout << firstPart << " => " << secondPart  << " = ";
                std::cout << (std::atof((secondPart ).c_str()) * std::atof((mapCSV.begin()->second).c_str()) ) << std::endl;
                findDate = 1;
            }
            if (findDate == 0 &&  lastDate < firstPart)
            {
                std::multimap<std::string, std::string>::iterator it;

                it = mapCSV.end();
                it--;
                std::cout << firstPart << " => " << secondPart  << " = ";
                std::cout << (std::atof((secondPart).c_str()) * std::atof((it->second).c_str()) ) << std::endl;
                findDate = 1;
            }
            if (findDate == 0)
            {
                for (std::multimap<std::string, std::string>::iterator itCSV = mapCSV.begin(); itCSV != mapCSV.end(); itCSV++)
                {
                    if (firstPart.find("date") == std::string::npos && firstPart.find(itCSV->first) != std::string::npos )
                    {
                        std::cout << itCSV->first << " => " << secondPart  << " = ";
                        std::cout << (std::atof((secondPart ).c_str()) * std::atof((itCSV->second).c_str()) ) << std::endl;
                        findDate = 1;
                    }
                    if (firstPart.find("date") != std::string::npos)
                        findDate = 1;
                }
                if (findDate == 0)
                    saveDate = newDate(firstPart);

                while (findDate == 0)
                {
                   for (std::multimap<std::string, std::string>::iterator itCSV = mapCSV.begin(); itCSV != mapCSV.end(); itCSV++)
                    {
                        if (saveDate.find("date") == std::string::npos && saveDate.find(itCSV->first) != std::string::npos )
                        {
                            std::cout << firstPart << " => " << secondPart  << " = ";
                            std::cout << (std::atof((secondPart ).c_str()) * std::atof((itCSV->second).c_str())) << std::endl;
                            findDate = 1;
                        }
                    }
                    if (findDate == 0)
                        saveDate = newDate(saveDate);
                }
            }
        }
    }
}

std::multimap<std::string, std::string> btc::fillMap(std::ifstream& file, int nbr){
    std::string firstPart;
    std::string secondPart;
    std::string line;
    std::pair<std::string, float>  pair;

    while(std::getline(file, line))
    {
        if (line.find("date") == std::string::npos)
        {
            firstPart = extractFirstPart(line, nbr);
            secondPart = extractLastPart(line, nbr);
            mapCSV.insert(std::make_pair(firstPart,secondPart));
        }
    }
    return (mapCSV);
}

int btc::count(const char *str)
{
    int i;
    i = 0;
    if (!str)
        return (0);
    while (str[i] && std::isdigit(str[i]))
        i++;
    return (i);
}
std::string btc::createNewDay(std::string day)
{
    std::string newDay;
    int nbr = std::atoi(day.c_str());
    if (nbr < 10)
    {
        nbr = nbr - 1;
        if (nbr <= 0) 
            nbr = 31;
        if (nbr != 31)
        {
            std::ostringstream oss;
            oss << nbr;
            newDay = oss.str();
            newDay.insert(0, 1, '0');
            return (newDay);
        }
        else
        {
            std::ostringstream oss;
            oss << nbr;
            newDay = oss.str();
            return (newDay);
        }
    }
    else
    {
        std::ostringstream oss;
        oss << nbr - 1;
        newDay = oss.str();
        return (newDay);
    }
}
std::string btc::createNewMonth(std::string month)
{
    std::string newMonth;
    int nbr = std::atoi(month.c_str());
    if (nbr < 10)
    {
        nbr = nbr - 1;
        if (nbr <= 0)
            nbr = 12;
        if (nbr > 9)
        {
            std::ostringstream oss;
            oss << nbr;
            newMonth = oss.str();
            return (newMonth);
        }
        else
        {
            std::ostringstream oss;
            oss << nbr;
            newMonth = oss.str();
            newMonth.insert(0, 1, '0');
            return (newMonth);
        }
    }
    else
    {
        std::ostringstream oss;
        oss << nbr - 1;
        newMonth = oss.str();
        return (newMonth);
    }
}
std::string btc::createNewYear(std::string year)
{
    std::string newYear;
    int nbr = std::atoi(year.c_str());

    std::ostringstream oss;
    oss << nbr - 1;
    newYear = oss.str();


    return (newYear);
}
std::string btc::newDate(std::string date)
{
    std::string newDate;
    std::string newDay;
    std::string newMonth;
    std::string newYear;

    int changeMonth = 0;


    
    int pos2 = static_cast<int>(date.find('-'));
    int pos3 = static_cast<int>(date.find('-', pos2 + 1));
    newDay = createNewDay(date.substr(pos3 + 1, 2));

    
    if (std::atoi(newDay.c_str()) != 31)
    {
        int pos1 = static_cast<int>(date.find('-'));
        newMonth = date.substr(pos1 + 1, 2);
    }
    else
    {
        changeMonth = 1;
        int pos1 = static_cast<int>(date.find('-'));
        newMonth = createNewMonth(date.substr(pos1 + 1, 2));
    }

    if (changeMonth != 1)
    {
        int pos = static_cast<int>(date.find('-'));
        newYear = date.substr(0, pos);
    }
    else
    {
        int pos = static_cast<int>(date.find('-'));
        newYear = createNewYear(date.substr(0, pos));
    }
    newDate = newYear + '-' + newMonth + '-' + newDay;
    return (newDate);
}
bool btc::checkYear(std::string date)
{
    int pos = static_cast<int>(date.find('-'));
    std::string dateStr = date.substr(0, pos);
    for (long unsigned int i = 0; i < dateStr.size(); i++)
    {
        if (dateStr[i] != ' ' && !std::isdigit(dateStr[i]))
            return (false);
    }
    int nbr = std::atoi(dateStr.c_str());

    if (count(dateStr.c_str()) < 4 || count(dateStr.c_str()) > 4)
        return (false);
    if (nbr <= 0)
        return (false);
    return (true);
}
bool btc::checkDay(std::string date)
{
    int pos1 = static_cast<int>(date.find('-'));
    int pos2 = static_cast<int>(date.find('-', pos1 + 1));

    std::string dateStr = date.substr(pos2 + 1, date.length() - pos2 - 1);
    int nbr = std::atoi(dateStr.c_str());

    for (long unsigned int i = 0; i < dateStr.size(); i++)
    {
        if (dateStr[i] != ' ' && !std::isdigit(dateStr[i]))
            return (false);
    }

    if (count(dateStr.c_str()) < 2 || count(dateStr.c_str()) > 2)
        return (false);
    if (nbr <= 0)
        return (false);
    if (nbr > 31)
        return (false);
    return (true);
}
bool btc::checkMonth(std::string date)
{
    int pos1 = static_cast<int>(date.find('-'));
    int pos2 = static_cast<int>(date.find('-', pos1 + 1));
    std::string dateStr = date.substr(pos1 + 1, pos2 - pos1 - 1);
    int nbr = std::atoi(dateStr.c_str());

    for (long unsigned int i = 0; i < dateStr.size(); i++)
    {
        if (dateStr[i] != ' ' && !std::isdigit(dateStr[i]))
            return (false);
    }
    if (count(dateStr.c_str()) < 2 || count(dateStr.c_str()) > 2)
        return (false);
    if (nbr <= 0)
        return (false);
    if (nbr > 12)
        return (false);
    return (true);
}
bool btc::checkDate(std::string date)
{
    if (std::count(date.begin(), date.end(), '-') != 2)
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }    
    if (!checkYear(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    if (!checkDay(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    if (!checkMonth(date))
    {
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    return (true);
}
bool btc::checkValue(std::string nbrStr)
{
    if (!nbrStr.size())
    {
        std::cout << "Error: bad input => " << nbrStr << std::endl;
        return (false);
    }
    for (long unsigned int i = 0; i < nbrStr.size(); i++)
    {
        if (nbrStr[i] != '.' &&  nbrStr[i] != ' ' && !std::isdigit(nbrStr[i]))
        {
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
std::string btc::extractFirstPart(std::string line, int nbr)
{
    std::string extractStr;
    size_t pos;
    if (nbr == 1)
        pos = line.find(',');
    else
        pos = line.find('|');
    if (pos != std::string::npos)
        extractStr = line.substr(0,(pos));
    if (pos == std::string::npos)
    {
        pos = line.find('\n');
        if (pos != std::string::npos)
            extractStr = line.substr(0,(pos));
        else
            extractStr = line.substr(0,line.size());
    }
    return (extractStr);  
}
std::string btc::extractLastPart(std::string line, int nbr)
{
    std::string extractStr;
    size_t pos;

     if (nbr == 1)
        pos = line.find(',');
    else
        pos = line.find('|');
    if (pos != std::string::npos)
        extractStr = line.substr((pos+1),(line.length() - (pos + 1)));
    if (pos == std::string::npos)
        extractStr = "";
    return (extractStr);  
}