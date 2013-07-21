//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_ACCESS_GET_PATTERN_HPP
#define META_ACCESS_GET_PATTERN_HPP

namespace meta
{
    //!     Получение шаблона класса "Class".
    /*!
            Результатом этой метафункции является шаблон, который в дальнейшем может быть
        конкретизирован любыми новыми типами, доступными данному шаблону.
            Время компиляции постоянно, то есть O(1).
     */
    template <typename Class>
    struct get_pattern;
    
    template <template <typename ...> class Pattern, typename ... Types>
    struct get_pattern <Pattern<Types ...>>
    {
        template <typename ... FutureTypes>
        using pattern = Pattern<FutureTypes ...>;
    };
    
    template <typename Integer, template <typename, Integer ...> class Pattern, Integer ... Numbers>
    struct get_pattern <Pattern<Integer, Numbers ...>>
    {
        template <typename NewInteger, NewInteger ... FutureNumbers>
        using pattern = Pattern<NewInteger, FutureNumbers ...>;
    };
} // namespace meta

#endif // META_ACCESS_GET_PATTERN_HPP
