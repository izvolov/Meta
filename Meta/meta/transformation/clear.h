//
//  meta/transformation/clear.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_CLEAR_H
#define META_TRANSFORMATION_CLEAR_H

#include <meta/transformation/implementation/clear.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    template <typename Class>
    struct clear
    {
        typedef typename impl::clear<typename get_types<Class>::type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_TRANSFORMATION_CLEAR_H
