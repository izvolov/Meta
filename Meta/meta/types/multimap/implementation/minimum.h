//
//  meta/types/multimap/implementation/minimum.h
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_MIN_VALUE_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_MIN_VALUE_H

#include <meta/types/multimap/implementation/node.h>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct minimum;
            
            template <typename Left, typename Right, typename CurrentValue>
            struct minimum <node<Left, Right, CurrentValue>>
            {
                typedef typename minimum<Left>::type type;
            };
            
            template <typename Right, typename CurrentValue>
            struct minimum <node<void, Right, CurrentValue>>
            {
                typedef CurrentValue type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_MIN_VALUE_H
