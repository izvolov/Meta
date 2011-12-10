//
//  meta/transformation/pop_front.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_POP_FRONT_H
#define META_TRANSFORMATION_POP_FRONT_H

#include <meta/transformation/implementation/pop_front.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    template <typename Class>
    struct pop_front
    {
        typedef typename impl::pop_front<typename get_types<Class>::type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_INSERTION_POP_FRONT_H
