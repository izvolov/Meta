//
//  meta/access/advance.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_ACCESS_ADVANCE_H
#define META_ACCESS_ADVANCE_H

#include <meta/inspection/size.hpp>
#include <meta/access/at.hpp>
#include <meta/access/implementation/advance.hpp>
#include <meta/access/implementation/unwrap.hpp>
#include <meta/access/implementation/wrap.hpp>

namespace meta
{
    namespace iter
    {
        //!     Продвижение итератора вперёд на N позиций.
        /*!
                Результатом данной метафункции является итератор некоторой последовательности
            типов, указывающий на N элементов дальше по сравнению со входным итератором
            ("Iterator").
         */
        template <typename Iterator, int N>
        struct advance
        {
            static_assert(N >= 0, "Второй параметр шаблона должен быть целым неотрицательным числом.");
            static_assert(N <= size<typename at<Iterator, 2>::type>::value, "Попытка продвинуть итератор выводит его из диапазона допустимых значений.");
                        
            typedef typename impl::advance<typename impl::unwrap<Iterator>::type, N>::type next_raw_iterator;
            typedef typename impl::wrap<next_raw_iterator, typename at<Iterator, 0>::type>::type type;
        };    
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ADVANCE_H
