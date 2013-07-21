//
//  meta/types/map/insert.hpp
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_INSERT_HPP
#define META_TYPES_MAP_INSERT_HPP

#include <meta/types/map/implementation/insert.hpp>
#include <meta/creation/reinstantiate.hpp>

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

#endif // META_TYPES_MAP_INSERT_HPP
