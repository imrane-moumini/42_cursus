#include "search.hpp"
#include <cstring>
#include <iomanip>
void print_right_text(std::string str){
    if (str.length() > 10)
        std::cout << std::right << std::setw(10) << str.substr(0, 9) << "." << "|";
    else
        std::cout << std::right << std::setw(11) << str.substr(0, 10) << "|";
}
void print_phonebook(PhoneBook& phone_book, int index){
    print_right_text(phone_book.tab[index].get_first_name());
    print_right_text(phone_book.tab[index].get_last_name());
    print_right_text(phone_book.tab[index].get_nickname());
}

void print_specific_index(PhoneBook& phone_book, int index){
    std::cout << "First name: " << phone_book.tab[index - 1].get_first_name() << std::endl;
    std::cout << "Last name: " << phone_book.tab[index - 1].get_last_name() << std::endl;
    std::cout << "Nick name: " << phone_book.tab[index - 1].get_nickname() << std::endl;
    std::cout << "Phone number: " << phone_book.tab[index - 1].get_phone_number() << std::endl;
    std::cout << "Darkest secret: " << phone_book.tab[index - 1].get_darkest_secret() << std::endl;
}