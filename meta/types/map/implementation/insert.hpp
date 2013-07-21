//
//  meta/types/map/implementation/insert.hpp
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_IMPLEMENTATION_INSERT_HPP
#define META_TYPES_MAP_IMPLEMENTATION_INSERT_HPP

#include <meta/types/multimap/implementation/at.hpp>
#include <meta/types/multimap/implementation/insert.hpp>
#include <meta/common/identity.hpp>

namespace meta
{
    namespace map
    {
        namespace impl
        {
            template <typename Node, typename MapValue>
            struct insert
            {
                typedef typename std::conditional
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

#endif // META_TYPES_MAP_IMPLEMENTATION_INSERT_HPP
