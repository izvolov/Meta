//
//  meta/access/next.hpp
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_ACCESS_NEXT_H
#define META_ACCESS_NEXT_H

#include <meta/inspection/has_next.hpp>
#include <meta/access/implementation/advance.hpp>
#include <meta/access/implementation/unwrap.hpp>
#include <meta/access/implementation/wrap.hpp>
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
         */
        template <typename Iterator>
        struct next
        {
            static_assert(has_next<Iterator>::value, "Невозможно продвинуть итератор, поскольку достигнут конец последовательности.");
            
            typedef typename impl::advance<typename impl::unwrap<Iterator>::type, 1>::type next_raw_iterator;
            typedef typename impl::wrap<next_raw_iterator, typename at<Iterator, 0>::type>::type type;
        };    
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_NEXT_H
