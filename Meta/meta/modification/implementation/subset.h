//
//  meta/modification/implementation/subset.h
//
//  Дмитрий Изволов.
//  21 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_SUBSET_H
#define META_MODIFICATION_IMPLEMENTATION_SUBSET_H

#include <meta/types/type_list.h>
#include <meta/types/value_list.h>
#include <meta/modification/implementation/push_front.h>
#include <meta/access/at.h>

namespace meta
{
    namespace impl
    {        
        template <typename TypeList, typename ValueList>
        struct subset;
        
        template <typename ... Types, int First, int ... Others>
        struct subset <type_list<Types ...>, value_list<int, First, Others ...>>
        {
            typedef typename push_front
            <
                typename subset<type_list<Types ...>, value_list<int, Others ...>>::type,
                typename at<type_list<Types ...>, First>::type
            >
            ::type type;
        };
        
        template <typename ... Types, int Only>
        struct subset <type_list<Types ...>, value_list<int, Only>>
        {
            typedef type_list<typename at<type_list<Types ...>, Only>::type> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_SUBSET_H
