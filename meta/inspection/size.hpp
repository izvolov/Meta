//
//  meta/inspection/size.hpp
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_INSPECTION_SIZE_H
#define META_INSPECTION_SIZE_H

namespace meta
{
    //!     Количество параметров шаблонного класса.
    /*!
            Результатом этой метафункции является целое число, равное количеству параметров шаблона
        шаблонного класса "Class".
     */
    template <typename Class>
    struct size;
    
    template <template <typename ...> class Pattern, typename ... Types>
    struct size <Pattern<Types ...>>
    {
        static constexpr int value = sizeof...(Types);
    };
} // namespace meta

#endif // META_INSPECTION_SIZE_H
