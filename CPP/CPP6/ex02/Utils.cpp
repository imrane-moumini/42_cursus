#include "Base.hpp"
#include "A.hpp"
#include "C.hpp"
#include "B.hpp"

A* generateA(void)
{
    A* ptr;

    try{
        ptr = new A;
        std::cout << "new A is generated\n";
        return (ptr);
    } catch (std::bad_alloc& er){
        std::cout << er.what() << std::endl;
        return (NULL);
    }
    return (NULL);
}

B* generateB(void)
{
    B* ptr;

    try{
        ptr = new B;
        std::cout << "new B is generated\n";
        return (ptr);
    } catch (std::bad_alloc& er){
        std::cout << er.what() << std::endl;
        return (NULL);
    }
    return (NULL);
}

C* generateC(void)
{
    C* ptr;

    try{
        ptr = new C;
        std::cout << "new C is generated\n";
        return (ptr);
    } catch (std::bad_alloc& er){
        std::cout << er.what() << std::endl;
        return (NULL);
    }
    return (NULL);
}

Base* generate(void){

    Base* ptr;
    std::srand(std::time(0)); 
    int nbr = std::rand() % 3 + 1;
    if (nbr % 3)
        ptr = generateA();
    else if (nbr % 2)
        ptr = generateB();
    else
        ptr = generateC();
    return (ptr);
}

void identify(Base* p){
    if (p == NULL)
		std::cout << "P is NULL\n" ;
	else if (dynamic_cast<A*>(p))
		std::cout << "P is A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "P is B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "P is C\n";
}

void identify(Base& p){
	if (dynamic_cast<A*>(&p))
		std::cout << "P is A\n";
	else if (dynamic_cast<B*>(&p))
		std::cout << "P is B\n";
	else if (dynamic_cast<C*>(&p))
		std::cout << "P is C\n";
}
