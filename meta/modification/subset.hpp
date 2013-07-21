//
//  meta/modification/subset.hpp
//
//  Дмитрий Изволов.
//  21 декабря 2011 года.
//

#ifndef META_MODIFICATION_SUBSET_HPP
#define META_MODIFICATION_SUBSET_HPP

#include <meta/modification/implementation/subset.hpp>
#include <meta/access/get_types.hpp>
#include <meta/types/value_list.hpp>
#include <meta/creation/reinstantiate.hpp>

namespace meta
{
    //!     Выделение произвольного подмножества типов шаблонного класса.
    /*!
            Результатом этой метафункции является новая конкретизация шаблонного класса "Class", в
        которой присутствует произвольное подмножество типов из того набора типов, которым был
        конкретизирован входной класс. Это подмножество описывается простым перечислением индексов
        тех типов, которые должны быть включены в новую конкретизацию. Индексы могут повторяться и
        следовать в любом порядке.
            Время компиляции данной метафункции пропорционально произведению количества типов в
        конкретизации входного класса и размера формируемой последовательности, т.е. O(S * M).
     */
    template <typename Class, int ... Indexes>
    struct subset
    {
        typedef typename impl::subset<typename get_types<Class>::type, value_list<int, Indexes ...>>::type subtypes;        
        typedef typename reinstantiate<Class, subtypes>::type type;
    };
} // namespace meta

#endif // META_MODIFICATION_SUBSET_HPP
