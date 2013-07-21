//
//  Дмитрий Изволов.
//  26 января 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_MODULUS_HPP
#define META_TYPES_ARITHMETIC_MODULUS_HPP

#include <meta/types/arithmetic/implementation/modulus.hpp>

namespace meta
{
    template <typename Number>
    struct modulus
    {
        typedef integer<impl::modulus<Number::value>::value> type;
    };
} // namespace meta

#endif // META_TYPES_ARITHMETIC_MODULUS_HPP
