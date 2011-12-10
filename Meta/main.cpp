#include <iostream>
#include <tuple>

#include <meta/transformation.h>

int main ()
{
    typedef std::tuple<int, std::string, double, bool> tuple0;
    typedef meta::sub<tuple0, 1, 2>::type tuple1;
    tuple1 tuple("какой-то текст", 1.5);
    
    std::cout << std::get<0>(tuple) << std::endl;
    std::cout << std::get<1>(tuple) << std::endl;
    
    return 0;
}
