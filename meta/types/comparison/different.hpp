//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_COMPARISON_DIFFERENT_HPP
#define META_TYPES_COMPARISON_DIFFERENT_HPP

#include <meta/types/comparison/implementation/different.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct different
    {
        static constexpr bool value = impl::different<Left, Right>::value;
    };
} // namespace meta

#endif // META_TYPES_COMPARISON_DIFFERENT_HPP
