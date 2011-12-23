//
//  meta/common/select.h
//
//  Дмитрий Изволов.
//  4 декабря 2011 года.
//

#ifndef META_SELECT_H
#define META_SELECT_H

namespace meta
{
    //!     Метафункция условного выбора.
    /*!
            Аналогична по функциональности тернарному оператору "?:": если значение выражения
        "Expression" истинно, то результатом метафункции будет являться первый тип, следующий за
        условием (то есть тип "First"), если же выражение ложно, то второй (то есть тип "Second").
     */
    template <bool Expression, typename First, typename Second>
    struct select
    {
        typedef First type;
    };
    
    template <typename First, typename Second>
    struct select <false, First, Second>
    {
        typedef Second type;
    };
} // namespace meta

#endif // META_SELECT_H
