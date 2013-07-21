//
//  Дмитрий Изволов.
//  7 августа 2012 года.
//

#ifndef META_TYPES_COMPARISON_IMPLEMENTATION_MINIMUM_HPP
#define META_TYPES_COMPARISON_IMPLEMENTATION_MINIMUM_HPP

#include <meta/types/comparison/implementation/less.hpp>

namespace meta
{
    namespace impl
    {
        template <typename First, typename ... Others>
        struct minimum
        {
            typedef typename minimum<Others...>::type others_minimum;
            
            typedef typename std::conditional
            <
                less<First, others_minimum>::value,
                First,
                others_minimum
            >
            ::type type;
        };
        
        template <typename Only>
        struct minimum <Only>
        {
            typedef Only type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_COMPARISON_IMPLEMENTATION_MINIMUM_HPP
