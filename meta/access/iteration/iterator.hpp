//
//  meta/access/iteration/iterator.hpp
//
//  Дмитрий Изволов.
//  5 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_ITERATOR_HPP
#define META_ACCESS_ITERATION_ITERATOR_HPP

#include <meta/types/pattern_list.hpp>
#include <meta/types/type_list.hpp>

namespace meta
{
    namespace iter
    {
        //!     Итератор шаблонного класса.
        /*!
                Хранит шаблон итерируемого класса в виде списка шаблонов ("pattern_list<...>")
            единичного размера, а также типы, которыми конкретизирован данный шаблон, разделяя их на
            два списка типов ("type_list<...>"). Первый из них содержит уже проитерированные типы, а
            второй — под нулевым индексом содержит текущий тип, а под остальными индексами — все ещё
            непроитерированные типы.
                Время компиляции данного конструктора постоянно, то есть O(1).
         */
        template <typename PackedPattern, typename HeadList, typename TailList>
        struct iterator;
        
        template <template <typename ...> class Pattern, typename ... Head, typename ... Tail>
        struct iterator <pattern_list<Pattern>, type_list<Head ...>, type_list<Tail ...>>
        {
            typedef pattern_list<Pattern> packed_pattern;
            typedef type_list<Head ...> head;
            typedef type_list<Tail ...> tail;
            typedef type_list<Head ..., Tail ...> all_types;
        };
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ITERATION_ITERATOR_HPP
