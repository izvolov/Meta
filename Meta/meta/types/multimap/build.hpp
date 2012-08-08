//
//  meta/types/multimap/implementation/build.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_BUILD_H
#define META_TYPES_MULTIMAP_BUILD_H

#include <meta/types/multimap/instance.hpp>
#include <meta/types/multimap/implementation/build.hpp>
#include <meta/types/multimap/implementation/node.hpp>

namespace meta
{
    namespace multimap
    {
        //!
        /*!
         */
        template <typename FirstValue, typename ... OtherValues>
        struct build
        {
            typedef instance
            <
                typename impl::build
                <
                    impl::node<void, void, FirstValue>,
                    OtherValues ...
                >
                ::type
            >
            type;
        };
        
        template <typename Value>
        struct build <Value>
        {
            typedef instance<impl::node<void, void, Value>> type;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_BUILD_H
