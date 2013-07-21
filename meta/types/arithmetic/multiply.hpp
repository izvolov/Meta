//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_MULTIPLY_HPP
#define META_TYPES_ARITHMETIC_MULTIPLY_HPP

#include <meta/types/arithmetic/implementation/multiply.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct multiply
    {
        typedef typename impl::multiply<Left, Right>::type type;
    };
} // namespace meta

#endif // META_TYPES_ARITHMETIC_MULTIPLY_HPP
