#include "MutantStack.hpp"

int main()
{
    {
	    std::cout << "-------------------------------MutantStack test : iterator--------------------------\n" << std::endl;
		MutantStack<int> sta;
		sta.push(8);
		sta.push(17);
		std::cout << sta.top() << std::endl;
		sta.pop();
		std::cout << sta.size() << std::endl;
		sta.push(3);
		sta.push(5);
		sta.push(737);
		sta.push(0);
		MutantStack<int>::iterator it = sta.begin();
		MutantStack<int>::iterator ite = sta.end();
		
		while (it != ite)
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
    }


	

	std::cout << "\n---------------------------MutantStack test : reverse_iterator-------------------------\n" << std::endl;

	    {
	    	MutantStack<int> mystack;
	    	for (int i=0; i<10; i++) mystack.push(i);
    
	    	MutantStack<int>::reverse_iterator it = mystack.rbegin();
	    	MutantStack<int>::reverse_iterator ite = mystack.rend();
    
	    	while (it != ite)
	    	{
	    		std::cout << *it << " ";
	    		++it;
	    	}
	    	std::cout << std::endl;
	    }
	


    std::cout << "\n ----------------------------Copy / = test----------------------------------\n" << std::endl;

	    {
	    	MutantStack<int> mystack;
	    	mystack.push(5);
	    	mystack.push(17);
	    	MutantStack<int> yourstac(mystack);
	    	MutantStack<int> stack3 = mystack;
	    	std::cout << mystack.size() << std::endl;
	    	std::cout << stack3.size() << std::endl;
	    }

    return 0;

}