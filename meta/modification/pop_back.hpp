//
//  meta/modification/pop_back.hpp
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_POP_BACK_H
#define META_MODIFICATION_POP_BACK_H

#include <meta/modification/head.hpp>
#include <meta/inspection/size.hpp>

namespace meta
{
    //!     Удаление последнего типа из шаблонного класса "Class".
    /*!
            Результатом этой метафункции является новая конкретизация шаблонного класса "Class", в
        которой отсутствует последний тип из того набора типов, которым был конкретизирован входной
        класс.
            Поскольку данная метафункция использует в реализации метафункцию "head", время её
        компиляции пропорционально без единицы количеству типов в конкретизации входного класса, то
        есть O(S - 1), где S — число параметров шаблона входного класса.
     */
    template <typename Class>
    struct pop_back
    {
        typedef typename head<Class, size<Class>::value - 1>::type type;
    };
} // namespace meta

#endif // META_INSERTION_POP_BACK_H
