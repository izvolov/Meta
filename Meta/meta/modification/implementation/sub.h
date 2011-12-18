//
//  meta/modification/implementation/sub.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_SUB_H
#define META_MODIFICATION_IMPLEMENTATION_SUB_H

#include <meta/types/type_list.h>
#include <meta/modification/implementation/head.h>
#include <meta/modification/implementation/tail.h>

namespace meta
{
    namespace impl
    {        
        template <typename TypeList, int Index, int Size>
        struct sub;
        
        template <typename ... Types, int Index, int Size>
        struct sub <type_list<Types ...>, Index, Size>
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

#endif // META_MODIFICATION_IMPLEMENTATION_SUB_H
