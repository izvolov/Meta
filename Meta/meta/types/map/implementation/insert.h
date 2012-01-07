//
//  meta/types/map/implementation/insert.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_IMPLEMENTATION_INSERT_H
#define META_TYPES_MAP_IMPLEMENTATION_INSERT_H

#include <meta/common/select.h>
#include <meta/types/multimap/implementation/at.h>
#include <meta/types/multimap/implementation/insert.h>
#include <meta/common/identity.h>

namespace meta
{
    namespace map
    {
        namespace impl
        {
            template <typename Node, typename MapValue>
            struct insert
            {
                typedef typename select
                <
                    std::is_void
                    <
                        typename multimap::impl::at<Node, typename MapValue::first>::type
                    >
                    ::value,
                    multimap::impl::insert<Node, MapValue>,
                    identity<Node>
                >
                ::type lazy_result;
                
                typedef typename lazy_result::type type;
            };
        } // namespace impl
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_IMPLEMENTATION_INSERT_H