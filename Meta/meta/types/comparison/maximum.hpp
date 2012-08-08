//
//  meta/types/comparison/maximum.hpp
//
//  Дмитрий Изволов.
//  7 августа 2012 года.
//

#ifndef META_TYPES_COMPARISON_MAXIMUM_HPP
#define META_TYPES_COMPARISON_MAXIMUM_HPP

#include <meta/types/comparison/implementation/maximum.hpp>

namespace meta
{
    template <typename ... Types>
    struct maximum
    {
        // Добавить проверку на сравнимость.
        
        typedef typename impl::maximum<Types ...>::type type;
    };
} // namespace meta

#endif // META_TYPES_COMPARISON_MAXIMUM_HPP
