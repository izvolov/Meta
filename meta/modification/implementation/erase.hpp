//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_ERASE_HPP
#define META_MODIFICATION_IMPLEMENTATION_ERASE_HPP

#include <meta/types/type_list.hpp>
#include <meta/modification/implementation/split.hpp>
#include <meta/modification/implementation/merge.hpp>
#include <meta/access/at.hpp>
#include <meta/modification/implementation/pop_front.hpp>

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

#endif // META_MODIFICATION_IMPLEMENTATION_ERASE_HPP
