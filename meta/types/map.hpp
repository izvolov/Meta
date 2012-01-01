//
//  meta/types/map.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MAP_H
#define META_TYPES_MAP_H

#include <meta/types/at_key.hpp>
#include <meta/types/implementation/insert_value.hpp>
#include <meta/types/map_value.hpp>

namespace meta
{    
    //!     Дерево.
    /*!
     */
    template <typename Root>
    struct map
    {
        typedef Root root;
        
        template <int Key>
        using at = typename at_key<map, Key>::type;
        
        template <int Key, typename MappedType>
        using insert = map<typename impl::insert_value<root, map_value<Key, MappedType>>::type>;
    };
} // namespace meta

#endif // META_TYPES_MAP_H
