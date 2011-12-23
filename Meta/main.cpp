#include <iostream>
#include <tuple>

#include <meta/access.h>
#include <meta/inspection.h>
#include <meta/modification.h>
#include <meta/types.h>

template <typename ... T>
struct test
//{}
;

int main ()
{
    typedef std::tuple<int, double, bool, char, float, int, bool, bool> tuple0;
    typedef meta::subset<tuple0, 5, 3, 1, 0, 2, 4, 6>::type sub;
    
    typedef meta::map
    <
        meta::map_value<5, int>,
        meta::map_value<4, double>,
        meta::map_value<6, int>,
        meta::map_value<3, bool>,
        meta::map_value<2, long>
    >
    map;
    
    typedef meta::at_key<map, 2>::type a;
            
    return 0;
}

// Распаковка кортежей: http://liveworkspace.org/code/8843c8742cffbc4bc6e2714a54a4a227
