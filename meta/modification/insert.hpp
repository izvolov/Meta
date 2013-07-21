//
//  meta/modification/insert.hpp
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_INSERT_HPP
#define META_MODIFICATION_INSERT_HPP

#include <meta/modification/implementation/insert.hpp>
#include <meta/types/type_list.hpp>
#include <meta/access/get_types.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!     Вставка типа в шаблонный класс.
    /*
            Результатом этой метафункции является новая конкретизация шаблона класса "Class", в
        которой в списке типов на место под индексом "Index" (начиная с нуля) встаёт тип "Type",
        сдвигая на единицу вправо все типы, которые ранее находились под индексами
        {"Index", "Index" + 1, ...}.
            Поскольку данная метафункция использует в реализации метафункцию "split", время её
        компиляции пропорционально индексу того места, в которое вставляется новый тип, то есть
        O(Index).
     */
    template <typename Class, int Index, typename Type>
    struct insert
    {
        typedef typename impl::insert<typename get_types<Class>::type, Index, Type>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_INSERT_HPP
