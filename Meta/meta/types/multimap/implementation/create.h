//
//  meta/types/multimap/implementation/create.h
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_CREATE_H
#define META_TYPES_MULTIMAP_IMPLEMENTATION_CREATE_H

#include <meta/types/multimap/implementation/insert.h>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename MapNode, typename FirstValue, typename ... OtherValues>
            struct create
            {
                typedef typename create<typename insert<MapNode, FirstValue>::type, OtherValues ...>::type type;
            };
            
            template <typename MapNode, typename Value>
            struct create <MapNode, Value>
            {
                typedef typename insert<MapNode, Value>::type type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_CREATE_H
