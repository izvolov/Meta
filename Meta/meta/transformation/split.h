//
//  meta/transformation/split.h
//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_TRANSFORMATION_SPLIT_H
#define META_TRANSFORMATION_SPLIT_H

#include <meta/transformation/implementation/split.h>
#include <meta/utilities/type_list.h>
#include <meta/access/get_types.h>
#include <meta/transformation/repattern.h>
#include <meta/access/at.h>
#include <meta/access/get_pattern.h>

namespace meta
{
    template <typename TypeList, int N>
    struct split
    {
        typedef typename impl::split<TypeList, N>::type splitted_lists;
        
        typedef type_list
        <
            typename repattern
            <
                typename impl::at<splitted_lists, 0>::type,
                get_pattern<Left>::template pattern
            >
            ::type,
            typename repattern
            <
                typename impl::at<splitted_lists, 1>::type,
                get_pattern<Right>::template pattern
            >
            ::type
        >
        type;
    };
} // namespace meta

#endif // META_TRANSFORMATION_SPLIT_H
