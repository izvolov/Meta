//
//  meta/modification/head.hpp
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_HEAD_HPP
#define META_MODIFICATION_HEAD_HPP

#include <meta/modification/implementation/head.hpp>
#include <meta/types/type_list.hpp>
#include <meta/access/get_types.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!     Выделение первых N типов из шаблонного класса "Class".
    /*!
            Результатом этой метафункции является новая конкретизация шаблонного класса "Class", в
        которой присутствуют только первые N типов из того набора типов, которыми был
        конкретизирован входной класс.
            Поскольку данная метафункция использует в реализации метафункцию "split", время её
        компиляции пропорционально желаемому количеству выделенных типов, то есть O(N).
     */
    template <typename Class, int N>
    struct head
    {
        typedef typename impl::head<typename get_types<Class>::type, N>::type head_list;
        typedef typename reinstantiate<Class, head_list>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_HEAD_HPP
