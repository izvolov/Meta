//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_CREATION_REINSTANTIATE_HPP
#define META_CREATION_REINSTANTIATE_HPP

#include <meta/types/type_list.hpp>

namespace meta
{
    
    //!     Переконкретизация шаблонного класса другими типами при помощи списка типов.
    /*!
            Результатом этой метафукнции является шаблон класса "Class", конкретизированный типами
        из списка типов "TypeList".
            Время компиляции постоянно, то есть O(1).
     */
    template <class Class, typename TypeList>
    struct reinstantiate;
    
    template <template <typename ...> class Class, typename ... OldTypes, typename ... NewTypes>
    struct reinstantiate <Class<OldTypes ...>, type_list<NewTypes ...>>
    {
        typedef Class<NewTypes ...> type;
    };
} // namespace meta

#endif // META_CREATION_REINSTANTIATE_HPP
