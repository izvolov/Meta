//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_IMPLEMENTATION_MULTIPLY_HPP
#define META_TYPES_ARITHMETIC_IMPLEMENTATION_MULTIPLY_HPP

#include <meta/types/integer.hpp>
#include <meta/types/rational.hpp>
#include <meta/types/arithmetic/implementation/simplify.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Left, typename Right>
        struct multiply;
        
        template <int Left, int Right>
        struct multiply <integer<Left>, integer<Right>>
        {
            typedef integer<Left * Right> type;
        };
        
        template <int Numerator1, int Denominator1, int Numerator2, int Denominator2>
        struct multiply <rational<Numerator1, Denominator1>, rational<Numerator2, Denominator2>>
        {
            typedef typename simplify
            <
                rational<Numerator1 * Numerator2, Denominator1 * Denominator2>
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_ARITHMETIC_IMPLEMENTATION_MULTIPLY_HPP
