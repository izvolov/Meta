//
//  meta/transformation/erase.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_ERASE_H
#define META_TRANSFORMATION_ERASE_H

#include <meta/transformation/implementation/erase.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    template <typename Class, int Index>
    struct erase
    {
        typedef typename impl::erase<typename get_types<Class>::type, Index>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_TRANSFORMATION_REMOVE_H
