#include "Span.hpp"

int main()
{
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    
    try {
        sp.addNumber(6);
    } catch (Span::FullVect& obj){
        std::cout << obj.what();
    }
}

{
    std::cout << "--------------------------ADD RANGE---------------------\n";
    Span sp = Span(100);
    std::vector<int> vector;
    for (int i = 0; i < 100 ;i++)
        vector.push_back(8);
    try {
        sp.addRange(vector.begin(), vector.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    } catch (Span::FullVect& obj){
        std::cout << obj.what();
    }
}
    return 0;
}