//
//  meta/transformation/implementation/clear.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_IMPLEMENTATION_CLEAR_H
#define META_TRANSFORMATION_IMPLEMENTATION_CLEAR_H

#include <meta/utilities/type_list.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList>
        struct clear;
        
        template <typename ... OldTypes>
        struct clear <type_list<OldTypes ...>>
        {
            typedef type_list<> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TRANSFORMATION_IMPLEMENTATION_CLEAR_H
