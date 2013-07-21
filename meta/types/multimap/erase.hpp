//
//  meta/types/multimap/erase.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_ERASE_HPP
#define META_TYPES_MULTIMAP_ERASE_HPP

#include <meta/types/multimap/implementation/erase.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    namespace multimap
    {
        //!
        /*!
         */
        template <typename Map, typename Key>
        struct erase
        {
            typedef typename impl::erase<typename Map::root, Key>::type new_root;
            typedef typename reinstantiate<Map, type_list<new_root>>::type type;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_ERASE_HPP
