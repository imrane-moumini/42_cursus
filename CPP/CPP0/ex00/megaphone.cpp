#include <iostream>


int main(int argc, char *argv[])
{
	int i;

	i = 1;
    if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }else{
		while (argc > 1)
		{
			argc--;
			std::cout << argv[i];
			i++;
			
		}
		std::cout << std::endl;
    }
}