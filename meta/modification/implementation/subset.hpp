//
//  Дмитрий Изволов.
//  21 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_SUBSET_HPP
#define META_MODIFICATION_IMPLEMENTATION_SUBSET_HPP

#include <meta/types/type_list.hpp>
#include <meta/types/value_list.hpp>
#include <meta/modification/implementation/push_front.hpp>
#include <meta/access/at.hpp>

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

#endif // META_MODIFICATION_IMPLEMENTATION_SUBSET_HPP
