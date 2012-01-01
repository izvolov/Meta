//
//  meta/access/implementation/raw_iterator.hpp
//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_ACCESS_IMPLEMENTATION_RAW_ITERATOR_H
#define META_ACCESS_IMPLEMENTATION_RAW_ITERATOR_H

#include <meta/types/type_list.hpp>

namespace meta
{
    namespace iter
    {
        namespace impl
        {
            template <typename HeadList, typename TailList>
            struct raw_iterator;
            
            template <typename ... Head, typename ... Tail>
            struct raw_iterator <type_list<Head ...>, type_list<Tail ...>>
            {
                typedef type_list<Head ...> head;
                typedef type_list<Tail ...> tail;
                typedef type_list<Head ..., Tail ...> all_types;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_IMPLEMENTATION_RAW_ITERATOR_H
