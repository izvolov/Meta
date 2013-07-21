//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_MINIMAL_NODE_HPP
#define META_TYPES_MULTIMAP_MINIMAL_NODE_HPP

#include <meta/types/multimap/implementation/minimal_node.hpp>

namespace meta
{
    namespace multimap
    {
        //!
        /*!
         */
        template <typename Map>
        struct minimal_node
        {
            typedef typename impl::minimal_node<typename Map::root>::type type;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_MINIMAL_NODE_HPP
