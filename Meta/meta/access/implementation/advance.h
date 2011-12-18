//
//  meta/access/implementation/advance.h
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_ACCESS_IMPLEMENTATION_ADVANCE_H
#define META_ACCESS_IMPLEMENTATION_ADVANCE_H

#include <meta/access/implementation/raw_iterator.h>
#include <meta/types/type_list.h>
#include <meta/modification/implementation/move_left.h>
#include <meta/creation/instantiate.h>

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
