//
//  meta/modification/implementation/push_front.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_PUSH_FRONT_H
#define META_MODIFICATION_IMPLEMENTATION_PUSH_FRONT_H

#include <meta/types/type_list.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, typename InsertedType>
        struct push_front;
        
        template <typename ... OldTypes, typename InsertedType>
        struct push_front <type_list<OldTypes ...>, InsertedType>
        {
            typedef type_list<InsertedType, OldTypes ...> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_PUSH_FRONT_H