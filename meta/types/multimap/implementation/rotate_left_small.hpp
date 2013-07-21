//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_SMALL_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_SMALL_HPP

#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct rotate_left_small;
            
            template <typename Left, typename Right, typename CurrentValue>
            struct rotate_left_small <node<Left, Right, CurrentValue>>
            {
                typedef node
                <
                    node
                    <
                        Left,
                        typename Right::left,
                        CurrentValue
                    >,
                    typename Right::right,
                    typename Right::value_type
                >
                type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_SMALL_HPP
