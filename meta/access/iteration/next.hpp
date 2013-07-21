//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_NEXT_HPP
#define META_ACCESS_ITERATION_NEXT_HPP

#include <meta/inspection/iteration/has_next.hpp>
#include <meta/access/iteration/implementation/advance.hpp>
#include <meta/access/iteration/implementation/unwrap.hpp>
#include <meta/access/iteration/implementation/wrap.hpp>
#include <meta/access/at.hpp>

namespace meta
{
    namespace iter
    {
        //!     Продвижение итератора вперёд на одну позицию.
        /*!
                Результатом данной метафункции является итератор некоторой последовательности
            типов, указывающий на следующий элемент после того, на который указывает входной
            итератор ("Iterator").
                Время компиляции постоянно, то есть O(1).
         */
        template <typename Iterator>
        struct next
        {
            static_assert(has_next<Iterator>::value, "Невозможно продвинуть итератор, поскольку достигнут конец последовательности.");
            
            typedef typename impl::advance<typename impl::unwrap<Iterator>::type, 1>::type next_knot;
            typedef typename impl::wrap<next_knot, typename Iterator::packed_pattern>::type type;
        };    
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ITERATION_NEXT_HPP
