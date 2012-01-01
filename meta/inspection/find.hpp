//
//  meta/inspection/find.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_FIND_H
#define META_INSPECTION_FIND_H

#include <meta/inspection/distance.hpp>
#include <meta/inspection/implementation/find.hpp>
#include <meta/access/implementation/unwrap.hpp>
#include <meta/access/implementation/wrap.hpp>

namespace meta
{
    namespace iter
    {
        //!     Поиск типа в диапазоне между итераторами.
        /*!
         */
        template <typename First, typename Second, typename Type>
        struct find
        {
            static_assert(distance<First, Second>::value >= 0, "Неверно задан диапазон итераторов.");
            
            typedef typename impl::find
            <
                typename impl::unwrap<First>::type,
                typename impl::unwrap<Second>::type,
                Type
            >
            ::type found_raw_iterator;
            
            typedef typename impl::wrap<found_raw_iterator, typename at<First, 0>::type>::type type;
        };    
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_FIND_H
