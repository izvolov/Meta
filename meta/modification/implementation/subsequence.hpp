//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_SUBSEQUENCE_HPP
#define META_MODIFICATION_IMPLEMENTATION_SUBSEQUENCE_HPP

#include <meta/types/type_list.hpp>
#include <meta/modification/implementation/head.hpp>
#include <meta/modification/implementation/tail.hpp>

namespace meta
{
    namespace impl
    {        
        template <typename TypeList, int Index, int Size>
        struct subsequence;
        
        template <typename ... Types, int Index, int Size>
        struct subsequence <type_list<Types ...>, Index, Size>
        {            
            typedef typename head
            <
                typename tail
                <
                    type_list<Types ...>,
                    sizeof...(Types) - Index
                >
                ::type,
                Size
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_SUBSEQUENCE_HPP
