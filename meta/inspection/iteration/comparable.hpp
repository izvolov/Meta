//
//  meta/inspection/iteration/comparable.hpp
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_ITERATION_COMPARABLE_HPP
#define META_INSPECTION_ITERATION_COMPARABLE_HPP

namespace meta
{
    namespace iter
    {
        //!     Проверка сравнимости двух итераторов.
        /*!
                Итераторы являются сравнимыми, если они итерируют один и тот же шаблон и один и тот
            же список типов этого шаблона.
                Время компиляции постоянно, то есть O(1).
         */
        template <typename First, typename Second>
        struct comparable
        {
            static constexpr bool value = std::is_same
            <
                typename First::packed_pattern,
                typename Second::packed_pattern
            >
            ::value && std::is_same
            <
                typename First::all_types,
                typename Second::all_types
            >
            ::value;  
        };
    } // namespace iter
} // namespace meta

#endif // META_INSPECTION_ITERATION_COMPARABLE_HPP
