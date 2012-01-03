//
//  meta/inspection/find.h
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_FIND_H
#define META_INSPECTION_FIND_H

#include <meta/inspection/distance.h>
#include <meta/inspection/implementation/find.h>
#include <meta/access/implementation/unwrap.h>
#include <meta/access/implementation/wrap.h>

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

#endif // META_INSPECTION_FIND_H
