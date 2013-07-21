//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_COMPARISON_IMPLEMENTATION_DIFFERENT_HPP
#define META_TYPES_COMPARISON_IMPLEMENTATION_DIFFERENT_HPP

#include <meta/types/integer.hpp>
#include <meta/types/rational.hpp>
#include <meta/types/arithmetic/implementation/fix_sign.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Left, typename Right>
        struct different;
        
        template <int Left, int Right>
        struct different <integer<Left>, integer<Right>>
        {
            static constexpr bool value = Left != Right;
        };
        
        template <int Numerator1, int Denominator1, int Numerator2, int Denominator2>
        struct different <rational<Numerator1, Denominator1>, rational<Numerator2, Denominator2>>
        {
            static constexpr bool value = Numerator1 * Denominator2 != Numerator2 * Denominator1;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_COMPARISON_IMPLEMENTATION_DIFFERENT_HPP
