//
//  meta/transformation/head.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_HEAD_H
#define META_TRANSFORMATION_HEAD_H

#include <meta/transformation/implementation/head.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

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

#endif // META_TRANSFORMATION_HEAD_H