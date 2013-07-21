//
//  Дмитрий Изволов.
//  26 января 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_IMPLEMENTATION_GREATEST_COMMON_DIVISOR_HPP
#define META_TYPES_ARITHMETIC_IMPLEMENTATION_GREATEST_COMMON_DIVISOR_HPP

#include <meta/types/arithmetic/implementation/modulus.hpp>

namespace meta
{
    namespace impl
    {
        template <int Left, int Right>
        struct greatest_common_divisor
        {
            static constexpr int value = greatest_common_divisor<Right, Left % Right>::value;
        };
        
        template <int Left>
        struct greatest_common_divisor <Left, 0>
        {
            static_assert(Left != 0, "Наибольший общий делитель двух чисел определён тогда, и только тогда, когда хотя бы одно из них не равно нулю.");
            
            static constexpr int value = modulus<Left>::value;
        };
    } // namespace impl
} // nemaspace meta

#endif // META_TYPES_ARITHMETIC_IMPLEMENTATION_GREATEST_COMMON_DIVISOR_HPP
