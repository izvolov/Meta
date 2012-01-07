//
//  meta/types/map/erase.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_ERASE_H
#define META_TYPES_MAP_ERASE_H

#include <meta/types/multimap/erase.h>

namespace meta
{
    namespace map
    {
        //!
        /*!
         */
        template <typename Map, typename Key>
        using erase = typename multimap::erase<Map, Key>;
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_ERASE_H
