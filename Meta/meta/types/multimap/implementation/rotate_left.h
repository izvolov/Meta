//
//  meta/types/multimap/implementation/rotate_left.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_H

#include <meta/types/multimap/implementation/left_height.h>
#include <meta/types/multimap/implementation/right_height.h>
#include <meta/types/multimap/implementation/rotate_left_small.h>
#include <meta/types/multimap/implementation/rotate_left_large.h>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct rotate_left
            {
                typedef typename select
                <
                    left_height<typename Node::right>::value <= right_height<typename Node::right>::value,
                    rotate_left_small<Node>,
                    rotate_left_large<Node>
                >
                ::type lazy_result;
                
                typedef typename lazy_result::type type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_LEFT_H
