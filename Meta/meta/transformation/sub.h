//
//  meta/transformation/sub.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_SUB_H
#define META_TRANSFORMATION_SUB_H

#include <meta/transformation/implementation/sub.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/creation/reinstantiate.h>

namespace meta
{
    //!     Выделение "Size" типов, начиная с индекса "Index" из шаблонного класса "Class".
    /*!
            Результатом этой метафункции является новая конкретизация шаблонного класса "Class", в
        которой присутствуют только "Size" типов из того набора, которым конкретизирован входной
        класс, идущие подряд от индекса "Index" (отсчёт начинается с нуля).
     */
    template <typename Class, int Index, int Size>
    struct sub
    {
        typedef typename impl::sub<typename get_types<Class>::type, Index, Size>::type sub_types;        
        typedef typename reinstantiate<Class, sub_types>::type type;
    };
} // namespace meta

#endif // META_TRANSFORMATION_SUB_H
