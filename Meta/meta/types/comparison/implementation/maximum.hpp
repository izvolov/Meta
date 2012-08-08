//
//  meta/types/comparison/implementation/maximum.hpp
//
//  Дмитрий Изволов.
//  7 августа 2012 года.
//

#ifndef META_TYPES_COMPARISON_IMPLEMENTATION_MAXIMUM_HPP
#define META_TYPES_COMPARISON_IMPLEMENTATION_MAXIMUM_HPP

#include <meta/types/comparison/implementation/greater.hpp>

namespace meta
{
    namespace impl
    {
        template <typename First, typename ... Others>
        struct maximum
        {
            typedef typename maximum<Others...>::type others_maximum;
            
            typedef typename std::conditional
            <
                greater<First, others_maximum>::value,
                First,
                others_maximum
            >
            ::type type;
        };
        
        template <typename Only>
        struct maximum <Only>
        {
            typedef Only type;
        };
    } // namespace impl
} // namespace meta

#endif // META_TYPES_COMPARISON_IMPLEMENTATION_MAXIMUM_HPP
