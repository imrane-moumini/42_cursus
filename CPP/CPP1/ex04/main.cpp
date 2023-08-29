#include <string>
#include <iostream>
#include <fstream>


int main(int argc, char *argv[]) {
    (void)argc;
    //argv[0] = nom du programme
    //argv[1] = nom de fichier (filename)
    //argv[2] = str1
    //argv[3] = str2

    //ouvrir argv[1]
    // copier argv[1] dans un nouveau fichier intitulé argv[1].replace 
    //dans le fichier argv[1].replace remplacer les occurences de str1 par str2

    // gerer les potentielles erreurs
    // std::string test.replace() est interdit
    // les fonctions C de manipulation de fichiers sont interdit du coup utiliser celles de CPP
    std::string strFile;
    std::ifstream file(argv[1]);
    // if str

    //systeme de remplacement dans un fichier
    size_t locationOccur = 0;
    while(std::getline(file, strFile))
    {
        std::cout << "BEFORE REPLACE STR IS: " << strFile << std::endl;
        locationOccur = strFile.find("test");
        while (locationOccur != std::string::npos)
        {
            std::cout << "IM IN LOCATION !!!!!!!\n";
            // jpeux jouer avec erase et insert
            strFile.erase(locationOccur,4);
            strFile.insert(locationOccur, "dackqjsdbnkjqsndolqsk,dqpmks,d");
            locationOccur = strFile.find("test", locationOccur);
        }
        std::cout << "AFTER REPLACE STR IS: " << strFile << std::endl;
    }
    
} 



