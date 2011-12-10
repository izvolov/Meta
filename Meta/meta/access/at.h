//
//  meta/access/at.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_ACCESS_AT_H
#define META_ACCESS_AT_H

#include <meta/access/implementation/at.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>

namespace meta
{
    //!     Получение типа под номером N.
    /*!
            Результатом этой метафункции является N-й (начиная с нуля) тип, которым конкретизирован
        шаблонный класс "Class".
     */    
    template <typename Class, int N>
    struct at
    {
        typedef typename impl::at<typename get_types<Class>::type, N>::type type;
    };
} // namespace meta

#endif // META_ACCESS_AT_H
