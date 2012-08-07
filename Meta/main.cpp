#include <iostream>

#include <meta/types.hpp>
#include <meta/modification.hpp>

template <int Current, int Total, typename Map>
struct create_big_map_impl
{
    typedef typename meta::multimap::insert<Map, meta::pair<meta::integer<Current>, int>>::type new_map;
    typedef typename create_big_map_impl<Current + 1, Total, new_map>::type type;
};

template <int Total, typename Map>
struct create_big_map_impl <Total, Total, Map>
{
    typedef typename meta::multimap::insert<Map, meta::pair<meta::integer<Total>, int>>::type result_map;
    typedef result_map type;
};

template <int N>
struct create_big_map
{
    typedef typename meta::multimap::create<meta::pair<meta::integer<0>, int>>::type initial_map;
    typedef typename create_big_map_impl<1, N, initial_map>::type type;
};

template <typename T>
struct test
//{}
;

int main ()
{
//    typedef meta::map::create
//    <
//        meta::pair<meta::rational<3, 1>, short>,
//        meta::pair<meta::rational<3, 1>, long>,
//        meta::pair<meta::rational<1, 5>, double>,
//        meta::pair<meta::rational<2, 7>, long>,
//        meta::pair<meta::rational<-9, 19>, std::string>,
//        meta::pair<meta::rational<50,51>, char>
//    >
//    ::type map0;
//    
//    typedef meta::map::insert<map0, meta::pair<meta::rational<3, 5>, short>>::type map1;
//    typedef meta::map::at<map1, meta::rational<3, 1>>::type at;
//    
//    static_assert(std::is_same<at, short>::value, "Неверный результат.");
//    
////    typedef meta::get_pattern<meta::rational<1, 2>>::pattern<3, 4> t;
//    
//    std::cout << map1::root::size << std::endl;
    
    typedef create_big_map<1000>::type map;
//    test<map>();
    
    std::cout << map::root::size << ' ' << map::root::height << std::endl;
    
//    typedef meta::map::create<int>::type map;
    
    return 0;
}