//
//  meta/transformation/push_back.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_PUSH_BACK_H
#define META_TRANSFORMATION_PUSH_BACK_H

#include <meta/transformation/implementation/push_back.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    template <typename Class, typename Type>
    struct push_back
    {
        typedef typename impl::push_back<typename get_types<Class>::type, Type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_TRANSFORMATION_PUSH_BACK_H
