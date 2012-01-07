//
//  meta/types/multimap/implementation/insert.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_INSERT_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_INSERT_H

#include <meta/types/multimap/implementation/node.hpp>
#include <meta/common/select.hpp>
#include <meta/creation/lazy_instantiate.hpp>
#include <meta/types/type_list.hpp>
#include <meta/common/identity.hpp>
#include <meta/types/multimap/implementation/balance.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node, typename MapValue>
            struct insert;
            
            template <typename Left, typename Right, typename CurrentValue, typename InsertedValue>
            struct insert <node<Left, Right, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value < CurrentValue::first::value,
                    lazy_instantiate
                    <
                        node,
                        type_list
                        <
                            insert<Left, InsertedValue>,
                            identity<Right>,
                            identity<CurrentValue>
                        >
                    >,
                    lazy_instantiate
                    <
                        node,
                        type_list
                        <
                            identity<Left>,
                            insert<Right, InsertedValue>,
                            identity<CurrentValue>
                        >
                    >
                >
                ::type lazy_node;
                
                typedef typename lazy_node::type node;
                typedef typename balance<node>::type type;
            };
            
            template <typename Left, typename CurrentValue, typename InsertedValue>
            struct insert <node<Left, void, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value < CurrentValue::first::value,
                    lazy_instantiate
                    <
                        node,
                        type_list
                        <
                            insert<Left, InsertedValue>,
                            identity<void>,
                            identity<CurrentValue>
                        >
                    >,
                    identity
                    <
                        node<Left, node<void, void, InsertedValue>, CurrentValue>
                    >
                >
                ::type lazy_node;
                
                typedef typename lazy_node::type node;
                typedef typename balance<node>::type type;
            };
            
            template <typename Right, typename CurrentValue, typename InsertedValue>
            struct insert <node<void, Right, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value < CurrentValue::first::value,
                    identity
                    <
                        node<node<void, void, InsertedValue>, Right, CurrentValue>
                    >,
                    lazy_instantiate
                    <
                        node,
                        type_list
                        <
                            identity<void>,
                            insert<Right, InsertedValue>,
                            identity<CurrentValue>
                        >
                    >
                >
                ::type lazy_node;
                
                typedef typename lazy_node::type node;
                typedef typename balance<node>::type type;
            };
            
            template <typename CurrentValue, typename InsertedValue>
            struct insert <node<void, void, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value < CurrentValue::first::value,
                    node<node<void, void, InsertedValue>, void, CurrentValue>,
                    node<void, node<void, void, InsertedValue>, CurrentValue>
                >
                ::type type;
                
                // Разница высот левой и правой ветвей по модулю равна единице, поэтому балансировать
                // не нужно.
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_INSERT_H
