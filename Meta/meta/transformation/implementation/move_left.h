//
//  meta/transformation/implementation/move_left.h
//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_IMPLEMENTATION_MOVE_LEFT_H
#define META_TRANSFORMATION_IMPLEMENTATION_MOVE_LEFT_H

#include <meta/utilities/type_list.h>

namespace meta
{
    namespace impl
    {
        template <typename Left, typename Right, int N>
        struct move_left;
        
        template <typename ... Head, typename Moving, typename ... Tail, int N>
        struct move_left <type_list<Head ...>, type_list<Moving, Tail ...>, N>
        {
            typedef typename move_left
            <
                type_list<Head ..., Moving>,
                type_list<Tail ...>,
                N - 1
            >
            ::type type;
        };
        
        template <typename ... Head, typename Middle, typename ... Tail>
        struct move_left <type_list<Head ...>, type_list<Middle, Tail ...>, 0>
        {
            typedef type_list
            <
                type_list<Head ...>,
                type_list<Middle, Tail ...>
            >
            type;
        };
        
        template <typename ... Head>
        struct move_left <type_list<Head ...>, type_list<>, 0>
        {
            typedef type_list
            <
                type_list<Head ...>,
                type_list<>
            >
            type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TRANSFORMATION_IMPLEMENTATION_MOVE_LEFT_H
