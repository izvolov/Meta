//
//  meta/types/arithmetic/implementation/fix_sign.hpp
//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_IMPLEMENTATION_FIX_SIGN_HPP
#define META_TYPES_ARITHMETIC_IMPLEMENTATION_FIX_SIGN_HPP

#include <meta/types/rational.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Number>
        struct fix_sign;
        
        template <int Numerator, int Denominator>
        struct fix_sign <rational<Numerator, Denominator>>
        {
            typedef typename std::conditional
            <
                Denominator < 0,
                rational<-Numerator, -Denominator>,
                rational<Numerator, Denominator>
            >
            ::type type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_ARITHMETIC_IMPLEMENTATION_FIX_SIGN_HPP
