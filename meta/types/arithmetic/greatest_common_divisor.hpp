//
//  meta/types/arithmetic/greatest_common_divisor.hpp
//
//  Дмитрий Изволов.
//  26 января 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_GREATEST_COMMON_DIVISOR_HPP
#define META_TYPES_ARITHMETIC_GREATEST_COMMON_DIVISOR_HPP

#include <meta/types/arithmetic/implementation/greatest_common_divisor.hpp>

namespace meta
{
    template <typename One, typename Another>
    struct greatest_common_divisor
    {
        typedef integer
        <
            impl::greatest_common_divisor<One::value, Another::value>::value
        >
        type;
    };
} // namespace meta

#endif // META_TYPES_ARITHMETIC_GREATEST_COMMON_DIVISOR_HPP
