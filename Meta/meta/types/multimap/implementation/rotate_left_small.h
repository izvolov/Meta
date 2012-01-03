//
//  meta/types/multimap/implementation/rotate_left_small.h
//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_SMALL_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_SMALL_H

#include <meta/types/multimap/implementation/node.h>

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

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_SMALL_H
