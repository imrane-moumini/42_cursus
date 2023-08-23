#include "PhoneBook.hpp"
#include "add.hpp"
int check_if_input_is_empty(std::string contact_info)
{
    if (std::strcmp(input, "") == 0)
        return (1);
    return (0);
}

void fill_name(PhoneBook& phone_book, int i)
{
    std::string contact_info;
    std::cout << "Enter the first name of the contact\n";
    std::getline(std::cin, contact_info);
    while (check_if_input_is_empty(contact_info) == 1)
    {
        std::cout << "input can't be empty\n";
        std::cout << "Enter the first name of the contact\n";
        std::getline(std::cin, contact_info);
    }
    phone_book.tab[i].fill_first_name(contact_info);
}

void fill_last_name(PhoneBook& phone_book, int i)
{
    std::string contact_info;
    std::cout << "Enter the last name of the contact\n";
    std::getline(std::cin, contact_info);
    
    while (check_if_input_is_empty(contact_info) == 1)
    {
        std::cout << "input can't be empty\n";
        std::cout << "Enter the last name of the contact\n";
        std::getline(std::cin, contact_info);
    }
    phone_book.tab[i].fill_last_name(contact_info);
}

void fill_nickname(PhoneBook& phone_book, int i)
{
    std::string contact_info;
    std::cout << "Enter the nickname of the contact\n";
    std::getline(std::cin, contact_info);
    
    while (check_if_input_is_empty(contact_info) == 1)
    {
        std::cout << "input can't be empty\n";
        std::cout << "Enter the nickname of the contact\n";
        std::getline(std::cin, contact_info);
    }
    phone_book.tab[i].fill_nickname(contact_info);
}

void fill_phone_number(PhoneBook& phone_book, int i)
{
    std::string contact_info;
    std::cout << "Enter the phone number of the contact\n";
    std::getline(std::cin, contact_info);
    
    while (check_if_input_is_empty(contact_info) == 1)
    {
        std::cout << "input can't be empty\n";
        std::cout << "Enter the phone number of the contact\n";
        std::getline(std::cin, contact_info);
    }
    phone_book.tab[i].fill_phone_number(contact_info);
}

void fill_phone_number(PhoneBook& phone_book, int i)
{
    std::string contact_info;
    std::cout << "Enter the phone number of the contact\n";
    std::getline(std::cin, contact_info);
    
    while (check_if_input_is_empty(contact_info) == 1)
    {
        std::cout << "input can't be empty\n";
        std::cout << "Enter the phone number of the contact\n";
        std::getline(std::cin, contact_info);
    }
    phone_book.tab[i].fill_phone_number(contact_info);
}

void fill_darkest_secret(PhoneBook& phone_book, int i)
{
    std::string contact_info;
    std::cout << "Enter the darkest secret of the contact\n";
    std::getline(std::cin, contact_info);
    
    while (check_if_input_is_empty(contact_info) == 1)
    {
        std::cout << "input can't be empty\n";
        std::cout << "Enter the darkest secret of the contact\n";
        std::getline(std::cin, contact_info);
    }
    phone_book.tab[i].fill_darkest_secret(contact_info);
}