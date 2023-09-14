#include "PhoneBook.hpp"
#include "search.hpp"
#include "add.hpp"
#include <cstring>
#include <cstdlib>
int nbr_contact;

int is_numeric(const std::string& str) {
    for (long unsigned int i = 0;  i < str.length(); i++ ) {
        if (!std::isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void fill_contact_info(PhoneBook &phone_book, int i)
{

    fill_name(phone_book, i);
    fill_last_name(phone_book, i);
    fill_nickname(phone_book, i);
    fill_phone_number(phone_book, i);
    fill_darkest_secret(phone_book, i);
}
int main()
{
    int i;
    int affiche;
    affiche = 0;
    i = 0;
    std::string input;
    PhoneBook phone_book;
    // au lancement du programme ya une sorte de readline
    phone_book.tab[0] = Contact();
    phone_book.tab[0].fill_first_name("Artena");
    while (1)
    {
        std::cout << "Enter a Command\n";
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << "wrong input, relaunch the programm\n";
            return (0);
        }
        if (std::cin.fail())
        {
            std::cout << "wrong input, relaunch the program\n";
            return (0);
        }
        // l'utilisateur choisi entre ADD, SEARCh et EXIt, sinon refuse
        if (input.compare("EXIT") == 0 || input.compare("SEARCH") == 0 || input.compare("ADD") == 0)
        {
            if (input.compare("ADD") == 0)
            {
                if (nbr_contact <= 8)
                    nbr_contact++;
                if (nbr_contact > 8)
                    i = 0;
                phone_book.tab[i] = Contact();
                fill_contact_info(phone_book, i);
                i++;
            }
            else if (input.compare("SEARCH") == 0)
            {
                // gérer si le répertoir est vide
                if (phone_book.tab[0].get_first_name().compare("Artena") == 0)
                    std::cout << "the phoneBook is empty right now please add contact first\n";
                else
                {
                    while (affiche < 8 && affiche < nbr_contact)
                    {
                        std::cout << (1 + affiche) << "|";
                        std::cout << "   ";
                        print_phonebook(phone_book, affiche);
                        affiche++;
                        std::cout << std::endl;
                    }
                    // gérer affiche un index, gérer si l'index existe pas
                    std::cout << "Enter a specific index for which you would like to see info\n";
                    std::getline(std::cin, input);
                    while (!is_numeric(input) || (std::atoi(input.c_str()) > nbr_contact || std::atoi(input.c_str()) > 8 || std::atoi(input.c_str()) <= 0))
                    {
                        if (!is_numeric(input))
                            std::cout << input << " is not a number\n";
                        else if (std::atoi(input.c_str()) > nbr_contact || std::atoi(input.c_str()) > 8 || std::atoi(input.c_str()) <= 0)
                            std::cout << "there isn't any " << input << " index\n";
                        std::cout << "Enter a specific index for which you would like to see info\n";
                        std::getline(std::cin, input);
                    }
                    print_specific_index(phone_book, std::atoi(input.c_str()));
                }
                affiche = 0;
                
            }
            else if (input.compare("EXIT") == 0)
                return (1);
        }
        else
            std::cout << "Your command is invalid, you can only choose between : 'EXIT' or 'SEARCH' or 'ADD'\n";
    };
}
// voit pk le 8eme contact est ecris en vide