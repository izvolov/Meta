//
//  meta/types/insert_value.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_INSERT_VALUE_H
#define META_TYPES_INSERT_VALUE_H

#include <meta/types/map.h>
#include <meta/types/implementation/insert_value.h>

namespace meta
{
    template <typename Map, typename MapValue>
    struct insert_value
    {
        typedef map<typename impl::insert_value<typename Map::root, MapValue>::type> type;
    };
} // namespace meta

#endif // META_TYPES_INSERT_VALUE_H
