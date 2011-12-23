//
//  meta/types/implementation/create_map.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_CREATE_MAP_H
#define META_TYPES_IMPLEMENTATION_CREATE_MAP_H

#include <meta/types/implementation/insert_value.h>

namespace meta
{
    namespace impl
    {
        template <typename MapNode, typename FirstValue, typename ... OtherValues>
        struct create_map
        {
            typedef typename create_map<typename insert_value<MapNode, FirstValue>::type, OtherValues ...>::type type;
        };
        
        template <typename MapNode, typename Value>
        struct create_map <MapNode, Value>
        {
            typedef typename insert_value<MapNode, Value>::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_IMPLEMENTATION_CREATE_MAP_H
