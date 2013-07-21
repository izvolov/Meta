//
//  meta/types/multimap/implementation/erase.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_ERASE_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ERASE_HPP

#include <meta/types/multimap/implementation/node.hpp>
#include <meta/creation/lazy_instantiate.hpp>
#include <meta/types/type_list.hpp>
#include <meta/common/identity.hpp>
#include <meta/types/multimap/implementation/balance.hpp>
#include <meta/types/pair.hpp>
#include <meta/types/multimap/implementation/minimal_node.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename MapNode, typename Key>
            struct erase;
            
            // Самый общий случай: слева и справа непустые ветви, ключ текущего узла не совпадает с
            // искомым ключом.
            template <typename Left, typename Right, typename CurrentValue, typename Key>
            struct erase <node<Left, Right, CurrentValue>, Key>
            {
                typedef typename std::conditional
                <
                    Key::value < CurrentValue::first::value,
                    erase<Left, Key>,
                    erase<Right, Key>
                >
                ::type eraser; // "Ленивый" результат удаления справа или слева.
                
                typedef typename std::conditional
                <
                    Key::value < CurrentValue::first::value,
                    lazy_instantiate<node, type_list<eraser, identity<Right>, identity<CurrentValue>>>,
                    lazy_instantiate<node, type_list<identity<Left>, eraser, identity<CurrentValue>>>
                >
                ::type lazy_node; // "Ленивая" конкретизация нового узла дерева.
                
                // Хватит лениться! Пора вычислять окончательные результаты.
                typedef typename lazy_node::type node;
                typedef typename balance<node>::type type;
                typedef typename eraser::erased_value erased_value;
            };

            // Слева и справа непусто, ключ совпадает.
            template <typename Left, typename Right, typename Key, typename Mapped>
            struct erase <node<Left, Right, pair<Key, Mapped>>, Key>
            {
                typedef erase<Right, typename minimal_node<Right>::type::first> eraser;
                
                typedef node<Left, typename eraser::type, typename eraser::erased_value> node;
                typedef typename balance<node>::type type;            
                typedef pair<Key, Mapped> erased_value;
            };
            
            // Справа пусто, ключ не совпадает.
            template <typename Left, typename CurrentValue, typename Key>
            struct erase <node<Left, void, CurrentValue>, Key>
            {
                typedef erase<Left, Key> eraser;
                
                typedef node<typename eraser::type, void, CurrentValue> type;
                typedef typename eraser::erased_value erased_value;
                
                // Если справа пусто, а слева было что-то удалено, то это значит, что и слева
                // теперь пусто (высота левой ветви не может быть больше единицы, поскольку дерево
                // уже отбалансировано при построении), поэтому балансировать не нужно.
                // Если же слева ничего не было удалено (ключ попросту не был найден), то тем более
                // балансировать ничего не надо.
            };
            
            // Справа пусто, ключ совпадает.
            template <typename Left, typename Key, typename Mapped>
            struct erase <node<Left, void, pair<Key, Mapped>>, Key>
            {
                typedef Left type;
                typedef pair<Key, Mapped> erased_value;
                
                // В левой ветви ничего не изменилось, балансировать не нужно.
            };
            
            // Слева пусто, ключ не совпадает.
            template <typename Right, typename CurrentValue, typename Key>
            struct erase <node<void, Right, CurrentValue>, Key>
            {
                typedef erase<Right, Key> eraser;
                
                typedef node<void, typename eraser::type, CurrentValue> type;
                typedef typename eraser::erased_value erased_value;
                
                // Если слева пусто, а справа было что-то удалено, то это значит, что и справа
                // теперь пусто (высота правой ветви не может быть больше единицы, поскольку дерево
                // уже отбалансировано при построении), поэтому балансировать не нужно.
                // Если же справа ничего не было удалено (ключ попросту не был найден), то тем
                // более балансировать ничего не надо.
            };
            
            // Слева пусто, ключ совпадает.
            template <typename Right, typename Key, typename Mapped>
            struct erase <node<void, Right, pair<Key, Mapped>>, Key>
            {
                typedef Right type;
                typedef pair<Key, Mapped> erased_value;
                
                // В правой ветви ничего не изменилось, балансировать не нужно.
            };
            
            // Слева и справа пусто, ключ не совпадает.
            template <typename CurrentValue, typename Key>
            struct erase <node<void, void, CurrentValue>, Key>
            {
                typedef node<void, void, CurrentValue> type;
                typedef void erased_value;
                
                // Балансировать не нужно, поскольку искомый ключ не был найден и ничего не было
                // удалено.
            };
            
            // Слева и справа пусто, ключ совпадает.
            template <typename Key, typename Mapped>
            struct erase <node<void, void, pair<Key, Mapped>>, Key>
            {
                typedef void type;
                typedef pair<Key, Mapped> erased_value;
                
                // Балансировать не нужно, потому что нечего.
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ERASE_KEY_H
