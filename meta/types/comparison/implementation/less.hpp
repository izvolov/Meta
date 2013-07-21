//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_COMPARISON_IMPLEMENTATION_LESS_HPP
#define META_TYPES_COMPARISON_IMPLEMENTATION_LESS_HPP

#include <meta/types/integer.hpp>
#include <meta/types/rational.hpp>
#include <meta/types/arithmetic/implementation/fix_sign.hpp>

namespace meta
{
    namespace impl
    {
        template <typename Left, typename Right>
        struct less;
        
        template <int Left, int Right>
        struct less <integer<Left>, integer<Right>>
        {
            static constexpr bool value = Left < Right;
        };
        
        template <int Numerator1, int Denominator1, int Numerator2, int Denominator2>
        struct less <rational<Numerator1, Denominator1>, rational<Numerator2, Denominator2>>
        {
            typedef typename fix_sign<rational<Numerator1, Denominator1>>::type rational1;
            typedef typename fix_sign<rational<Numerator2, Denominator2>>::type rational2;
            
            static constexpr bool value = rational1::numerator * rational2::denominator < rational2::numerator * rational1::denominator;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_COMPARISON_IMPLEMENTATION_LESS_HPP
