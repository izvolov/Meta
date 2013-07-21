//
//  meta/modification/push_back.hpp
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_PUSH_BACK_HPP
#define META_MODIFICATION_PUSH_BACK_HPP

#include <meta/modification/implementation/push_back.hpp>
#include <meta/types/type_list.hpp>
#include <meta/access/get_types.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!     Вставка типа в конец шаблонного класса "Class".
    /*!
            Результатом этой метафункции является новая конкретизация шаблонного класса "Class", в
        которой в конец того набора типов, которым был конкретизирован входной класс, добавлен тип
        "Type".
            Время компиляции данной метафункции константно, то есть O(1).
     */
    template <typename Class, typename Type>
    struct push_back
    {
        typedef typename impl::push_back<typename get_types<Class>::type, Type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_PUSH_BACK_HPP
