#include "Base.hpp"
#include "A.hpp"
#include "C.hpp"
#include "B.hpp"
#include "Utils.hpp"

int main(void){

    Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
}