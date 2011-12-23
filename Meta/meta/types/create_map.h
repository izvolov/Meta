//
//  meta/types/create_map.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_CREATE_MAP_H
#define META_TYPES_CREATE_MAP_H

#include <meta/types/implementation/map_node.h>
#include <meta/types/implementation/create_map.h>

namespace meta
{    
    //!
    /*!
     */
    template <typename FirstValue, typename ... OtherValues>
    struct create_map
    {
        typedef typename impl::create_map<impl::map_node<void, void, FirstValue>, OtherValues ...>::type type;
    };
} // namespace meta

#endif // META_TYPES_CREATE_MAP_H
