//
//  meta/access/iteration/implementation/knot.hpp
//
//  Дмитрий Изволов.
//  7 декабря 2011 года.
//

#ifndef META_ACCESS_ITERATION_IMPLEMENTATION_KNOT_HPP
#define META_ACCESS_ITERATION_IMPLEMENTATION_KNOT_HPP

#include <meta/types/type_list.hpp>

namespace meta
{
    namespace iter
    {
        namespace impl
        {
            //!     Узелок.
            /*!
                    Представляет собой основу для итератора: сам он итератором не является,
                поскольку не содержит шаблона итерируемого класса, но зато содержит типы этого
                класса и "завязанный узелок" на том месте, куда будет указывать уже настоящий
                итератор, образованный из данного метакласса.
             */
            template <typename HeadList, typename TailList>
            struct knot;
            
            template <typename ... Head, typename ... Tail>
            struct knot <type_list<Head ...>, type_list<Tail ...>>
            {
                typedef type_list<Head ...> head;
                typedef type_list<Tail ...> tail;
                typedef type_list<Head ..., Tail ...> all_types;
            };
        } // namespace impl
    } // namespace iter
} // namespace meta

#endif // META_ACCESS_ITERATION_IMPLEMENTATION_KNOT_HPP
