//
//  Дмитрий Изволов.
//  26 января 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_IMPLEMENTATION_MODULUS_HPP
#define META_TYPES_ARITHMETIC_IMPLEMENTATION_MODULUS_HPP

#include <meta/types/integer.hpp>
#include <meta/types/rational.hpp>

namespace meta
{
    namespace impl
    {
        template <int Number>
        struct modulus
        {
            static constexpr int value = Number < 0 ? -Number : Number;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_ARITHMETIC_IMPLEMENTATION_MODULUS_HPP
