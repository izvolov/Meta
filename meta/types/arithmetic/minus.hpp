//
//  meta/types/arithmetic/minus.hpp
//
//  Дмитрий Изволов.
//  11 февраля 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_MINUS_HPP
#define META_TYPES_ARITHMETIC_MINUS_HPP

#include <meta/types/arithmetic/implementation/minus.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct minus
    {
        typedef typename impl::minus<Left, Right>::type type;
    };
} // namespace meta

#endif // META_TYPES_ARITHMETIC_MINUS_HPP
