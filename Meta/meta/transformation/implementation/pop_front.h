//
//  meta/transformation/implementation/pop_front.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_IMPLEMENTATION_POP_FRONT_H
#define META_TRANSFORMATION_IMPLEMENTATION_POP_FRONT_H

#include <meta/utilities/type_list.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList>
        struct pop_front;
        
        template <typename Head, typename ... Tail>
        struct pop_front <type_list<Head, Tail ...>>
        {
            typedef type_list<Tail ...> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TRANSFORMATION_IMPLEMENTATION_POP_FRONT_H
