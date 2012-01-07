//
//  meta/types/multimap/implementation/create.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_CREATE_H
#define META_TYPES_MULTIMAP_CREATE_H

#include <meta/types/multimap/instance.hpp>
#include <meta/types/multimap/implementation/create.hpp>
#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
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
                    impl::node<void, void, FirstValue>,
                    OtherValues ...
                >
                ::type
            >
            type;
        };
        
        template <typename Value>
        struct create <Value>
        {
            typedef instance<impl::node<void, void, Value>> type;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_CREATE_H
