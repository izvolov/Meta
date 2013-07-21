//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_ITERATION_DISTANCE_HPP
#define META_INSPECTION_ITERATION_DISTANCE_HPP

#include <meta/inspection/iteration/comparable.hpp>
#include <meta/inspection/size.hpp>

namespace meta
{
    namespace iter
    {
        //!     Нахождение расстояния между двумя итераторами.
        /*!
         */
        template <typename First, typename Second>
        struct distance
        {
            static_assert(comparable<First, Second>::value, "Расстояние между итераторами не может быть вычислено, поскольку они итерируют разные классы.");
            
            static constexpr int value = size<typename Second::head>::value - size<typename First::head>::value;
        };    
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_ITERATION_DISTANCE_HPP
