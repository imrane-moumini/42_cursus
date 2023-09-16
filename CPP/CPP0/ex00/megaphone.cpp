#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int i;
	int j;
	//char letter;
	i = 1;
	j = 0;
    if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }else{
		while (argc > 1)
		{
			argc--;
			std::string display(argv[i]);
			for (unsigned long i = 0; i < display.length(); i++)
				display[i] = toupper(display[i]);
			std::cout << display;
			i++;
		}
		std::cout << std::endl;
    }
}