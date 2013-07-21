//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_NODE_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_NODE_HPP

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
                typedef MapValue value_type;
                
                static constexpr int height = max<Left::height, Right::height>::value + 1;
                static constexpr int size = Left::size + Right::size + 1;
                
                typedef Left left;
                typedef Right right;
            };
            
            template <typename Left, typename MapValue>
            struct node <Left, void, MapValue>
            {
                typedef MapValue value_type;
                
                static constexpr int height = Left::height + 1;
                static constexpr int size = Left::size + 1;
                
                typedef Left left;
                typedef void right;
            };
            
            template <typename Right, typename MapValue>
            struct node <void, Right, MapValue>
            {
                typedef MapValue value_type;
                
                static constexpr int height = Right::height + 1;
                static constexpr int size = Right::size + 1;
                
                typedef void left;
                typedef Right right;
            };
            
            template <typename MapValue>
            struct node <void, void, MapValue>
            {
                typedef MapValue value_type;
                
                static constexpr int height = 1;
                static constexpr int size = 1;
                
                typedef void left;
                typedef void right;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_MAP_NODE_H
