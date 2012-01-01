//
//  meta/types/implementation/min_value.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_MIN_VALUE_H
#define META_TYPES_IMPLEMENTATION_MIN_VALUE_H

#include <meta/types/implementation/map_node.hpp>
#include <meta/common/select.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Node>
        struct min_value;
        
        template <typename Left, typename Right, typename CurrentValue>
        struct min_value <map_node<Left, Right, CurrentValue>>
        {
            typedef typename min_value<Left>::type type;
        };
        
        template <typename Right, typename CurrentValue>
        struct min_value <map_node<void, Right, CurrentValue>>
        {
            typedef CurrentValue type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_IMPLEMENTATION_MIN_VALUE_H
