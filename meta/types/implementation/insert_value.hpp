//
//  meta/types/implementation/insert_value.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_INSERT_VALUE_H
#define META_TYPES_IMPLEMENTATION_INSERT_VALUE_H

#include <meta/types/implementation/map_node.hpp>
#include <meta/common/select.hpp>
#include <meta/creation/lazy_instantiate.hpp>
#include <meta/types/type_list.hpp>
#include <meta/common/identity.hpp>

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
                lazy_instantiate
                <
                    map_node,
                    type_list
                    <
                        insert_value<Left, InsertedValue>,
                        identity<Right>,
                        identity<CurrentValue>
                    >
                >,
                lazy_instantiate
                <
                    map_node,
                    type_list
                    <
                        identity<Left>,
                        insert_value<Right, InsertedValue>,
                        identity<CurrentValue>
                    >
                >
            >
            ::type lazy_node;
            
            typedef typename lazy_node::type type;
        };
        
        template <typename Left, typename CurrentValue, typename InsertedValue>
        struct insert_value <map_node<Left, void, CurrentValue>, InsertedValue>
        {
            typedef typename select
            <
                InsertedValue::key < CurrentValue::key,
                lazy_instantiate
                <
                    map_node,
                    type_list
                    <
                        insert_value<Left, InsertedValue>,
                        identity<void>,
                        identity<CurrentValue>
                    >
                >,
                identity
                <
                    map_node<Left, map_node<void, void, InsertedValue>, CurrentValue>
                >
            >
            ::type lazy_node;
            
            typedef typename lazy_node::type type;
        };
        
        template <typename Right, typename CurrentValue, typename InsertedValue>
        struct insert_value <map_node<void, Right, CurrentValue>, InsertedValue>
        {
            typedef typename select
            <
                InsertedValue::key < CurrentValue::key,
                identity
                <
                    map_node<map_node<void, void, InsertedValue>, Right, CurrentValue>
                >,
                lazy_instantiate
                <
                    map_node,
                    type_list
                    <
                        identity<void>,
                        insert_value<Right, InsertedValue>,
                        identity<CurrentValue>
                    >
                >
            >
            ::type lazy_node;
            
            typedef typename lazy_node::type type;
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
