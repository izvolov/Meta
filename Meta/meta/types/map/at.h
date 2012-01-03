//
//  meta/types/map/at.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_AT_H
#define META_TYPES_MAP_AT_H

#include <meta/types/multimap/implementation/at.h>

namespace meta
{
    namespace map
    {
        //!
        /*!
         */
        template <typename Map, typename Key>
        struct at
        {
            typedef typename multimap::impl::at<typename Map::root, Key>::type type;
        };
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_AT_H
