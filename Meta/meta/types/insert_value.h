//
//  meta/types/insert_value.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_INSERT_VALUE_H
#define META_TYPES_INSERT_VALUE_H

#include <meta/types/implementation/insert_value.h>

namespace meta
{
    template <typename Node, typename MapValue>
    struct insert_value
    {
        typedef typename impl::insert_value<Node, MapValue>::type type;
    };
} // namespace meta

#endif // META_TYPES_INSERT_VALUE_H
