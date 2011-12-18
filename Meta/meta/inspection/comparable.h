//
//  meta/inspection/comparable.h
//
//  Дмитрий Изволов.
//  18 декабря 2011 года.
//

#ifndef META_INSPECTION_COMPARABLE_H
#define META_INSPECTION_COMPARABLE_H

namespace meta
{
    namespace iter
    {
        //!    Проверка сравнимости двух итераторов.
        /*!
                Итераторы являются сравнимыми, если они итерируют один и тот же шаблон и один и тот
            же список типов этого шаблона.
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

#endif // META_INSPECTION_COMPARABLE_H