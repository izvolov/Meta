#include <iostream>

#include <meta/types.hpp>
#include <meta/modification.hpp>
#include <meta/access.hpp>

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
    
    typedef meta::type_list<int, double> tl;
    typedef meta::pattern_list<meta::get_pattern<tl>::pattern> pl;
    test<pl>();
    std::cout << meta::size<pl>::value << std::endl;
    
    typedef meta::value_list<int, 1, 2> vl;
    typedef meta::get_pattern<vl>::pattern<int, 4, 5> pl1;
    std::cout << meta::size<vl>::value << std::endl;
        
    return 0;
}