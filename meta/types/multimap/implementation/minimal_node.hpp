//
//  meta/types/multimap/implementation/minimal_node.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_MINIMAL_NODE_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_MINIMAL_NODE_H

#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Node>
            struct minimal_node;
            
            template <typename LeftBranch, typename RightBranch, typename CurrentValue>
            struct minimal_node <node<LeftBranch, RightBranch, CurrentValue>>
            {
                typedef typename minimal_node<LeftBranch>::type type;
            };
            
            template <typename RightBranch, typename CurrentValue>
            struct minimal_node <node<void, RightBranch, CurrentValue>>
            {
                typedef CurrentValue type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_MINIMAL_NODE_H
