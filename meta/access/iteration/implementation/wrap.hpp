//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_IMPLEMENTATION_WRAP_HPP
#define META_ACCESS_ITERATION_IMPLEMENTATION_WRAP_HPP

#include <meta/access/iteration/implementation/knot.hpp>
#include <meta/access/iteration/iterator.hpp>

namespace meta
{
    namespace iter
    {
        namespace impl
        {       
            template <typename PackedPattern, typename RawIterator>
            struct wrap;
            
            template <typename HeadList, typename TailList, typename PackedPattern>
            struct wrap <knot<HeadList, TailList>, PackedPattern>
            {
                typedef iterator<PackedPattern, HeadList, TailList> type;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ITERATION_IMPLEMENTATION_WRAP_HPP
