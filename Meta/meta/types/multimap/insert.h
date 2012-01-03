//
//  meta/types/multimap/insert.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_INSERT_VALUE_H
#define META_TYPES_MULTIMAP_INSERT_VALUE_H

#include <meta/types/multimap/implementation/insert.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    namespace multimap
    {
        //!
        /*!
         */
        template <typename Map, typename MapValue>
        struct insert
        {
            typedef typename impl::insert<typename Map::root, MapValue>::type new_root;
            typedef typename reinstantiate<Map, type_list<new_root>>::type type;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_INSERT_VALUE_H
