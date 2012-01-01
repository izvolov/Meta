//
//  meta/types/implementation/map_node.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_IMPLEMENTATION_MAP_NODE_H
#define META_TYPES_IMPLEMENTATION_MAP_NODE_H

namespace meta
{
    namespace impl
    {
        template <typename Left, typename Right, typename MapValue>
        struct map_node
        {
            static constexpr int key = MapValue::key;
            typedef typename MapValue::mapped_type mapped_type; 
            
            typedef Left left;
            typedef Right right;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_IMPLEMENTATION_MAP_NODE_H
