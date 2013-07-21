//
//  meta/access/iteration/advance.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_ADVANCE_HPP
#define META_ACCESS_ITERATION_ADVANCE_HPP

#include <meta/inspection/size.hpp>
#include <meta/access/at.hpp>
#include <meta/access/iteration/implementation/advance.hpp>
#include <meta/access/iteration/implementation/unwrap.hpp>
#include <meta/access/iteration/implementation/wrap.hpp>

namespace meta
{
    namespace iter
    {
        //!     Продвижение итератора вперёд на N позиций.
        /*!
                Результатом данной метафункции является итератор некоторой последовательности
            типов, указывающий на N элементов дальше по сравнению со входным итератором
            ("Iterator").
                Время компиляции пропорционально количеству позиций, на которое продвигается итератор,
            то есть O(N).
         */
        template <typename Iterator, int N>
        struct advance
        {
            static_assert(N >= 0, "Второй параметр шаблона должен быть целым неотрицательным числом.");
            static_assert(N <= size<typename Iterator::tail>::value, "Попытка продвинуть итератор выводит его из диапазона допустимых значений.");
                        
            typedef typename impl::advance<typename impl::unwrap<Iterator>::type, N>::type next_knot;
            typedef typename impl::wrap<next_knot, typename Iterator::packed_pattern>::type type;
        };    
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ITERATION_ADVANCE_HPP
