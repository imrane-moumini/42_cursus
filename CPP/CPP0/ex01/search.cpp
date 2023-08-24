#include "search.hpp"
#include <cstring>

void print_right_text(std::string str){
    int i;
    int diff;
    int length;
    i = 0;
    if (str.length() > 10)
    {
        
        while (i < 8)
        {
            std::cout << str[i];
            i++;
        }
        std::cout << '.';
        std::cout << '|';
    }
    else
    {
        diff = 10 - str.length();
        length = str.length();
        diff--;
        while (diff)
        {
            std::cout << ' ';
            diff--;
        }
        while (i < length)
        {
            std::cout << str[i];
            i++;
        }
        std::cout << '|';
    }
}
void print_phonebook(PhoneBook& phone_book, int index){
    //fonction général qui va compter et renvoyer le bon truc bien formate
    //print first name
    print_right_text(phone_book.tab[index].get_first_name());
    std::cout << "   ";
    //print last name
    print_right_text(phone_book.tab[index].get_last_name());
    std::cout << "   ";
    //print nickname
    print_right_text(phone_book.tab[index].get_nickname());
}

void print_specific_index(PhoneBook& phone_book, int index){
    std::cout << "First name: " << phone_book.tab[index - 1].get_first_name() << std::endl;
    std::cout << "Last name: " << phone_book.tab[index - 1].get_last_name() << std::endl;
    std::cout << "Nick name: " << phone_book.tab[index - 1].get_nickname() << std::endl;
    std::cout << "Phone number: " << phone_book.tab[index - 1].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << phone_book.tab[index - 1].get_darkest_secret() << std::endl;
}