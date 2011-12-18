//
//  meta/transformation/replace.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_REPLACE_H
#define META_TRANSFORMATION_REPLACE_H

#include <meta/transformation/implementation/replace.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    template <typename Class, int Index, typename Type>
    struct replace
    {
        typedef typename impl::replace<typename get_types<Class>::type, Index, Type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_TRANSFORMATION_REPLACE_H
