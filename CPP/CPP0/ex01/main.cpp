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
        if (std::strcmp(input, "EXIT") == 0 || std::strcmp(input, "SEARCH") == 0 || std::strcmp(input, "ADD") == 0)
        {
            if (std::strcmp(input, "ADD") == 0)
            {
                if (nbr_contact < 8)
                    nbr_contact++;
                if (nbr_contact > 8)
                    i = 0;
                phone_book.tab[i] = Contact();
                fill_contact_info(phone_book, i);
                i++;
            }
            else if (std::strcmp(input, "SEARCH") == 0)
            {
                // gérer si le répertoir est vide
                if (std::strcmp(phone_book.tab[0].get_first_name(), "Artena") == 0)
                    std::cout << "the phoneBook is empty right now please add contact first";
                else
                {
                    while (affiche + 1 < nbr_contact)
                    {
                        std::cout << '0' + 1 + affiche << "|";
                        
                        // fonction qui compte le nbr de car et qui compte le nbr de car et affiche en fonction de si + ou - de 10

                        // gérer le fait que ça s'affiche à droite
                        // en fait que ça saffiche a droite c'est simple, je remplis par la fin en mettant d'abord la barre
                        // et je met le même espace entre l'index barre et les autres mots et je fais commencer chaque text a la barre
                        // en fait si je défini une taille défini de 10 car et je commence par la fin ça va focément donner cette impression
                        // en mode la ou ya pas de caractère je met des espaces ça va donner cette impressionb
                        affiche++;
                    }
                }
                affiche = 0;
                // gérer affiche un index
                
            }
            else if (std::strcmp(input, "EXIT") == 0)
            {
                return (1);
            }
        }
        else
            std::cout << "Your command is invalid, you can only choose between : 'EXIT' or 'SEARCH' or 'ADD'\n";
    };
}