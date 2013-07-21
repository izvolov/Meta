//
//  meta/inspection/iteration/find.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_ITERATION_FIND_HPP
#define META_INSPECTION_ITERATION_FIND_HPP

#include <meta/inspection/iteration/distance.hpp>
#include <meta/inspection/iteration/implementation/find.hpp>
#include <meta/access/iteration/implementation/unwrap.hpp>
#include <meta/access/iteration/implementation/wrap.hpp>

namespace meta
{
    namespace iter
    {
        //!     Поиск типа в диапазоне между итераторами.
        /*!
         */
        template <typename First, typename Last, typename Type>
        struct find
        {
            static_assert(distance<First, Last>::value >= 0, "Неверно задан диапазон итераторов.");
            
            typedef typename impl::find
            <
                typename impl::unwrap<First>::type,
                typename impl::unwrap<Last>::type,
                Type
            >
            ::type found_raw_iterator;
            
            typedef typename impl::wrap<found_raw_iterator, typename at<First, 0>::type>::type type;
        };    
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_ITERATION_FIND_HPP
