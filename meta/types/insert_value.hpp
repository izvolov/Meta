//
//  meta/types/insert_value.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_INSERT_VALUE_H
#define META_TYPES_INSERT_VALUE_H

#include <meta/types/implementation/insert_value.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!
    /*!
     */
    template <typename Map, typename MapValue>
    struct insert_value
    {
        typedef typename impl::insert_value<typename Map::root, MapValue>::type new_root;
        typedef typename reinstantiate<Map, type_list<new_root>>::type type;
    };
} // namespace meta

#endif // META_TYPES_INSERT_VALUE_H
