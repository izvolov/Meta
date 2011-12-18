//
//  meta/modification/pop_front.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_POP_FRONT_H
#define META_MODIFICATION_POP_FRONT_H

#include <meta/modification/implementation/pop_front.h>
#include <meta/types/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    //!     Удаление первого типа из шаблонного класса "Class".
    /*!
            Результатом этой метафункции является новая конкретизация шаблонного класса "Class", в
        которой отсутствует первый тип из того набора типов, которым был конкретизирован входной
        класс.
            Время компиляции данной метафункции константно, то есть O(1).
     */
    template <typename Class>
    struct pop_front
    {
        typedef typename impl::pop_front<typename get_types<Class>::type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_INSERTION_POP_FRONT_H
