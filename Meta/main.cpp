#include <iostream>

#include <meta/types.hpp>
#include <meta/access.hpp>
#include <meta/inspection.hpp>

int main ()
{    
    typedef meta::map::create
    <
        meta::pair<meta::integer<1>, double>,
        meta::pair<meta::integer<2>, bool>,
        meta::pair<meta::integer<3>, short>,
        meta::pair<meta::integer<4>, long>,
        meta::pair<meta::integer<5>, float>,
        meta::pair<meta::integer<6>, unsigned>,
        meta::pair<meta::integer<7>, std::string>
    >
    ::type map0;
    
    typedef meta::map::at<map0, meta::integer<6>>::type type;
    type x = -1;
    
    std::cout << x << std::endl;
    
    return 0;
}