#include "PhoneBook.hpp"
#include "search.hpp"
#include "add.hpp"
#include <cstring>
#include <cstdlib>
int nbr_contact;

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
        // l'utilisateur choisi entre ADD, SEARCh et EXIt, sinon refuse
        if (input.compare("EXIT") == 0 || input.compare("SEARCH") == 0 || input.compare("ADD") == 0)
        {
            if (input.compare("ADD") == 0)
            {
                if (nbr_contact < 8)
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
                    std::cout << "the phoneBook is empty right now please add contact first";
                else
                {
                    while (affiche + 1 < nbr_contact)
                    {
                        std::cout << '0' + 1 + affiche << "|";
                        std::cout << "   ";
                        print_phonebook(phone_book, affiche);
                        affiche++;
                        std::cout << std::endl;
                    }
                }
                affiche = 0;
                // gérer affiche un index, gérer si l'index existe pas
                std::cout << "Enter a specific index for which you would like to see info\n";
                std::getline(std::cin, input);
                while (std::atoi(input.c_str()) > nbr_contact)
                {
                    std::cout << "there isn't any " << input << " index";
                    std::cout << "Enter a specific index for which you would like to see info\n";
                    std::getline(std::cin, input);
                }
                print_specific_index(phone_book, std::atoi(input.c_str()));
            }
            else if (input.compare("EXIT") == 0)
                return (1);
        }
        else
            std::cout << "Your command is invalid, you can only choose between : 'EXIT' or 'SEARCH' or 'ADD'\n";
    };
}