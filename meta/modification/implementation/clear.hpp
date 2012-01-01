//
//  meta/modification/implementation/clear.hpp
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_CLEAR_H
#define META_MODIFICATION_IMPLEMENTATION_CLEAR_H

#include <meta/types/type_list.hpp>

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

#endif // META_MODIFICATION_IMPLEMENTATION_CLEAR_H
