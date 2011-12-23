//
//  meta/modification/subsequence.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_SUBSEQUENCE_H
#define META_MODIFICATION_SUBSEQUENCE_H

#include <meta/modification/implementation/subsequence.h>
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
    struct subsequence
    {
        typedef typename impl::subsequence<typename get_types<Class>::type, Index, Size>::type subtypes;        
        typedef typename reinstantiate<Class, subtypes>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_SUBSEQUENCE_H
