//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_MODIFICATION_SPLIT_HPP
#define META_MODIFICATION_SPLIT_HPP

#include <meta/modification/implementation/split.hpp>
#include <meta/access/get_types.hpp>
#include <meta/types/type_list.hpp>
#include <meta/creation/repattern.hpp>
#include <meta/access/at.hpp>
#include <meta/access/get_pattern.hpp>

namespace meta
{
    //!     Разделение шаблонного класса "Class" на две части.
    /*!
            Результат этой метафункции — список типов ("type_list"), состоящий из двух классов,
        образованных из шаблона класса "Class", первый из которых конкретизирован первыми N
        параметрами шаблона входного класса, а второй — всеми остальными.
            Время компиляции пропорционально параметру разбиения, то есть O(N).
     */
    template <typename Class, int N>
    struct split
    {
        typedef typename impl::split<typename get_types<Class>::type, N>::type splitted_lists;
        
        typedef type_list
        <
            typename repattern
            <
                typename impl::at<splitted_lists, 0>::type,
                get_pattern<Class>::template pattern
            >
            ::type,
            typename repattern
            <
                typename impl::at<splitted_lists, 1>::type,
                get_pattern<Class>::template pattern
            >
            ::type
        >
        type;
    };
} // namespace meta

#endif // META_MODIFICATION_SPLIT_HPP
