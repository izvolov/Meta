//
//  meta/types/map/erase.hpp
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_ERASE_HPP
#define META_TYPES_MAP_ERASE_HPP

#include <meta/types/multimap/erase.hpp>

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

#endif // META_TYPES_MAP_ERASE_HPP
