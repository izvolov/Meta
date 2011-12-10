//
//  meta/transformation/implementation/head.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_IMPLEMENTATION_HEAD_H
#define META_TRANSFORMATION_IMPLEMENTATION_HEAD_H

#include <meta/utilities/type_list.h>
#include <meta/transformation/implementation/split.h>
#include <meta/access/at.h>

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

#endif // META_TRANSFORMATION_IMPLEMENTATION_HEAD_H
