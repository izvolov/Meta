//
//  meta/access/implementation/wrap.h
//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_ACCESS_IMPLEMENTATION_WRAP_H
#define META_ACCESS_IMPLEMENTATION_WRAP_H

#include <meta/access/implementation/raw_iterator.h>
#include <meta/access/iterator.h>

namespace meta
{
    namespace iter
    {
        namespace impl
        {       
            template <typename PackedPattern, typename RawIterator>
            struct wrap;
            
            template <typename HeadList, typename TailList, typename PackedPattern>
            struct wrap <raw_iterator<HeadList, TailList>, PackedPattern>
            {
                typedef iterator<PackedPattern, HeadList, TailList> type;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_IMPLEMENTATION_WRAP_H
