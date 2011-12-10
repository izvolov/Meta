//
//  meta/access/implementation/at.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_ACCESS_IMPLEMENTATION_AT_H
#define META_ACCESS_IMPLEMENTATION_AT_H

#include <meta/utilities/type_list.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, int Index>
        struct at;
        
        template <typename Head, typename ... Tail, int Index>
        struct at <type_list<Head, Tail ...>, Index>
        {
            typedef typename at<type_list<Tail ...>, Index - 1>::type type;
        };
        
        template <typename Head, typename ... Tail>
        struct at <type_list<Head, Tail ...>, 0>
        {
            typedef Head type;
        };
    } // namespace impl
} // namespace meta

#endif // META_ACCESS_IMPLEMENTATION_AT_H
