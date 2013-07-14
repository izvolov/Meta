//
//  meta/types/multimap/at.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_AT_H
#define META_TYPES_MULTIMAP_AT_H

#include <meta/types/multimap/implementation/at.hpp>

namespace meta
{
    namespace multimap
    {
        //!
        /*!
         */
        template <typename Map, typename Key>
        struct at
        {
            typedef typename impl::at<typename Map::root, Key>::type type;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_AT_H
