//
//  meta/modification/implementation/reverse.hpp
//
//  Дмитрий Изволов.
//  11 декабря 2011 года.
//

#ifndef META_MODIFICATION_IMPLEMENTATION_REVERSE_HPP
#define META_MODIFICATION_IMPLEMENTATION_REVERSE_HPP

#include <meta/types/type_list.hpp>
#include <meta/modification/implementation/push_back.hpp>

namespace meta
{
    namespace impl
    {
        template <typename TypeList>
        struct reverse;
        
        template <typename Head, typename ... Tail>
        struct reverse <type_list<Head, Tail ...>>
        {
            typedef typename push_back<typename reverse<type_list<Tail ...>>::type, Head>::type type;
        };
        
        template <typename Only>
        struct reverse <type_list<Only>>
        {
            typedef type_list<Only> type;
        };
    } // namespace impl
} // namespace meta

#endif // META_MODIFICATION_IMPLEMENTATION_REVERSE_HPP
