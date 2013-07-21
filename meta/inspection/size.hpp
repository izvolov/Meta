//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_INSPECTION_SIZE_HPP
#define META_INSPECTION_SIZE_HPP

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
    
    template
    <
        template <template <typename ...> class ...> class OuterPattern,
        template <typename ...> class ... InnerPatterns
    >
    struct size <OuterPattern<InnerPatterns...>>
    {
        static constexpr int value = sizeof...(InnerPatterns);
    };
    
    template
    <
        typename Integer,
        template <typename Int, Int ...> class Pattern,
        Integer ... Numbers
    >
    struct size <Pattern<Integer, Numbers ...>>
    {
        static constexpr int value = sizeof...(Numbers);
    };
} // namespace meta

#endif // META_INSPECTION_SIZE_HPP
