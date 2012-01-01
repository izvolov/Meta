//
//  meta/modification/reverse.hpp
//
//  Дмитрий Изволов.
//  11 декабря 2011 года.
//

#ifndef META_MODIFICATION_REVERSE_H
#define META_MODIFICATION_REVERSE_H

#include <meta/modification/implementation/reverse.hpp>
#include <meta/access/get_types.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!     Обращение типов в шаблонном классе.
    /*
            Результатом этой метафункции является новая конкретизация шаблона класса "Class", в
        которой все типы, которыми он был конкретизирован ранее, поставлены в обратном порядке.
            Время компиляции данной метафункции пропорционально количеству типов в конкретизации
        входного класса, то есть O(S), где S — число параметров шаблона входного класса.
     */
    template <typename Class>
    struct reverse
    {
        typedef typename impl::reverse<typename get_types<Class>::type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_REVERSE_H
