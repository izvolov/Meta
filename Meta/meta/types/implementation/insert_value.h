//
//  meta/types/implementation/insert_value.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_INSERT_VALUE_H
#define META_TYPES_IMPLEMENTATION_INSERT_VALUE_H

#include <meta/types/implementation/map_node.h>
#include <meta/common/select.h>

namespace meta
{
    namespace impl
    {
        template <typename Node, typename MapValue>
        struct insert_value;
        
        template <typename Left, typename Right, typename CurrentValue, typename InsertedValue>
        struct insert_value <map_node<Left, Right, CurrentValue>, InsertedValue>
        {
            typedef typename select
            <
                InsertedValue::key < CurrentValue::key,
                map_node<typename insert_value<Left, InsertedValue>::type, Right, CurrentValue>,
                map_node<Left, typename insert_value<Right, InsertedValue>::type, CurrentValue>
            >
            ::type type;
        };
        
        template <typename Left, typename CurrentValue, typename InsertedValue>
        struct insert_value <map_node<Left, void, CurrentValue>, InsertedValue>
        {
            typedef typename select
            <
                InsertedValue::key < CurrentValue::key,
                map_node<typename insert_value<Left, InsertedValue>::type, void, CurrentValue>,
                map_node<Left, map_node<void, void, InsertedValue>, CurrentValue>
            >
            ::type type;
        };
        
        template <typename Right, typename CurrentValue, typename InsertedValue>
        struct insert_value <map_node<void, Right, CurrentValue>, InsertedValue>
        {
            typedef typename select
            <
                InsertedValue::key < CurrentValue::key,
                map_node<map_node<void, void, InsertedValue>, Right, CurrentValue>,
                map_node<void, typename insert_value<Right, InsertedValue>::type, CurrentValue>
            >
            ::type type;
        };
        
        template <typename CurrentValue, typename InsertedValue>
        struct insert_value <map_node<void, void, CurrentValue>, InsertedValue>
        {
            typedef typename select
            <
                InsertedValue::key < CurrentValue::key,
                map_node<map_node<void, void, InsertedValue>, void, CurrentValue>,
                map_node<void, map_node<void, void, InsertedValue>, CurrentValue>
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_IMPLEMENTATION_INSERT_VALUE_H
