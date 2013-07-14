//
//  meta/types/comparison/greater.hpp
//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_COMPARISON_GREATER_HPP
#define META_TYPES_COMPARISON_GREATER_HPP

#include <meta/types/comparison/implementation/greater.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct greater
    {
        static constexpr bool value = impl::greater<Left, Right>::value;
    };
} // namespace meta

#endif // META_TYPES_COMPARISON_GREATER_HPP
