//
//  meta/types/map/instance.h
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_MAP_INSTANCE_H
#define META_TYPES_MAP_INSTANCE_H

namespace meta
{
    namespace map
    {
        //!     Дерево.
        /*!
         */
        template <typename Root>
        struct instance
        {
            typedef Root root;
        };
    } // namespace map
} // namespace meta

#endif // META_TYPES_MAP_INSTANCE_H
