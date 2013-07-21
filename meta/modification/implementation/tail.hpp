//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_TAIL_HPP
#define META_MODIFICATION_IMPLEMENTATION_TAIL_HPP

#include <meta/types/type_list.hpp>
#include <meta/modification/implementation/split.hpp>
#include <meta/access/at.hpp>

namespace meta
{
    namespace impl
    {        
        template <typename TypeList, int N>
        struct tail;
        
        template <typename ... Types, int N>
        struct tail <type_list<Types ...>, N>
        {
            typedef typename split
            <
                type_list<Types ...>,
                sizeof...(Types) - N
            >
            ::type splitted_lists;
            
            typedef typename at<splitted_lists, 1>::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_TAIL_HPP
