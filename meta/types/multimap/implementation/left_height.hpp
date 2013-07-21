//
//  Дмитрий Изволов.
//  2 января 2012 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_LEFT_HEIGHT_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_LEFT_HEIGHT_HPP

#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct left_height;
            
            template <typename Left, typename Right, typename CurrentValue>
            struct left_height <node<Left, Right, CurrentValue>>
            {
                static constexpr int value = Left::height;
            };
            
            template <typename Right, typename CurrentValue>
            struct left_height <node<void, Right, CurrentValue>>
            {
                static constexpr int value = 0;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_LEFT_HEIGHT_HPP
