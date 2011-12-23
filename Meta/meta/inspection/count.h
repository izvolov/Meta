//
//  meta/inspection/count.h
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_COUNT_H
#define META_INSPECTION_COUNT_H

#include <meta/inspection/distance.h>
#include <meta/inspection/implementation/count.h>
#include <meta/access/implementation/unwrap.h>
#include <meta/access/implementation/wrap.h>

namespace meta
{
    namespace iter
    {
        //!     Подсчёт включений типа в диапазон между итераторами.
        /*!
         */
        template <typename First, typename Second, typename Type>
        struct count
        {
            static_assert(distance<First, Second>::value >= 0, "Неверно задан диапазон итераторов.");
            
            static constexpr int value = impl::count
            <
                typename impl::unwrap<First>::type,
                typename impl::unwrap<Second>::type,
                Type
            >
            ::value;
        };    
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_COUNT_H
