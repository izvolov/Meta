//
//  Дмитрий Изволов.
//  17 декабря 2011 года.
//

#ifndef META_INSPECTION_ITERATION_HAS_NEXT_HPP
#define META_INSPECTION_ITERATION_HAS_NEXT_HPP

#include <meta/access/iteration/iterator.hpp>
#include <meta/types/pattern_list.hpp>
#include <meta/types/type_list.hpp>

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

#endif // META_INSPECTION_ITERATION_HAS_NEXT_HPP
