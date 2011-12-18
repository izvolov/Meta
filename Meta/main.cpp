#include <iostream>
#include <tuple>

#include <meta/access.h>
#include <meta/inspection.h>

int main ()
{
    typedef std::tuple<int, double, bool, char, float, int, bool, bool> tuple0;
    
    typedef meta::iter::begin<tuple0>::type begin;
    typedef meta::iter::end<tuple0>::type end;
    
    std::cout << meta::iter::count<begin, end, long>::value << std::endl;
    std::cout << meta::iter::count<begin, end, bool>::value << std::endl;
    
    typedef meta::iter::next<begin>::type next;
    typedef meta::iter::advance<begin, 7>::type advanced;
    
    std::cout << meta::iter::count<next, advanced, int>::value << std::endl;
        
    return 0;
}

// Распаковка кортежей: http://liveworkspace.org/code/c5f90916a12eccba9bceb5d4d2107483
