//
//  meta/access/end.hpp
//
//  Дмитрий Изволов.
//  6 декабря 2011 года.
//

#ifndef META_ACCESS_END_H
#define META_ACCESS_END_H

#include <meta/access/iterator.hpp>
#include <meta/types/pattern_list.hpp>
#include <meta/access/get_pattern.hpp>
#include <meta/access/get_types.hpp>
#include <meta/types/type_list.hpp>

namespace meta
{
    namespace iter
    {
        //!     Получение итератора на конец шаблонного класса.
        /*!
                Результатом данной метафункции является итератор шаблонного класса "Class",
            указывающий на элемент списка типов шаблона входного класса, находящийся за последним
            типом этого списка (то есть, на самом деле, на пустоту).
         */
        template <typename Class>
        struct end
        {
            typedef iterator
            <
                pattern_list<get_pattern<Class>::template pattern>,
                typename get_types<Class>::type,
                type_list<>
            >
            type;
        };
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_END_H
