//
//  meta/access/at.hpp
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_ACCESS_AT_H
#define META_ACCESS_AT_H

#include <meta/inspection/size.hpp>
#include <meta/access/implementation/at.hpp>
#include <meta/types/type_list.hpp>
#include <meta/access/get_types.hpp>

namespace meta
{
    //!     Получение типа под номером N.
    /*!
            Результатом этой метафункции является N-й (начиная с нуля) тип, которым конкретизирован
        шаблонный класс "Class".
            Время компиляции данной метафункции пропорционально номеру искомого типа, то есть O(N).
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
