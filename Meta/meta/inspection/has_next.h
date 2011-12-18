//
//  meta/access/has_next.h
//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_INSPECTION_HAS_NEXT_H
#define META_INSPECTION_HAS_NEXT_H

#include <meta/access/iterator.h>
#include <meta/types/pattern_list.h>
#include <meta/types/type_list.h>

namespace meta
{
    namespace iter
    {
        template <typename Iterator>
        struct has_next;
        
        template <template <typename ...> class Pattern, typename ... Head, typename ... Tail>
        struct has_next <iterator<pattern_list<Pattern>, type_list<Head ...>, type_list<Tail ...>>>
        {
            static constexpr const bool value = true;
        };
        
        template <template <typename ...> class Pattern, typename ... Head>
        struct has_next <iterator<pattern_list<Pattern>, type_list<Head ...>, type_list<>>>
        {
            static constexpr const bool value = false;
        };
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_HAS_NEXT_H
