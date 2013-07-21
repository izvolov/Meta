//
//  meta/modification/implementation/head.hpp
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_HEAD_HPP
#define META_MODIFICATION_IMPLEMENTATION_HEAD_HPP

#include <meta/types/type_list.hpp>
#include <meta/modification/implementation/split.hpp>
#include <meta/access/at.hpp>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, int N>
        struct head;
        
        template <typename ... Types, int N>
        struct head <type_list<Types ...>, N>
        {
            typedef typename split
            <
                type_list<Types ...>,
                N
            >
            ::type splitted_lists;
            
            typedef typename at<splitted_lists, 0>::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_HEAD_HPP
