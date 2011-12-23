//
//  meta/types/map_value.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MAP_VALUE_H
#define META_TYPES_MAP_VALUE_H

namespace meta
{
    template <int Key, typename Type>
    struct map_value
    {
        static constexpr int key = Key;
        typedef Type mapped_type;
    };
} // namespace meta

#endif // META_TYPES_MAP_VALUE_H
