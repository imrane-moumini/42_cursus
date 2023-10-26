#include "BitcoinExchange.hpp"

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

std::map<std::string, float>& fillMap(std::map<std::string, float>& mapFile,std::ifstream& file, int nbr){
    std::string firstPart;
    std::string secondPart;
    std::string line;
    while(std::getline(file, line))
    {
        firstPart = extractFirstPart(line, nbr);
        secondPart = extractLastPart(line, nbr);
        mapFile[firstPart] = std::atof(secondPart.c_str());
        //std::cout << mapFile[firstPart] << std::endl;
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
    std::map<std::string, float> mapCSV;
    std::map<std::string, float> mapArg;
    
    
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
    

    // il fauit que je lise mon fichier ligne par ligne
    // faut que je vérifie si le fichier n'est pas empty
    // ensuite il faut que je découpe la ligne en 2
    // faut que je vérifie si la premiere partie est valide
    // faut que je vérifie si la deuxième partie est valide
    // faut que je transforme la deuxieme partie en chiffre
    // faut que je remplie mon objet en renvoyant bien les bonnes parties
    mapCSV = fillMap(mapCSV,fileCSV,1);
    std::cout << "new fill MAP\n";
    mapArg = fillMap(mapArg,fileArg,0);
    std::cout << "size is "<<mapArg.size() << std::endl;
   
    for (std::map<std::string, float>::iterator itArg = mapArg.begin(); itArg != mapArg.end(); itArg++)
    {
        //std::cout << itArg->second << std::endl;
        for (std::map<std::string, float>::iterator itCSV = mapCSV.begin(); itCSV != mapCSV.end(); itCSV++)
        {
            //voir pk ya une valeur en trop dans mon mapArg

            //std::cout << "ARG: "<< itArg->second << std::endl;
            //std::cout << "FILE: "<< itCSV->first << std::endl;
            if (itArg->first.find(itCSV->first) != std::string::npos )
            {
                std::cout << "ARG second: " << itArg->second <<std::endl;
                std::cout << "FILE second " << itCSV->second <<std::endl;
                std::cout << ( itArg->second * itCSV->second ) << std::endl;
            }
        }
    }
    fileArg.close();
    fileCSV.close();
}