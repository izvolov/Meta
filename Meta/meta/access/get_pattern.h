//
//  meta/access/get_pattern.h
//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_ACCESS_GET_PATTERN_H
#define META_ACCESS_GET_PATTERN_H

namespace meta
{
    //!     Получение шаблона класса "Class".
    /*!
            Результатом этой метафункции является шаблон, который в дальнейшем может быть
        конкретизирован любыми новыми типами, доступными данному шаблону.
     */
    template <typename Class>
    struct get_pattern;
    
    template <template <typename ...> class Pattern, typename ... Types>
    struct get_pattern <Pattern<Types ...>>
    {
        template <typename ... FutureTypes>
        using pattern = Pattern<FutureTypes ...>;
    };
} // namespace meta

#endif // META_ACCESS_GET_PATTERN_H
