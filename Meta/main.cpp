#include <iostream>

#include <meta/types.hpp>
#include <meta/modification.hpp>

template <typename T>
struct test
{}
;

int main ()
{
    typedef meta::multimap::build
    <
        meta::pair<meta::integer<0>, long>,
        meta::pair<meta::integer<1>, char>,
        meta::pair<meta::integer<2>, double>
    >
    ::type mmap0;
    
    test<mmap0>();
    
    typedef meta::multimap::erase<mmap0, meta::integer<1>>::type mmap1;
    typedef meta::multimap::erase<mmap1, meta::integer<2>>::type mmap2;
    typedef meta::multimap::erase<mmap2, meta::integer<0>>::type mmap3;
    test<mmap3>();
    
    std::cout << mmap2::root::size << std::endl;
        
    return 0;
}