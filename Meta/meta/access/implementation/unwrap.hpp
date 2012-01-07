//
//  meta/access/implementation/unwrap.hpp
//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_ACCESS_IMPLEMENTATION_UNWRAP_H
#define META_ACCESS_IMPLEMENTATION_UNWRAP_H

#include <meta/access/iterator.hpp>
#include <meta/access/implementation/raw_iterator.hpp>

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
                typedef raw_iterator<HeadList, TailList> type;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_IMPLEMENTATION_UNWRAP_H
