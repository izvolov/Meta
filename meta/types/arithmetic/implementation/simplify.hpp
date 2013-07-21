//
//  Дмитрий Изволов.
//  26 января 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_IMPLEMENTATION_SIMPLIFY_HPP
#define META_TYPES_ARITHMETIC_IMPLEMENTATION_SIMPLIFY_HPP

#include <meta/types/arithmetic/greatest_common_divisor.hpp>
#include <meta/types/rational.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Fraction>
        struct simplify;
        
        template <int Numerator, int Denominator>
        struct simplify <rational<Numerator, Denominator>>
        {
            static constexpr int gcd = greatest_common_divisor<Numerator, Denominator>::value;
            
            typedef rational<Numerator / gcd, Denominator / gcd> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_ARITHMETIC_IMPLEMENTATION_SIMPLIFY_HPP
