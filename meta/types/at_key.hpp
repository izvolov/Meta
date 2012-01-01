//
//  meta/types/at_key.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_AT_KEY_H
#define META_TYPES_AT_KEY_H

#include <meta/types/implementation/at_key.hpp>

namespace meta
{    
    //!
    /*!
     */
    template <typename Map, int Key>
    struct at_key
    {
        typedef typename impl::at_key<typename Map::root, Key>::type type;
    };
} // namespace meta

#endif // META_TYPES_AT_KEY_H
