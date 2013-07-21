//
//  meta/modification/replace.hpp
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_REPLACE_HPP
#define META_MODIFICATION_REPLACE_HPP

#include <meta/modification/implementation/replace.hpp>
#include <meta/access/get_types.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!     Замена типа в шаблонном классе.
    /*
            Результатом этой метафункции является новая конкретизация шаблона класса "Class", в
        которой тип под индексом "Index" (начиная с нуля) заменён на тип "Type".
            Поскольку данная метафункция использует в реализации метафункцию "split", время её
        компиляции пропорционально индексу заменяемого типа, то есть O(Index).
     */
    template <typename Class, int Index, typename Type>
    struct replace
    {
        typedef typename impl::replace<typename get_types<Class>::type, Index, Type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_REPLACE_HPP
