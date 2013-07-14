//
//  meta/types/multimap/minimal_node.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_MINIMAL_NODE_H
#define META_TYPES_MULTIMAP_MINIMAL_NODE_H

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

#endif // META_TYPES_MULTIMAP_MINIMAL_NODE_H
