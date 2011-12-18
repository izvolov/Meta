//
//  meta/access/begin.h
//
//  Дмитрий Изволов.
//  6 декабря 2011 года.
//

#ifndef META_ACCESS_BEGIN_H
#define META_ACCESS_BEGIN_H

#include <meta/access/iterator.h>
#include <meta/types/pattern_list.h>
#include <meta/access/get_pattern.h>
#include <meta/types/type_list.h>
#include <meta/access/get_types.h>

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
    
#endif // META_ACCESS_BEGIN_H
