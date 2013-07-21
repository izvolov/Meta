//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_DIVIDE_HPP
#define META_TYPES_ARITHMETIC_DIVIDE_HPP

#include <meta/types/arithmetic/implementation/divide.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct divide
    {
        typedef typename impl::divide<Left, Right>::type type;
    };
} // namespace meta

#endif // META_TYPES_ARITHMETIC_DIVIDE_HPP
