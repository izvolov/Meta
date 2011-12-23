#include <iostream>
#include <tuple>

#include <meta/modification.h>
#include <meta/types.h>

int main ()
{
    // ---- Произвольные подмножества -------------------------------------------------------------
    
    typedef std::tuple<int, double, bool, char, float, int, bool, bool> tuple0;
    typedef meta::subset<tuple0, 5, 3, 1, 0, 2, 4, 6>::type sub;
    
    // ---- Двоичное дерево -----------------------------------------------------------------------
    
    typedef meta::create_map
    <
        meta::map_value<5, int>,
        meta::map_value<4, double>,
        meta::map_value<6, int>,
        meta::map_value<3, bool>,
        meta::map_value<2, long>
    >
    ::type map;
    
    typedef meta::insert_value<map, meta::map_value<-100500, std::string>>::type new_map;
    
    typedef meta::at_key<new_map, -100500>::type type;
    type string = "Это строка.";
            
    return 0;
}

// Распаковка кортежей: http://liveworkspace.org/code/8843c8742cffbc4bc6e2714a54a4a227
