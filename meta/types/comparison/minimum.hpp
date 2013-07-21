//
//  Дмитрий Изволов.
//  7 августа 2012 года.
//

#ifndef META_TYPES_COMPARISON_MINIMUM_HPP
#define META_TYPES_COMPARISON_MINIMUM_HPP

#include <meta/types/comparison/implementation/minimum.hpp>

namespace meta
{
    template <typename ... Types>
    struct minimum
    {
        // Добавить проверку на сравнимость.
        
        typedef typename impl::minimum<Types ...>::type type;
    };
} // namespace meta

#endif // META_TYPES_COMPARISON_MINIMUM_HPP
