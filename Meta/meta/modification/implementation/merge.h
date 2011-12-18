//
//  meta/modification/implementation/merge.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_MERGE_H
#define META_MODIFICATION_IMPLEMENTATION_MERGE_H

#include <meta/types/type_list.h>

namespace meta
{
    namespace impl
    {
        template <typename FirstList, typename SecondList>
        struct merge;
        
        template <typename ... FirstTypes, typename ... SecondTypes>
        struct merge <type_list<FirstTypes ...>, type_list<SecondTypes ...>>
        {
            typedef type_list<FirstTypes ..., SecondTypes ...> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_PARTITION_IMPLEMENTATION_MERGE_H