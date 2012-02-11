//
//  meta/types/arithmetic/plus.hpp
//
//  Дмитрий Изволов.
//  26 января 2012 года.
//

#ifndef META_TYPES_ARITHMETIC_PLUS_HPP
#define META_TYPES_ARITHMETIC_PLUS_HPP

#include <meta/types/arithmetic/implementation/plus.hpp>

namespace meta
{
    template <typename Left, typename Right>
    struct plus
    {
        typedef typename impl::plus<Left, Right>::type type;
    };
} // namespace meta

#endif // META_TYPES_ARITHMETIC_PLUS_HPP
