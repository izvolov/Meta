//
//  meta/types/implementation/at_key.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_AT_KEY_H
#define META_TYPES_IMPLEMENTATION_AT_KEY_H

#include <meta/types/implementation/map_node.h>
#include <meta/common/select.h>

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
                Key == CurrentValue::key,
                typename CurrentValue::mapped_type,
                typename select
                <
                    Key < CurrentValue::key,
                    typename at_key<Left, Key>::type,
                    typename at_key<Right, Key>::type
                >
                ::type
            >
            ::type type;
        };

        template <typename Left, typename CurrentValue, int Key>
        struct at_key <map_node<Left, void, CurrentValue>, Key>
        {
            typedef typename select
            <
                Key == CurrentValue::key,
                typename CurrentValue::mapped_type,
                typename select
                <
                    Key < CurrentValue::key,
                    typename at_key<Left, Key>::type,
                    void
                >
                ::type
            >
            ::type type;
        };

        template <typename Right, typename CurrentValue, int Key>
        struct at_key <map_node<void, Right, CurrentValue>, Key>
        {
            typedef typename select
            <
                Key == CurrentValue::key,
                typename CurrentValue::mapped_type,
                typename select
                <
                    Key < CurrentValue::key,
                    void,
                    typename at_key<Right, Key>::type
                >
                ::type
            >
            ::type type;
        };

        template <typename CurrentValue, int Key>
        struct at_key <map_node<void, void, CurrentValue>, Key>
        {
            typedef typename select
            <
                Key == CurrentValue::key,
                typename CurrentValue::mapped_type,
                void
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_IMPLEMENTATION_AT_KEY_H
