//
//  meta/modification/implementation/pop_front.hpp
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_POP_FRONT_H
#define META_MODIFICATION_IMPLEMENTATION_POP_FRONT_H

#include <meta/types/type_list.hpp>

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

#endif // META_MODIFICATION_IMPLEMENTATION_POP_FRONT_H
