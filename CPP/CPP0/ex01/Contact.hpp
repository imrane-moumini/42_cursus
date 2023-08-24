#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
// en fait le phonebook va enregistrer un tableau contenant des instances de contact 
class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public:

	Contact(){
		
	};
	// getter
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();
// setter
	void fill_first_name(std::string str);
	void fill_last_name(std::string str);
	void fill_nickname(std::string str);
	void fill_phone_number(std::string str);
	void fill_darkest_secret(std::string str);

};

#endif