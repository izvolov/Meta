//
//  meta/transformation/implementation/erase.h
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_IMPLEMENTATION_ERASE_H
#define META_TRANSFORMATION_IMPLEMENTATION_ERASE_H

#include <meta/utilities/type_list.h>
#include <meta/transformation/implementation/split.h>
#include <meta/transformation/implementation/merge.h>
#include <meta/access/at.h>
#include <meta/transformation/implementation/pop_front.h>

namespace meta
{
    namespace impl
    {
        template <typename TypeList, int Index>
        struct erase;
        
        template <typename ... OldTypes, int Index>
        struct erase <type_list<OldTypes ...>, Index>
        {
            typedef typename split<type_list<OldTypes ...>, Index>::type splitted_lists;
            typedef typename merge
            <
                typename at<splitted_lists, 0>::type,
                typename pop_front<typename at<splitted_lists, 1>::type>::type
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TRANSFORMATION_IMPLEMENTATION_ERASE_H
