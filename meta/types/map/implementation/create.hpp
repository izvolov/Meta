//
//  meta/types/map/implementation/create.hpp
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_IMPLEMENTATION_CREATE_H
#define META_TYPES_MAP_IMPLEMENTATION_CREATE_H

#include <meta/types/map/implementation/insert.hpp>

namespace meta
{
    namespace map
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
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_IMPLEMENTATION_CREATE_H
