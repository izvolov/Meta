//
//  meta/access/implementation/advance.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_ACCESS_IMPLEMENTATION_ADVANCE_H
#define META_ACCESS_IMPLEMENTATION_ADVANCE_H

#include <meta/access/implementation/raw_iterator.hpp>
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
            struct advance <raw_iterator<HeadList, TailList>, N>
            {
                typedef typename meta::impl::move_left<HeadList, TailList, N>::type moved_types;
                typedef typename instantiate<raw_iterator, moved_types>::type type;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_IMPLEMENTATION_ADVANCE_H
