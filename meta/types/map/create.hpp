//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_CREATE_HPP
#define META_TYPES_MAP_CREATE_HPP

#include <meta/types/map/instance.hpp>
#include <meta/types/map/implementation/create.hpp>
#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace map
    {
        //!
        /*!
         */
        template <typename FirstValue, typename ... OtherValues>
        struct create
        {
            typedef instance
            <
                typename impl::create
                <
                    multimap::impl::node<void, void, FirstValue>,
                    OtherValues ...
                >
                ::type
            >
            type;
        };
        
        template <typename Value>
        struct create <Value>
        {
            typedef instance<multimap::impl::node<void, void, Value>> type;
        };
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_CREATE_HPP
