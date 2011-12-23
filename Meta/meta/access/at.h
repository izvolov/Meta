//
//  meta/access/at.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_ACCESS_AT_H
#define META_ACCESS_AT_H

#include <meta/inspection/size.h>
#include <meta/access/implementation/at.h>
#include <meta/types/type_list.h>
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
        static_assert(N >= 0, "Индекс типа в списке типов должен быть целым неотрицательным числом.");
        static_assert(N < size<Class>::value, "Индекс требуемого элемента лежит вне диапазона допустимых значений.");
        
        typedef typename impl::at<typename get_types<Class>::type, N>::type type;
    };
} // namespace meta

#endif // META_ACCESS_AT_H
