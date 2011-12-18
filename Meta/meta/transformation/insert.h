//
//  meta/transformation/insert.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_INSERT_H
#define META_TRANSFORMATION_INSERT_H

#include <meta/transformation/implementation/insert.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    template <typename Class, int Index, typename Type>
    struct insert
    {
        typedef typename impl::insert<typename get_types<Class>::type, Index, Type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_TRANSFORMATION_INSERT_H
