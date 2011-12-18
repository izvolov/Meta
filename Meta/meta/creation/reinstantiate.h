//
//  meta/creation/reinstantiate.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_CREATION_REINSTANTIATE_H
#define META_CREATION_REINSTANTIATE_H

#include <meta/utilities/type_list.h>

namespace meta
{
    //!     Переконкретизация шаблонного класса другими типами.
    /*!
            Результатом этой метафункции является шаблон класса "Class", конкретизированный типами
        "Types".
     */
    template <class Class, typename ... Types>
    struct reinstantiate;
    
    template <template <typename ...> class Class, typename ... OldTypes, typename ... NewTypes>
    struct reinstantiate <Class<OldTypes ...>, NewTypes ...>
    {
        typedef Class<NewTypes ...> type;
    };
    
    //!     Переконкретизация шаблонного класса другими типами при помощи списка типов.
    /*!
            Результатом этой метафукнции является шаблон "Class", конкретизированный типами из
        списка типов ("type_list<...>").
     */
    template <template <typename ...> class Class, typename ... OldTypes, typename ... NewTypes>
    struct reinstantiate <Class<OldTypes ...>, type_list<NewTypes ...>>
    {
        typedef Class<NewTypes ...> type;
    };
} // namespace meta

#endif // META_CREATION_REINSTANTIATE_H
