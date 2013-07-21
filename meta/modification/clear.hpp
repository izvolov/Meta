//
//  meta/modification/clear.hpp
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_CLEAR_HPP
#define META_MODIFICATION_CLEAR_HPP

#include <meta/modification/implementation/clear.hpp>
#include <meta/types/type_list.hpp>
#include <meta/access/get_types.hpp>
#include <meta/creation/reinstantiate.hpp>

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

#endif // META_MODIFICATION_CLEAR_HPP
