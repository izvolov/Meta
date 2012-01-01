//
//  meta/types/erase_key.hpp
//
//  Дмитрий Изволов.
//  24 декабря 2011 года.
//

#ifndef META_TYPES_ERASE_KEY_H
#define META_TYPES_ERASE_KEY_H

#include <meta/types/implementation/erase_key.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{    
    //!
    /*!
     */
    template <typename Map, int Key>
    struct erase_key
    {
        typedef typename impl::erase_key<typename Map::root, Key>::type new_root;
        typedef typename reinstantiate<Map, type_list<new_root>>::type type;
    };
} // namespace meta

#endif // META_TYPES_ERASE_KEY_H
