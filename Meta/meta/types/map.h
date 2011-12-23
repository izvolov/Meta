//
//  meta/types/map.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MAP_H
#define META_TYPES_MAP_H

#include <meta/types/create_map.h>

namespace meta
{    
    //!     Дерево.
    /*!
     */
    template <typename ... Values>
    struct map
    {
        typedef typename create_map<Values ...>::type root;
    };
} // namespace meta

#endif // META_TYPES_MAP_H
