//
//  meta/types/multimap/implementation/rotate_left_large.hpp
//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_LARGE_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_LARGE_HPP

#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct rotate_left_large;
            
            template <typename Left, typename Right, typename CurrentValue>
            struct rotate_left_large <node<Left, Right, CurrentValue>>
            {
                typedef node
                <
                    node
                    <
                        Left,
                        typename Right::left::left,
                        CurrentValue
                    >,
                    node
                    <
                        typename Right::left::right,
                        typename Right::right,
                        typename Right::value_type
                    >,
                    typename Right::left::value_type
                >
                type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_LARGE_HPP
