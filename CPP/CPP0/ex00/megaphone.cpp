#include <iostream>


int main(int argc, char *argv[])
{
	int i;
	int j;
	char letter;
	i = 1;
	j = 0;
    if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    }else{
		while (argc > 1)
		{
			argc--;
			while (argv[i][j])
			{
				letter = argv[i][j];
				if (letter >= 'a' && letter <= 'z')	
				{
					letter = (letter - 32);
					std::cout << letter;
				}
				else
					std::cout << argv[i][j];
				j++;
			}
			j = 0;
			i++;

			
		}
		std::cout << std::endl;
    }
}