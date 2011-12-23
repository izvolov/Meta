//
//  meta/modification/erase.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_ERASE_H
#define META_MODIFICATION_ERASE_H

#include <meta/modification/implementation/erase.h>
#include <meta/types/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    //!     Удаление типа из шаблонного класса.
    /*!
            Результатом этой метафункции является новая конкретизация шаблона класса "Class", в
        которой в списке типов отсутствует тип, который ранее находился под индексом "Index"
        (начиная с нуля).
            Поскольку данная метафункция использует в реализации метафункцию "split", время её
        компиляции пропорционально индексу удаляемого типа, то есть O(Index).
     */
    template <typename Class, int Index>
    struct erase
    {
        typedef typename impl::erase<typename get_types<Class>::type, Index>::type new_types;
        typedef typename reinstantiate<Class, new_types>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_REMOVE_H
