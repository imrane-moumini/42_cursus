#ifndef SEARCH_H
#define SEARCH_H
#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstring>
// en param c'est le phone book qui contient le tab + index
void print_phonebook(PhoneBook& phone_book, int index);
void print_right_text(std::string str);
void print_specific_index(PhoneBook& phone_book, int index);
#endif