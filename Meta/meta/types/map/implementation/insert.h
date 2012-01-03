//
//  meta/types/map/implementation/insert.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_IMPLEMENTATION_INSERT_H
#define META_TYPES_MAP_IMPLEMENTATION_INSERT_H

#include <meta/types/multimap/implementation/node.h>
#include <meta/common/select.h>
#include <meta/creation/lazy_instantiate.h>
#include <meta/types/type_list.h>
#include <meta/common/identity.h>
#include <meta/types/multimap/implementation/balance.h>

namespace meta
{
    namespace map
    {
        namespace impl
        {
            template <typename Node, typename MapValue>
            struct insert;
            
            template <typename Left, typename Right, typename CurrentValue, typename InsertedValue>
            struct insert <multimap::impl::node<Left, Right, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value == CurrentValue::first::value,
                    identity<multimap::impl::node<Left, Right, CurrentValue>>,
                    typename select
                    <
                        InsertedValue::first::value < CurrentValue::first::value,
                        lazy_instantiate
                        <
                            multimap::impl::node,
                            type_list
                            <
                                insert<Left, InsertedValue>,
                                identity<Right>,
                                identity<CurrentValue>
                            >
                        >,
                        lazy_instantiate
                        <
                            multimap::impl::node,
                            type_list
                            <
                                identity<Left>,
                                insert<Right, InsertedValue>,
                                identity<CurrentValue>
                            >
                        >
                    >
                    ::type
                >
                ::type lazy_node;
                
                typedef typename lazy_node::type node;
                typedef typename multimap::impl::balance<node>::type type;
            };
            
            template <typename Left, typename CurrentValue, typename InsertedValue>
            struct insert <multimap::impl::node<Left, void, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value == CurrentValue::first::value,
                    identity<multimap::impl::node<Left, void, CurrentValue>>,
                    typename select
                    <
                        InsertedValue::first::value < CurrentValue::first::value,
                        lazy_instantiate
                        <
                            multimap::impl::node,
                            type_list
                            <
                                insert<Left, InsertedValue>,
                                identity<void>,
                                identity<CurrentValue>
                            >
                        >,
                        identity
                        <
                            multimap::impl::node<Left, multimap::impl::node<void, void, InsertedValue>, CurrentValue>
                        >
                    >
                    ::type
                >
                ::type lazy_node;
                
                typedef typename lazy_node::type node;
                typedef typename multimap::impl::balance<node>::type type;
            };
            
            template <typename Right, typename CurrentValue, typename InsertedValue>
            struct insert <multimap::impl::node<void, Right, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value == CurrentValue::first::value,
                    identity<multimap::impl::node<void, Right, CurrentValue>>,
                    typename select
                    <
                        InsertedValue::first::value < CurrentValue::first::value,
                        identity
                        <
                            multimap::impl::node<multimap::impl::node<void, void, InsertedValue>, Right, CurrentValue>
                        >,
                        lazy_instantiate
                        <
                            multimap::impl::node,
                            type_list
                            <
                                identity<void>,
                                insert<Right, InsertedValue>,
                                identity<CurrentValue>
                            >
                        >
                    >
                    ::type
                >
                ::type lazy_node;
                
                typedef typename lazy_node::type node;
                typedef typename multimap::impl::balance<node>::type type;
            };
            
            template <typename CurrentValue, typename InsertedValue>
            struct insert <multimap::impl::node<void, void, CurrentValue>, InsertedValue>
            {
                typedef typename select
                <
                    InsertedValue::first::value == CurrentValue::first::value,
                    multimap::impl::node<void, void, CurrentValue>,
                    typename select
                    <
                        InsertedValue::first::value < CurrentValue::first::value,
                        multimap::impl::node<multimap::impl::node<void, void, InsertedValue>, void, CurrentValue>,
                        multimap::impl::node<void, multimap::impl::node<void, void, InsertedValue>, CurrentValue>
                    >
                    ::type
                >
                ::type type;
                
                // Разница высот левой и правой ветвей по модулю равна единице, поэтому балансировать
                // не нужно.
            };
        } // namespace impl
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_IMPLEMENTATION_INSERT_H
