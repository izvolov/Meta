//
//  meta/types/comparison/equal.hpp
//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_COMPARISON_EQUAL_HPP
#define META_TYPES_COMPARISON_EQUAL_HPP

#include <meta/types/comparison/implementation/equal.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct equal
    {
        static constexpr bool value = impl::equal<Left, Right>::value;
    };
} // namespace meta

#endif // META_TYPES_COMPARISON_EQUAL_HPP
