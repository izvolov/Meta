//
//  meta/inspection/count.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_COUNT_H
#define META_INSPECTION_COUNT_H

#include <meta/inspection/distance.hpp>
#include <meta/inspection/implementation/count.hpp>
#include <meta/access/implementation/unwrap.hpp>
#include <meta/access/implementation/wrap.hpp>

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
