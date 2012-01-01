//
//  meta/modification/tail.hpp
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_TAIL_H
#define META_MODIFICATION_TAIL_H

#include <meta/modification/implementation/tail.hpp>
#include <meta/access/get_types.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!     Выделение последних N типов из шаблонного класса "Class".
    /*!
            Результатом этой метафункции является новая конкретизация шаблонного класса "Class", в
        которой присутствуют только последние N типов из того набора типов, которым был
        конкретизирован входной класс.
            Поскольку данная метафункция использует в реализации метафункцию "split", время её
        компиляции пропорционально количеству типов в конкретизации входного класса за вычетом
        параметра разбиения, то есть O(S - N), где S — число параметров шаблона входного класса.
     */
    template <typename Class, int N>
    struct tail
    {
        typedef typename impl::tail<typename get_types<Class>::type, N>::type tail_list;
        typedef typename reinstantiate<Class, tail_list>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_TAIL_H
