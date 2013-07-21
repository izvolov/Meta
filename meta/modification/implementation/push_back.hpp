//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_PUSH_BACK_HPP
#define META_MODIFICATION_IMPLEMENTATION_PUSH_BACK_HPP

#include <meta/types/type_list.hpp>

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

#endif // META_MODIFICATION_IMPLEMENTATION_PUSH_BACK_HPP
