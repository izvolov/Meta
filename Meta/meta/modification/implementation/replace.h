//
//  meta/modification/implementation/replace.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_REPLACE_H
#define META_MODIFICATION_IMPLEMENTATION_REPLACE_H

#include <meta/types/type_list.h>
#include <meta/modification/implementation/split.h>
#include <meta/modification/implementation/merge.h>
#include <meta/access/at.h>
#include <meta/modification/implementation/push_front.h>
#include <meta/modification/implementation/pop_front.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, int Index, typename NewType>
        struct replace;
        
        template <typename ... OldTypes, int Index, typename NewType>
        struct replace <type_list<OldTypes ...>, Index, NewType>
        {
            typedef typename split<type_list<OldTypes ...>, Index>::type splitted_lists;
            typedef typename merge
            <
                typename at<splitted_lists, 0>::type,
                typename push_front
                <
                    typename pop_front
                    <
                        typename at<splitted_lists, 1>::type
                    >
                    ::type,
                    NewType
                >
                ::type
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_REPLACE_H
