//
//  meta/inspection/distance.h
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_DISTANCE_H
#define META_INSPECTION_DISTANCE_H

#include <meta/inspection/comparable.h>
#include <meta/inspection/size.h>

namespace meta
{
    namespace iter
    {
        //!    Нахождение расстояния между двумя итераторами.
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

#endif // META_INSPECTION_DISTANCE_H
