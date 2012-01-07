//
//  meta/access/implementation/wrap.hpp
//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_ACCESS_IMPLEMENTATION_WRAP_H
#define META_ACCESS_IMPLEMENTATION_WRAP_H

#include <meta/access/implementation/raw_iterator.hpp>
#include <meta/access/iterator.hpp>

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
