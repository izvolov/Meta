//
//  meta/modification/implementation/insert.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_INSERT_H
#define META_MODIFICATION_IMPLEMENTATION_INSERT_H

#include <meta/types/type_list.h>
#include <meta/modification/implementation/split.h>
#include <meta/modification/implementation/merge.h>
#include <meta/modification/implementation/push_back.h>
#include <meta/access/at.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, int Index, typename Type>
        struct insert;
        
        template <typename ... OldTypes, int Index, typename InsertedType>
        struct insert <type_list<OldTypes ...>, Index, InsertedType>
        {
            typedef typename split<type_list<OldTypes ...>, Index>::type splitted_lists;
            typedef typename merge
            <
                typename push_back
                <
                    typename at<splitted_lists, 0>::type,
                    InsertedType
                >
                ::type,
                typename at<splitted_lists, 1>::type
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_INSERT_H
