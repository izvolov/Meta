//
//  meta/types/multimap/implementation/right_height.h
//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_RIGHT_HEIGHT_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_RIGHT_HEIGHT_H

#include <meta/types/multimap/implementation/node.h>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct right_height;
            
            template <typename Left, typename Right, typename CurrentValue>
            struct right_height <node<Left, Right, CurrentValue>>
            {
                static constexpr int value = Right::height;
            };
            
            template <typename Left, typename CurrentValue>
            struct right_height <node<Left, void, CurrentValue>>
            {
                static constexpr int value = 0;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_RIGHT_HEIGHT_H
