//
//  meta/types/multimap/implementation/rotate_right.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_IMULTIMAP_MPLEMENTATION_ROTATE_RIGHT_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_H

#include <meta/types/multimap/implementation/left_height.h>
#include <meta/types/multimap/implementation/right_height.h>
#include <meta/types/multimap/implementation/rotate_right_small.h>
#include <meta/types/multimap/implementation/rotate_right_large.h>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct rotate_right
            {
                typedef typename select
                <
                    right_height<typename Node::left>::value <= left_height<typename Node::left>::value,
                    rotate_right_small<Node>,
                    rotate_right_large<Node>
                >
                ::type lazy_result;
                
                typedef typename lazy_result::type type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_ROTATE_RIGHT_H
