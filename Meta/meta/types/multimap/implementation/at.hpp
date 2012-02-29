//
//  meta/types/multimap/implementation/at.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_AT_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_AT_H

#include <meta/types/multimap/implementation/node.hpp>
#include <meta/common/select.hpp>
#include <meta/types/comparison/less.hpp>
#include <meta/types/pair.hpp>
#include <meta/common/identity.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node, typename Key>
            struct at;
            
            template <typename Left, typename Right, typename CurrentValue, typename Key>
            struct at <node<Left, Right, CurrentValue>, Key>
            {
                typedef typename select
                <
                    less
                    <
                        Key,
                        typename CurrentValue::first
                    >
                    ::value,
                    at<Left, Key>,
                    at<Right, Key>
                >
                ::type lazy_result;
                
                typedef typename lazy_result::type type;
            };
            
            template <typename Left, typename Right, typename Key, typename Type>
            struct at <node<Left, Right, pair<Key, Type>>, Key>
            {
                typedef Type type;
            };
            
            template <typename Left, typename CurrentValue, typename Key>
            struct at <node<Left, void, CurrentValue>, Key>
            {
                typedef typename select
                <
                    less
                    <
                        Key,
                        typename CurrentValue::first
                    >
                    ::value,
                    at<Left, Key>,
                    identity<void>
                >
                ::type lazy_result;
                
                typedef typename lazy_result::type type;
            };
            
            template <typename Left, typename Key, typename Type>
            struct at <node<Left, void, pair<Key, Type>>, Key>
            {
                typedef Type type;
            };
            
            template <typename Right, typename CurrentValue, typename Key>
            struct at <node<void, Right, CurrentValue>, Key>
            {
                typedef typename select
                <
                    less
                    <
                        Key,
                        typename CurrentValue::first
                    >
                    ::value,
                    identity<void>,
                    at<Right, Key>
                >
                ::type lazy_result;
                
                typedef typename lazy_result::type type;
            };
            
            template <typename Right, typename Key, typename Type>
            struct at <node<void, Right, pair<Key, Type>>, Key>
            {
                typedef Type type;
            };
            
            template <typename CurrentValue, typename Key>
            struct at <node<void, void, CurrentValue>, Key>
            {
                typedef void type;
            };
            
            template <typename Key, typename Type>
            struct at <node<void, void, pair<Key, Type>>, Key>
            {
                typedef Type type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_AT_KEY_H
