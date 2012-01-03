//
//  meta/types/multimap/implementation/balance.h
//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_BALANCE_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_BALANCE_H

#include <meta/types/multimap/implementation/left_height.h>
#include <meta/types/multimap/implementation/right_height.h>
#include <meta/types/multimap/implementation/rotate_left.h>
#include <meta/types/multimap/implementation/rotate_right.h>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct balance
            {
                static constexpr int height_difference = left_height<Node>::value - right_height<Node>::value;
                
                typedef typename select
                <
                    height_difference < -1,
                    rotate_left<Node>,
                    typename select
                    <
                        (height_difference > 1),
                        rotate_right<Node>,
                        identity<Node>
                    >
                    ::type
                >
                ::type lazy_result;
                
                typedef typename lazy_result::type type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_BALANCE_H
