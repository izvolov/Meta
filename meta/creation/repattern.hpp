//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_CREATION_REPATTERN_HPP
#define META_CREATION_REPATTERN_HPP

namespace meta
{
    //!     Замена шаблона.
    /*!
            Результатом этой метафункции является конкретизация шаблона "Pattern" теми же типами,
        которыми конкретизирован класс "Class".
            Время компиляции постоянно, то есть O(1).
     */
    template <class Class, template <typename ...> class Pattern>
    struct repattern;
    
    template <template <typename ...> class OldPattern, typename ... Types, template <typename ...> class NewPattern>
    struct repattern <OldPattern<Types ...>, NewPattern>
    {
        typedef NewPattern<Types ...> type;
    };
} // namespace meta

#endif // META_CREATION_REPATTERN_HPP
