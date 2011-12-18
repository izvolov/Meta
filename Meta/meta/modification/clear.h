//
//  meta/modification/clear.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_CLEAR_H
#define META_MODIFICATION_CLEAR_H

#include <meta/modification/implementation/clear.h>
#include <meta/types/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    //!     Удаление всех типов из шаблонного класса.
    /*!
            Результатом данной метафункции является шаблон входного класса ("Class"),
        конкретизированный пустым списком типов.
            Время компиляции — константно, то есть O(1).
     */
    template <typename Class>
    struct clear
    {
        typedef typename impl::clear<typename get_types<Class>::type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_CLEAR_H
