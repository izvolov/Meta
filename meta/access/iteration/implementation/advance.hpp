//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_IMPLEMENTATION_ADVANCE_HPP
#define META_ACCESS_ITERATION_IMPLEMENTATION_ADVANCE_HPP

#include <meta/access/iteration/implementation/knot.hpp>
#include <meta/types/type_list.hpp>
#include <meta/modification/implementation/move_left.hpp>
#include <meta/creation/instantiate.hpp>

namespace meta
{
    namespace iter
    {
        namespace impl
        {       
            template <typename RawIterator, int N>
            struct advance;
            
            template <typename HeadList, typename TailList, int N>
            struct advance <knot<HeadList, TailList>, N>
            {
                typedef typename meta::impl::move_left<HeadList, TailList, N>::type moved_types;
                typedef typename instantiate<knot, moved_types>::type type;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ITERATION_IMPLEMENTATION_ADVANCE_HPP
