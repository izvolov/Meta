//
//  meta/types/create_map.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_CREATE_MAP_H
#define META_TYPES_CREATE_MAP_H

#include <meta/types/map.hpp>
#include <meta/types/implementation/create_map.hpp>
#include <meta/types/implementation/map_node.hpp>

namespace meta
{    
    //!
    /*!
     */
    template <typename FirstValue, typename ... OtherValues>
    struct create_map
    {
        typedef map
        <
            typename impl::create_map
            <
                impl::map_node<void, void, FirstValue>,
                OtherValues ...
            >
            ::type
        >
        type;
    };
    
    template <typename Value>
    struct create_map <Value>
    {
        typedef map<impl::map_node<void, void, Value>> type;
    };
} // namespace meta

#endif // META_TYPES_CREATE_MAP_H
