//
//  meta/types/multimap/minimum.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_MIN_VALUE_H
#define META_TYPES_MULTIMAP_MIN_VALUE_H

#include <meta/types/multimap/implementation/minimum.hpp>

namespace meta
{
    namespace multimap
    {
        //!
        /*!
         */
        template <typename Map>
        struct minimum
        {
            typedef typename impl::minimum<typename Map::root>::type type;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_MIN_VALUE_H
