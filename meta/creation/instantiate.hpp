//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_CREATION_INSTANTIATE_HPP
#define META_CREATION_INSTANTIATE_HPP

#include <meta/types/type_list.hpp>

namespace meta
{
    
    //!     Конкретизация шаблонного класса при помощи списка типов.
    /*!
            Результатом этой метафукнции является шаблон класса "Class", конкретизированный типами
        из списка типов "TypeList".
            Время компиляции постоянно, то есть O(1).
     */
    template <template <typename ...> class Class, typename TypeList>
    struct instantiate;
    
    template <template <typename ...> class Class, typename ... Types>
    struct instantiate <Class, type_list<Types ...>>
    {
        typedef Class<Types ...> type;
    };
} // namespace meta

#endif // META_CREATION_INSTANTIATE_HPP
