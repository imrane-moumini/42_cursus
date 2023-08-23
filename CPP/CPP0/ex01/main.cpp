#include "PhoneBook.hpp"
#include "add.hpp"
#include <cstring>,
int nbr_contact;

void fill_contact_info(PhoneBook &phone_book, int i)
{

    fill_name(phone_book, i);
    fill_last_name(phone_book, i);
    fill_nickname(phone_book, i);
    fill_phone_number(phone_book, i);
    fill_darkest_secret(phone_book, i);
}
int main(int argc, char *argv[])
{
    int i;

    i = 0;
    std::string input;
    PhoneBook phone_book;
    // au lancement du programme ya une sorte de readline
    while (1)
    {
        std::cout << "Enter a Command\n";
        std::getline(std::cin, input);
        // l'utilisateur choisi entre ADD, SEARCh et EXIt, sinon refuse
        if (std::strcmp(input, "EXIT") == 0 || std::strcmp(input, "SEARCH") == 0 || std::strcmp(input, "ADD") == 0)
        {
            if (std::strcmp(input, "ADD") == 0)
            {
                nbr_contact++;
                if (nbr_contact > 8)
                    i = 0;
                phone_book.tab[i] = Contact();
                fill_contact_info(phone_book, i);
                i++;
            }
            else if (std::strcmp(input, "SEARCH") == 0)
            {
                
            }
            else if (std::strcmp(input, "EXIT") == 0)
            {
            }
        }
        else
            std::cout << "Your command is invalid, you can only choose between : 'EXIT' or 'SEARCH' or 'ADD'\n";
    };
}