//
//  meta/types/map/at.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_AT_H
#define META_TYPES_MAP_AT_H

#include <meta/types/multimap/at.h>

namespace meta
{
    namespace map
    {
        //!
        /*!
         */
        template <typename Map, typename Key>
        using at = multimap::at<Map, Key>;
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_AT_H
