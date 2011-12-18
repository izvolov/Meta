//
//  meta/creation/instantiate.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_CREATION_INSTANTIATE_H
#define META_CREATION_INSTANTIATE_H

#include <meta/creation/type_list.h>

namespace meta
{
    //!     Конкретизация шаблонного класса.
    /*!
            Результатом этой метафункции является шаблон "Class", конкретизированный типами
        "Types".
     */
    template <template <typename ...> class Class, typename ... Types>
    struct instantiate
    {
        typedef Class<Types ...> type;
    };
    
    //!     Конкретизация шаблонного класса при помощи списка типов.
    /*!
            Результатом этой метафукнции является шаблон "Class", конкретизированный типами из
        списка типов ("type_list<...>").
     */
    template <template <typename ...> class Class, typename ... Types>
    struct instantiate <Class, type_list<Types ...>>
    {
        typedef Class<Types ...> type;
    };
} // namespace meta

#endif // META_CREATION_INSTANTIATE_H
