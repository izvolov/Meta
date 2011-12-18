//
//  meta/access/get_types.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_ACCESS_GET_TYPES_H
#define META_ACCESS_GET_TYPES_H

#include <meta/utilities/type_list.h>

namespace meta
{
    //!     Получение списка типов шаблонного класса "Class".
    /*!
            Результатом этой метафункции является список типов ("type_list"), содержащий все типы,
        которыми конкретизирован шаблонный класс "Class".
     */
    template <typename Class>
    struct get_types;
    
    template <template <typename ...> class Class, typename ... Types>
    struct get_types <Class<Types ...>>
    {
        typedef type_list<Types ...> type;
    };
}

#endif // META_ACCESS_GET_TYPES_H
