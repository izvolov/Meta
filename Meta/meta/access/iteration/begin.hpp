//
//  meta/access/iteration/begin.hpp
//
//  Дмитрий Изволов.
//  6 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_BEGIN_H
#define META_ACCESS_ITERATION_BEGIN_H

#include <meta/access/iteration/iterator.hpp>
#include <meta/types/pattern_list.hpp>
#include <meta/access/get_pattern.hpp>
#include <meta/types/type_list.hpp>
#include <meta/access/get_types.hpp>

namespace meta
{
    namespace iter
    {
        //!     Получение итератора на начало шаблонного класса.
        /*!
                Результатом данной метафункции является итератор на первый элемент списка типов
            шаблонного класса "Class".
         */
        template <typename Class>
        struct begin
        {
            typedef iterator
            <
                pattern_list<get_pattern<Class>::template pattern>,
                type_list<>,
                typename get_types<Class>::type
            >
            type;
        };
    } // namespace iter
} // namespace meta
    
#endif // META_ACCESS_ITERATION_BEGIN_H
