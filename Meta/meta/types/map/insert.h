//
//  meta/types/map/insert.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_INSERT_H
#define META_TYPES_MAP_INSERT_H

#include <meta/types/map/implementation/insert.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    namespace map
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
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_INSERT_H
