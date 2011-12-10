//
//  meta/transformation/implementation/push_back.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_IMPLEMENTATION_PUSH_BACK_H
#define META_TRANSFORMATION_IMPLEMENTATION_PUSH_BACK_H

#include <meta/utilities/type_list.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, typename InsertedType>
        struct push_back;
        
        template <typename ... OldTypes, typename InsertedType>
        struct push_back <type_list<OldTypes ...>, InsertedType>
        {
            typedef type_list<OldTypes ..., InsertedType> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TRANSFORMATION_IMPLEMENTATION_PUSH_BACK_H
