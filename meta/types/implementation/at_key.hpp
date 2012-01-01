//
//  meta/types/implementation/at_key.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_AT_KEY_H
#define META_TYPES_IMPLEMENTATION_AT_KEY_H

#include <meta/types/implementation/map_node.hpp>
#include <meta/common/select.hpp>
#include <meta/types/map_value.hpp>
#include <meta/common/identity.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Node, int Key>
        struct at_key;
        
        template <typename Left, typename Right, typename CurrentValue, int Key>
        struct at_key <map_node<Left, Right, CurrentValue>, Key>
        {
            typedef typename select
            <
                Key < CurrentValue::key,
                at_key<Left, Key>,
                at_key<Right, Key>
            >
            ::type lazy_result;
            
            typedef typename lazy_result::type type;
        };
        
        template <typename Left, typename Right, int Key, typename Type>
        struct at_key <map_node<Left, Right, map_value<Key, Type>>, Key>
        {
            typedef Type type;
        };
        
        template <typename Left, typename CurrentValue, int Key>
        struct at_key <map_node<Left, void, CurrentValue>, Key>
        {
            typedef typename select
            <
                Key < CurrentValue::key,
                at_key<Left, Key>,
                identity<void>
            >
            ::type lazy_result;
            
            typedef typename lazy_result::type type;
        };
        
        template <typename Left, int Key, typename Type>
        struct at_key <map_node<Left, void, map_value<Key, Type>>, Key>
        {
            typedef Type type;
        };
        
        template <typename Right, typename CurrentValue, int Key>
        struct at_key <map_node<void, Right, CurrentValue>, Key>
        {
            typedef typename select
            <
                Key < CurrentValue::key,
                identity<void>,
                at_key<Right, Key>
            >
            ::type lazy_result;
            
            typedef typename lazy_result::type type;
        };
        
        template <typename Right, int Key, typename Type>
        struct at_key <map_node<void, Right, map_value<Key, Type>>, Key>
        {
            typedef Type type;
        };
        
        template <typename CurrentValue, int Key>
        struct at_key <map_node<void, void, CurrentValue>, Key>
        {
            typedef void type;
        };
        
        template <int Key, typename Type>
        struct at_key <map_node<void, void, map_value<Key, Type>>, Key>
        {
            typedef Type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_IMPLEMENTATION_AT_KEY_H
