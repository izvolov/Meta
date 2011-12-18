//
//  meta/access/next.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_ACCESS_NEXT_H
#define META_ACCESS_NEXT_H

#include <meta/inspection/has_next.h>
#include <meta/access/implementation/advance.h>
#include <meta/access/implementation/unwrap.h>
#include <meta/access/implementation/wrap.h>
#include <meta/access/at.h>

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
