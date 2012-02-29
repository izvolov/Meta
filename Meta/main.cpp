#include <iostream>

#include <meta/types.hpp>

int main ()
{
    typedef meta::map::create
    <
        meta::pair<meta::rational<3, 1>, short>,
        meta::pair<meta::rational<3, 1>, long>,
        meta::pair<meta::rational<1, 5>, double>,
        meta::pair<meta::rational<2, 7>, long>,
        meta::pair<meta::rational<-9, 19>, std::string>,
        meta::pair<meta::rational<50,51>, char>
    >
    ::type map0;
    
    typedef meta::map::insert<map0, meta::pair<meta::rational<3, 5>, short>>::type map1;
    typedef meta::map::at<map1, meta::rational<3, 1>>::type at;
    
    static_assert(std::is_same<at, short>::value, "Неверный результат.");
        
    return 0;
}