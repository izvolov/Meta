//
//  meta/types/pair.hpp
//
//  Дмитрий Изволов.
//  3 января 2012 года.
//

#ifndef META_TYPES_PAIR_H
#define META_TYPES_PAIR_H

namespace meta
{
    //!     Пара.
    /*!
     */
    template <typename First, typename Second>
    struct pair
    {
        typedef First first;
        typedef Second second;
    };
} // namespace meta

#endif // META_TYPES_PAIR_H