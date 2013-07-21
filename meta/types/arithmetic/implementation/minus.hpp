//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_IMPLEMENTATION_MINUS_HPP
#define META_TYPES_ARITHMETIC_IMPLEMENTATION_MINUS_HPP

#include <meta/types/integer.hpp>
#include <meta/types/rational.hpp>
#include <meta/types/arithmetic/implementation/simplify.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Left, typename Right>
        struct minus;
        
        template <int Left, int Right>
        struct minus <integer<Left>, integer<Right>>
        {
            typedef integer<Left - Right> type;
        };
        
        template <int Numerator1, int Denominator1, int Numerator2, int Denominator2>
        struct minus <rational<Numerator1, Denominator1>, rational<Numerator2, Denominator2>>
        {
            typedef typename simplify
            <
                rational<Numerator1 * Denominator2 - Numerator2 * Denominator1, Denominator1 * Denominator2>
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_ARITHMETIC_IMPLEMENTATION_MINUS_HPP
