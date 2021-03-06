//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_COMPARISON_LESS_HPP
#define META_TYPES_COMPARISON_LESS_HPP

//#include <meta/types/pattern_list.hpp>
//#include <meta/access/get_pattern.hpp>
#include <meta/types/comparison/implementation/less.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct less
    {
//        pattern_list<get_pattern<Left>::template pattern> g;
//        typedef pattern_list<get_pattern<Left>::pattern> first_pattern;
//        Доделать проверку на сравнимость типов "Left" и "Right"
        
        static constexpr bool value = impl::less<Left, Right>::value;
    };
} // namespace meta

#endif // META_TYPES_COMPARISON_LESS_HPP
