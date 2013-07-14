//
//  meta/types/multimap/instance.hpp
//
//  Дмитрий Изволов.
//  22 декабря 2011 года.
//

#ifndef META_TYPES_MULTIMAP_INSTANCE_H
#define META_TYPES_MULTIMAP_INSTANCE_H

namespace meta
{
    namespace multimap
    {
        //!     Дерево.
        /*!
         */
        template <typename Root>
        struct instance
        {
            typedef Root root;
        };
    } // namespace multimap
} // namespace meta

#endif // META_TYPES_MULTIMAP_INSTANCE_H
