//
//  meta/access/iteration/implementation/unwrap.hpp
//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_IMPLEMENTATION_UNWRAP_HPP
#define META_ACCESS_ITERATION_IMPLEMENTATION_UNWRAP_HPP

#include <meta/access/iteration/iterator.hpp>
#include <meta/access/iteration/implementation/knot.hpp>

namespace meta
{
    namespace iter
    {
        namespace impl
        {       
            template <typename Iterator>
            struct unwrap;
            
            template <typename PackedPattern, typename HeadList, typename TailList>
            struct unwrap <iterator<PackedPattern, HeadList, TailList>>
            {
                typedef knot<HeadList, TailList> type;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ITERATION_IMPLEMENTATION_UNWRAP_HPP
