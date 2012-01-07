//
//  meta/creation/lazy_instantiate.hpp
//
//  Дмитрий Изволов.
//  31 декабря 2011 года.
//

#ifndef META_CREATION_LAZY_INSTANTIATE_H
#define META_CREATION_LAZY_INSTANTIATE_H

#include <meta/types/type_list.hpp>

namespace meta
{
    
    //!     Конкретизация шаблонного класса при помощи списка "ленивых" элементов.
    /*!
            Аргументы данной метафункции — конкретизируемый шаблон и список типов, состоящий из
        метафункций, результат которых ещё не вычислен. Их результат вычисляется вместе с
        вычислением результата данной метафункции.
            "Ленивые" вычисления используются, например, в метафункциях условного выбора для того,
        чтобы игнорировать ненужные ветви компиляции. Это даёт возможность избежать непонятных
        ошибок и повысить эффективность алгоритмов.
            Результатом этой метафукнции является шаблон класса "Class", конкретизированный
        результатами соответствующих метафункций из списка типов "TypeList".
            Время компиляции (без учёта компиляции "ленивых" элементов) — константно, то есть O(1).
     */
    template <template <typename ...> class Class, typename TypeList>
    struct lazy_instantiate;
    
    template <template <typename ...> class Class, typename ... Types>
    struct lazy_instantiate <Class, type_list<Types ...>>
    {
        typedef Class<typename Types::type ...> type;
    };
} // namespace meta

#endif // META_CREATION_LAZY_INSTANTIATE_H
