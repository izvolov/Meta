//
//  erase_key.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_ERASE_KEY_H
#define META_TYPES_IMPLEMENTATION_ERASE_KEY_H

#include <meta/types/implementation/map_node.hpp>
#include <meta/common/select.hpp>
#include <meta/creation/lazy_instantiate.hpp>
#include <meta/types/type_list.hpp>
#include <meta/common/identity.hpp>
#include <meta/types/map_value.hpp>
#include <meta/types/implementation/min_value.hpp>

namespace meta
{
    namespace impl
    {
        template <typename MapNode, int Key>
        struct erase_key;
        
        // Самый общий случай: слева и справа непустые поддеревья, ключ текущего узла не совпадает
        // с искомым ключом.
        template <typename Left, typename Right, typename CurrentValue, int Key>
        struct erase_key <map_node<Left, Right, CurrentValue>, Key>
        {
            typedef typename select
            <
                Key < CurrentValue::key,
                erase_key<Left, Key>,
                erase_key<Right, Key>
            >
            ::type eraser; // "Ленивый" результат удаления справа или слева.
            
            typedef typename select
            <
                Key < CurrentValue::key,
                lazy_instantiate<map_node, type_list<eraser, identity<Right>, identity<CurrentValue>>>,
                lazy_instantiate<map_node, type_list<identity<Left>, eraser, identity<CurrentValue>>>
            >
            ::type lazy_node; // "Ленивая" конкретизация нового узла дерева.
            
            // Хватит лениться! Пора вычислять окончательные результаты.
            typedef typename lazy_node::type type;
            typedef typename eraser::erased_value erased_value;
        };

        // Слева и справа непусто, ключ совпадает.
        template <typename Left, typename Right, int Key, typename Type>
        struct erase_key <map_node<Left, Right, map_value<Key, Type>>, Key>
        {
            typedef erase_key<Right, min_value<Right>::type::key> eraser;
            
            typedef map_node<Left, typename eraser::type, typename eraser::erased_value> type;            
            typedef map_value<Key, Type> erased_value;
        };
        
        // Справа пусто, ключ не совпадает.
        template <typename Left, typename CurrentValue, int Key>
        struct erase_key <map_node<Left, void, CurrentValue>, Key>
        {
            typedef erase_key<Left, Key> eraser;
            
            typedef map_node<typename eraser::type, void, CurrentValue> type;
            typedef typename eraser::erased_value erased_value;
        };
        
        // Справа пусто, ключ совпадает.
        template <typename Left, int Key, typename Type>
        struct erase_key <map_node<Left, void, map_value<Key, Type>>, Key>
        {
            typedef Left type;
            typedef map_value<Key, Type> erased_value;
        };
        
        // Слева пусто, ключ не совпадает.
        template <typename Right, typename CurrentValue, int Key>
        struct erase_key <map_node<void, Right, CurrentValue>, Key>
        {
            typedef erase_key<Right, Key> eraser;
            
            typedef map_node<void, typename eraser::type, CurrentValue> type;
            typedef typename eraser::erased_value erased_value;
        };
        
        // Слева пусто, ключ совпадает.
        template <typename Right, int Key, typename Type>
        struct erase_key <map_node<void, Right, map_value<Key, Type>>, Key>
        {
            typedef Right type;
            typedef map_value<Key, Type> erased_value;
        };
        
        // Слева и справа пусто, ключ не совпадает.
        template <typename CurrentValue, int Key>
        struct erase_key <map_node<void, void, CurrentValue>, Key>
        {
            typedef map_node<void, void, CurrentValue> type;
            typedef void erased_value;
        };
        
        // Слева и справа пусто, ключ совпадает.
        template <int Key, typename Type>
        struct erase_key <map_node<void, void, map_value<Key, Type>>, Key>
        {
            typedef void type;
            typedef map_value<Key, Type> erased_value;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_IMPLEMENTATION_ERASE_KEY_H
