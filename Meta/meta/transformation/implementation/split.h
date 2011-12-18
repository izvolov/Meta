//
//  meta/transformation/implementation/split.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_IMPLEMENTATION_SPLIT_H
#define META_TRANSFORMATION_IMPLEMENTATION_SPLIT_H

#include <meta/utilities/type_list.h>
#include <meta/transformation/implementation/move_left.h>

namespace meta
{
    namespace impl
    {
        //!     Разделение списка типов на две части.
        /*!
                Результат этой метафункции — список типов ("type_list"), состоящий из двух других
            списков типов, первый из которых содержит первые N типов из входного списка, а второй — все
            остальные типы.
                Время компиляции пропорционально параметру разбиения, то есть O(N).
         */
        template <typename TypeList, int N>
        struct split;
        
        template <typename ... Types, int N>
        struct split <type_list<Types ...>, N>
        {
            typedef typename move_left<type_list<>, type_list<Types ...>, N>::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TRANSFORMATION_SPLIT_H
