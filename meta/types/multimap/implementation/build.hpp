//
//  meta/types/multimap/implementation/build.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_IMPLEMENTATION_BUILD_HPP
#define META_TYPES_MULTIMAP_IMPLEMENTATION_BUILD_HPP

#include <meta/types/multimap/implementation/insert.hpp>

namespace meta
{
    namespace multimap
    {
        namespace impl
        {
            template <typename MapNode, typename FirstValue, typename ... OtherValues>
            struct build
            {
                typedef typename build<typename insert<MapNode, FirstValue>::type, OtherValues ...>::type type;
            };
            
            template <typename MapNode, typename Value>
            struct build <MapNode, Value>
            {
                typedef typename insert<MapNode, Value>::type type;
            };
        } // namespace impl
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_IMPLEMENTATION_BUILD_HPP
