//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_SPLIT_HPP
#define META_MODIFICATION_IMPLEMENTATION_SPLIT_HPP

#include <meta/types/type_list.hpp>
#include <meta/modification/implementation/move_left.hpp>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, int N>
        struct split;
        
        template <typename ... Types, int N>
        struct split <type_list<Types ...>, N>
        {
            typedef typename move_left<type_list<>, type_list<Types ...>, N>::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_SPLIT_H
