//
//  meta/types/map/erase.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_ERASE_H
#define META_TYPES_MAP_ERASE_H

#include <meta/types/multimap/erase.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    namespace map
    {
        //!
        /*!
         */
        template <typename Map, typename Key>
        using erase = typename multimap::erase<Map, Key>;
        
//        template <typename Map, typename Key>
//        struct erase
//        {
//            typedef typename multimap::impl::erase<typename Map::root, Key>::type new_root;
//            typedef typename reinstantiate<Map, type_list<new_root>>::type type;
//        };
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_ERASE_H
