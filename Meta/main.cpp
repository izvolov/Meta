#include <iostream>

#include <meta/types.hpp>

int main ()
{
    typedef meta::rational<-2, 3> r1;
    typedef meta::rational<1, 2> r2;
    
    std::cout << meta::less     <r1, r2>::value << std::endl;
    std::cout << meta::greater  <r1, r2>::value << std::endl;
    std::cout << meta::equal    <r1, r2>::value << std::endl;
    std::cout << meta::different<r1, r2>::value << std::endl;
    
    return 0;
}