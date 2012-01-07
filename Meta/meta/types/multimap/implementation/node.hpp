//
//  meta/types/multimap/implementation/node.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_NODE_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_NODE_H

#include <meta/common/max.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename Left, typename Right, typename MapValue>
            struct node
            {
                static constexpr int key = MapValue::first::value;
                typedef typename MapValue::second mapped_type;
                typedef MapValue value_type;
                
                static constexpr int height = max<Left::height, Right::height>::value + 1;
                
                typedef Left left;
                typedef Right right;
            };
            
            template <typename Left, typename MapValue>
            struct node <Left, void, MapValue>
            {
                static constexpr int key = MapValue::first::value;
                typedef typename MapValue::second mapped_type;
                typedef MapValue value_type;
                
                static constexpr int height = Left::height + 1;
                
                typedef Left left;
                typedef void right;
            };
            
            template <typename Right, typename MapValue>
            struct node <void, Right, MapValue>
            {
                static constexpr int key = MapValue::first::value;
                typedef typename MapValue::second mapped_type;
                typedef MapValue value_type;
                
                static constexpr int height = Right::height + 1;
                
                typedef void left;
                typedef Right right;
            };
            
            template <typename MapValue>
            struct node <void, void, MapValue>
            {
                static constexpr int key = MapValue::first::value;
                typedef typename MapValue::second mapped_type;
                typedef MapValue value_type;
                
                static constexpr int height = 1;
                
                typedef void left;
                typedef void right;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_MAP_NODE_H
