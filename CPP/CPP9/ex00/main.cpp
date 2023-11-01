#include "BitcoinExchange.hpp"

// au lieu d'afficher les messages directemennts
// je vais enregistrer les messages dans une 3eme multimap
// ensuite je vais reparcourir le stream object du doc
// comparer la première partie avec celle de la 3eme map
// et afficher la value correspondante
// je el fais en dernier
int findDate = 0;
int count(const char *str)
{
    int i;
    i = 0;
    if (!str)
        return (0);
    while (str[i] && std::isdigit(str[i]))
        i++;
    return (i);
}
std::string createNewDay(std::string day)
{
    std::string newDay;
    int nbr = std::atoi(day.c_str());
    if (nbr < 10)
    {
        nbr = nbr - 1;
        if (nbr <= 0) // normalement je dois indiquer que je change le mois
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
std::string createNewMonth(std::string month)
{
    std::string newMonth;
    int nbr = std::atoi(month.c_str());
    if (nbr < 10)
    {
        nbr = nbr - 1;
        if (nbr <= 0) // normalement je dois indiquer que je change le mois
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

std::string createNewYear(std::string year)
{
    std::string newYear;
    int nbr = std::atoi(year.c_str());

    std::ostringstream oss;
    oss << nbr - 1;
    newYear = oss.str();


    return (newYear);
}

std::string newDate(std::string date)
{
    std::string newDate;
    std::string newDay;
    std::string newMonth;
    std::string newYear;

    int changeMonth = 0;

    //std::cout << "DATE IS: " << date << std::endl;

    
    int pos2 = static_cast<int>(date.find('-'));
    int pos3 = static_cast<int>(date.find('-', pos2 + 1));
    newDay = createNewDay(date.substr(pos3 + 1, 2));
    //std::cout << "new DAY: " << newDay <<std::endl;
    
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
    //std::cout << "new MONTH: " << newMonth << std::endl;
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
    //std::cout << "new YEAR: " << newYear << std::endl;
    newDate = newYear + '-' + newMonth + '-' + newDay;
    return (newDate);

}
bool checkYear(std::string date)
{
    // compter nombre delement avant premier tirer
        // regarder si 4 élément meme si c grand pas grave
    int pos = static_cast<int>(date.find('-'));
    std::string dateStr = date.substr(0, pos);
    for (long unsigned int i = 0; i < dateStr.size(); i++)
    {
        if (dateStr[i] != ' ' && !std::isdigit(dateStr[i]))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return (false);
        }
    }
    int nbr = std::atoi(dateStr.c_str());
    //std::cout << "YEAR: "<< dateStr<< std::endl;
    if (count(dateStr.c_str()) < 4 || count(dateStr.c_str()) > 4)
        return (false);
    if (nbr <= 0)
        return (false);
    return (true);
    
}

bool checkDay(std::string date)
{
    // c'est juste ce qu'il y a entre 2 tiret
    std::cout << "Date in Checkday is: " << date << std::endl;
    int pos1 = static_cast<int>(date.find('-'));
    int pos2 = static_cast<int>(date.find('-', pos1 + 1));
    std::cout << "debut: " << pos2+1 << std::endl;
    std::cout << "fin: " << date.length() - pos2 - 2 <<std::endl;
    std::string dateStr = date.substr(pos2 + 1, date.length() - pos2 - 1);
    int nbr = std::atoi(dateStr.c_str());

    for (long unsigned int i = 0; i < dateStr.size(); i++)
    {
        if (dateStr[i] != ' ' && !std::isdigit(dateStr[i]))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return (false);
        }
    }
    std::cout << "DAY: " << dateStr<< std::endl;
    if (count(dateStr.c_str()) < 2 || count(dateStr.c_str()) > 2)
    {
        // g pas la bonne dateStr, elle est trop grande
        //faut pas que je prenne les espaces
        std::cout << "size is: "<< count(dateStr.c_str()) << std::endl;
        std::cout << "c3.1\n";
        return (false);
    }
    if (nbr <= 0)
    {
        std::cout << "c3.2\n";
        return (false);
    }
    if (nbr > 31)
    {
        std::cout << "c3.3\n";
        return (false);
    }
    return (true);
    //checker si jamais c 2 tiret d'affilé
}

bool checkMonth(std::string date)
{
    // c'est juste ce qu'il y a entre 2 tiret
    //std::cout << "DATE IS : " << date << std::endl;
    int pos1 = static_cast<int>(date.find('-'));
    int pos2 = static_cast<int>(date.find('-', pos1 + 1));
    std::string dateStr = date.substr(pos1 + 1, pos2 - pos1 - 1);
    //std::cout << "DAY: " << dateStr << std::endl;
    int nbr = std::atoi(dateStr.c_str());

    for (long unsigned int i = 0; i < dateStr.size(); i++)
    {
        if (dateStr[i] != ' ' && !std::isdigit(dateStr[i]))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            return (false);
        }
    }
    if (count(dateStr.c_str()) < 2 || count(dateStr.c_str()) > 2)
    {
        //std::cout << "c4.1\n";
        //std::cout << "c0.4.1\n";
        std::cout<<count(dateStr.c_str()) <<std::endl;
        return (false);
    }
    if (nbr <= 0)
    {
        //std::cout << "c0.4.2\n";
        return (false);
    }
    if (nbr > 12)
    {
        //std::cout << "c0.4.3\n";
        return (false);
    }
    return (true);
}
bool checkDate(std::string date)
{
    if (std::count(date.begin(), date.end(), '-') != 2)
    {
        //std::cout << "c0.1\n";
        //std::cout << "c1\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    }    
    if (!checkYear(date))
    {
        //std::cout << "c0.2\n";
        //std::cout << "c2\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    if (!checkDay(date))
    {
        std::cout << "c0.3\n";
        //std::cout << "c3\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    if (!checkMonth(date))
    {
        //std::cout << "c0.4\n";
        //std::cout << "c4\n";
        std::cout << "Error: bad input => " << date << std::endl;
        return (false);
    } 
    return (true);
}
bool checkValue(std::string nbrStr)
{
    if (!nbrStr.size())
    {
        std::cout << "c7\n";
        std::cout << "Error: bad input => " << nbrStr << std::endl;
        return (false);
    }
    for (long unsigned int i = 0; i < nbrStr.size(); i++)
    {
        if (nbrStr[i] != '.' &&  nbrStr[i] != ' ' && !std::isdigit(nbrStr[i]))
        {
            std::cout << "c6\n";
            //std::cout << nbrStr[i] << std::endl;
            std::cout << "Error: bad input => " << nbrStr << std::endl;
            return (false);
        }
    }
    float nbr = std::atof(nbrStr.c_str());
    if (nbr < 0 || nbr > 1000)
    {
        std::cout << "c7\n";
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
    if (pos == std::string::npos)
        extractStr = "";
    return (extractStr);  
}

std::multimap<std::string, std::string>& fillMap(std::multimap<std::string, std::string>& mapFile,std::ifstream& file, int nbr){
    std::string firstPart;
    std::string secondPart;
    std::string line;
    std::pair<std::string, float>  pair;
    while(std::getline(file, line))
    {
        if (line.find("date") == std::string::npos)
        {
            //std::cout << "LINE is: " << line << std::endl;
            firstPart = extractFirstPart(line, nbr);
            //std::cout << "First part : " << firstPart << std::endl;
            secondPart = extractLastPart(line, nbr);
            //std::cout << "Second part : " << secondPart << std::endl;
            mapFile.insert(std::make_pair(firstPart,secondPart));
            //std::cout << "MAP begin is: "<< mapFile.begin()->first << std::endl;
        }
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
    std::string lastDate;
    std::string firstDate;
    std::string saveDate;
    
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

    //ok ça foire quand ya pas de barre
    // ça foire aussi quand je retir la ligne qyi foire, faire debug

    mapCSV = fillMap(mapCSV,fileCSV,1);
    mapArg = fillMap(mapArg,fileArg,0);
    firstDate = ((mapCSV.begin())->first).c_str();
    std::multimap<std::string, std::string>::iterator it;
    it = mapCSV.end();
    it--;
    lastDate = (it->first).c_str();
    // faire en sorte que ça soit pas trié par défaut

    // gérer des dates fausses (trop long, sans aucun sens)
    // tout mettre dans le header file
    
    for (std::multimap<std::string, std::string>::iterator itArg = mapArg.begin(); itArg != mapArg.end(); itArg++)
    {
        std::cout<< itArg->first << " " << itArg->second << std::endl;
    }
    //return 1;
    std::cout<<"\n";
    for (std::multimap<std::string, std::string>::iterator itArg = mapArg.begin(); itArg != mapArg.end(); itArg++)
    {
        std::cout << "c0\n";
        std::cout << "DATE: " << itArg->first << std::endl;
        findDate = 0;
        //if (itArg != mapArg.end() && itArg->first.find("date") != std::string::npos)
        //{
        //    findDate = 1;
            //std::cout << "IM HERE\n";
        //    itArg++;
            //if (itArg != mapArg.end())
                //std::cout << "CHELOU\n";
        //}
        if (itArg == mapArg.end())
            break;
        if (itArg != mapArg.end() && !checkDate(itArg->first))
        {
            findDate = 1;
            //itArgSave = itArg;
            //std::advance(itArgSave, 2);
            //if ((itArg != mapArg.end()) /*&& (itArgSave != mapArg.end())*/)
            //{
            //    itArg++;
            //}
            std::cout << "c1\n";
        }
        if (findDate == 0 && itArg != mapArg.end() && !checkValue(itArg->second))
        {
            findDate = 1;
            std::cout << "c92\n";
            //if (itArg != mapArg.end())
                //itArg++;
        }
        if (findDate == 0 && itArg != mapArg.end() &&  firstDate > itArg->first)
        {
            //std::cout << "IM HERE\n" << std::endl;
            std::cout << itArg->first << " => " << itArg->second << " = ";
            std::cout << (std::atof((itArg->second).c_str()) * std::atof((mapCSV.begin()->second).c_str()) ) << std::endl;
            findDate = 1;
            //if (itArg != mapArg.end())
                //itArg++;
        }
        if (findDate == 0 && itArg != mapArg.end() &&  lastDate < itArg->first)
        {
            std::cout << itArg->first << " => " << itArg->second << " = ";
            std::cout << (std::atof((itArg->second).c_str()) * std::atof((it->second).c_str()) ) << std::endl;
            findDate = 1;
            //if (itArg != mapArg.end())
                //itArg++;
        }
        // rajoute la condition genre pas trouvé (global value)
        std::cout << "c2\n";
        if (findDate == 0 && itArg != mapArg.end())
        {
            std::cout << "c3\n";
            for (std::multimap<std::string, std::string>::iterator itCSV = mapCSV.begin(); itCSV != mapCSV.end(); itCSV++)
            {
                if (itArg->first.find("date") == std::string::npos && itArg->first.find(itCSV->first) != std::string::npos )
                {
                    std::cout << itCSV->first << " => " << itArg->second << " = ";
                    std::cout << (std::atof((itArg->second).c_str()) * std::atof((itCSV->second).c_str()) ) << std::endl;
                    findDate = 1;
                }
                if (itArg->first.find("date") != std::string::npos)
                    findDate = 1;
            }
            std::cout << "c4\n";
            if (findDate == 0)
            {
                //std::cout << "ITarg->first is: " << itArg->first << std::endl;
                saveDate = newDate(itArg->first);
                //std::cout << "saveDate is : " << saveDate << std::endl;
                //return (1);
            }
            
            while (findDate == 0)
            {
                //std::cout << "c5\n";
                // sinon je remplace pas juste je l'utilise comme comparaison
                std::cout << "SaveDate: " << saveDate << std::endl;
                for (std::multimap<std::string, std::string>::iterator itCSV = mapCSV.begin(); itCSV != mapCSV.end(); itCSV++)
                {
                    if (saveDate.find("date") == std::string::npos && saveDate.find(itCSV->first) != std::string::npos )
                    {
                        std::cout << itArg->first << " => " << itArg->second << " = ";
                        std::cout << (std::atof((itArg->second).c_str()) * std::atof((itCSV->second).c_str())) << std::endl;
                        findDate = 1;
                    }
                }
                if (findDate == 0)
                    saveDate = newDate(saveDate);
            }
        }
    }
    fileArg.close();
    fileCSV.close();
}

 // déjà je vais me souvenir des dates les plus grandes et plus petites comme ça je vais gérer ces 2 cas
                // si la valeur de la variable globale a pas été trouvé bah je relance une loop 
                // la j'affiche la valeur juste avant
                // commen,t signifier qu'il s'agit de la valeur juste en dessous ?
                    // je fais étape par étape : toutes les années et tous les mois depuis 2009-01-02 jusqu'à 2023-03-29
                        //ya que les jours que je suis pas sur 
                        // du coup si date exsite pas je vais dans la meme année et le meme mois et je teste les jours -1
                    // en gros je créer une boucle qui va modifier la date de itArg-> first et réessayer
                    // je créer une variable qui va se souvenir de itArg de base