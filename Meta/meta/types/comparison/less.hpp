//
//  meta/types/comparison/less.hpp
//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_COMPARISON_LESS_HPP
#define META_TYPES_COMPARISON_LESS_HPP

#include <meta/types/comparison/implementation/less.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct less
    {
        static constexpr bool value = impl::less<Left, Right>::value;
    };
} // namespace meta

#endif // META_TYPES_COMPARISON_LESS_HPP
