#include <iostream>

#include <meta/types.hpp>

int main ()
{    
    typedef meta::create_map
    <
        meta::map_value<5, double>,
        meta::map_value<1, float>
    >
    ::type map0;
        
    typedef meta::insert_value<map0, meta::map_value<17, bool>>::type map1;
    typedef meta::erase_key<map1, 1>::type map2;
    
    typedef meta::at_key<map0, 5>::type type;
                
    return 0;
}